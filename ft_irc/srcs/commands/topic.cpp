#include "../../includes/commands.hpp"

using namespace ft;

topic::topic(std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw, std::map<std::string, ft::channels *>	&chans) :
	cinterface(c, p, pw), chan(chans) {}

topic::~topic() {}

void	topic::exec(int i_pfds, const std::vector<std::string> &cmds)
{
	if (cmds.size() < 2)
	{
		this->reply(M_CLIENT(i_pfds), ERR_NEEDMOREPARAMS, "TOPIC");
		return ;
	}
	if (this->chan[cmds[1]]->get_is_topic() && this->chan[cmds[1]]->getOp(M_CLIENT(i_pfds).getFd()) == false)
	{
		this->reply(M_CLIENT(i_pfds), ERR_CHANOPRIVSNEEDED, cmds[1] + " :You're not channel operator");
		return ;
	}
	if (cmds[1][0] == '#')
	{
		if (this->chan.find(cmds[1]) == this->chan.end())
		{
			this->reply(M_CLIENT(i_pfds), ERR_NOSUCHCHANNEL, cmds[1]);
			return ;
		}
		if (cmds.size() == 2) // checking for topic
		{
			if (this->chan[cmds[1]]->get_topic() == "")
				this->reply(M_CLIENT(i_pfds), RPL_NOTOPIC, cmds[1] + " :No topic is set");
			else
				this->reply(M_CLIENT(i_pfds), RPL_TOPIC, cmds[1] + " :" + this->chan[cmds[1]]->get_topic());
		}
		if (cmds.size() == 3) // assigning topic
		{
			if (cmds[2][0] == ':')
				this->chan[cmds[1]]->set_topic(cmds[2].substr(1, cmds[2].length()));
			else
				this->chan[cmds[1]]->set_topic(cmds[2]);
			this->chan[cmds[1]]->sendToAll(":" + this->sender(M_CLIENT(i_pfds)) 
			+ " TOPIC " + cmds[1] + " :" + this->chan[cmds[1]]->get_topic() + "\r\n", this->clients, i_pfds);
		}
	}
	else
	{
		this->reply(M_CLIENT(i_pfds), ERR_NOSUCHCHANNEL, cmds[1]);
		return ;
	}
}