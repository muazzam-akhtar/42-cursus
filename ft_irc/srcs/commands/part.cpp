#include "../../includes/commands.hpp"

using namespace ft;

part::part(std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw,
	std::map<std::string, ft::channels *>	&chans) :
	ft::cinterface(c, p, pw), chan(chans) {}

part::~part() {}

void	part::exec(int i_pfds, const std::vector<std::string> &cmds)
{
	std::string	chan_name;
	std::string	nick;
	int			client_fd = M_CLIENT(i_pfds).getFd();

	if (cmds.size() < 2)
	{
		this->reply(M_CLIENT(i_pfds), ERR_NEEDMOREPARAMS, "PART");
		return ;
	}
	chan_name = cmds[1];
	nick = M_CLIENT(i_pfds).getNick();
	if (chan_name[0] != '#')
	{
		this->reply(M_CLIENT(i_pfds), ERR_NOSUCHCHANNEL, chan_name);
		return ;
	}
	if (this->chan.find(chan_name) == this->chan.end())
	{
		this->reply(M_CLIENT(i_pfds), ERR_NOSUCHCHANNEL, chan_name);
		return ;
	}
	std::string	msg = ":" + this->sender(M_CLIENT(i_pfds)) + " PART " + chan_name + "\r\n";
	this->chan[chan_name]->kick_client(nick, msg);
	this->clients[client_fd].addBacklog("You left " + chan_name + "\r\n");
	if (this->chan[chan_name]->get_users().empty())
	{
		delete this->chan[chan_name];
		this->chan.erase(chan_name);
	}
}