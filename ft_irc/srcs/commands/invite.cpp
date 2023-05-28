#include "../../includes/commands.hpp"

using namespace ft;

invite::invite(std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw,
	std::map<std::string, ft::channels *>	&chans) :
	ft::cinterface(c, p, pw), chan(chans) {}

invite::~invite() {}

void	invite::exec(int i_pfds, const std::vector<std::string> &cmds)
{
	(void) chan;
	std::string chan_name = cmds[2];
	std::string invitee_nick = cmds[1];
	int invitee_fd;
	find_fd(invitee_nick, invitee_fd);
	std::string inviter_nick = M_CLIENT(i_pfds).getNick();
	ft::client	&client = M_CLIENT(i_pfds);
	bool	userFound = false;
	if (cmds.size() < 3)
    {
        this->reply(M_CLIENT(i_pfds), ERR_NEEDMOREPARAMS, "INVITE");
        return ;
    }
    if (chan_name[0] == '#')
    {
		if (this->chan.find(cmds[2]) == this->chan.end())
		{
			this->reply(client, ERR_NOSUCHCHANNEL, chan_name);
			return ;
		}
		if (this->chan[cmds[2]]->getOp(client.getFd()) == false)
		{
			this->reply(client, ERR_CHANOPRIVSNEEDED, chan_name + " :You're not channel operator");
			return ;
		}
		for (size_t i = 0; i < this->pfds.size(); i++)
		{
			ft::client	&rec = M_CLIENT(i);
			if (rec.getNick() == invitee_nick)
			{
				userFound = true;
				break;
			}
		}
		if (userFound == false)
		{
			this->reply(client, ERR_NOSUCHNICK, invitee_nick);
			return ;
		}
		if (this->chan[cmds[2]]->is_user(inviter_nick) == false)
		{
			this->reply(client, ERR_USERNOTINCHANNEL, inviter_nick + " " + chan_name + " :You aren't on that channel");
			return ;
		}
		if (this->chan[cmds[2]]->is_user(invitee_nick) == true)
		{
			this->reply(client, ERR_USERONCHANNEL, invitee_nick + " " + chan_name + " :is already on channel");
			return ;
		}
		this->chan[cmds[2]]->add_invited_user(invitee_nick);
		this->clients[invitee_fd].addBacklog(":" + inviter_nick + " INVITE " + invitee_nick + " :" + chan_name + "\r\n");
		this->reply(client, RPL_INVITING, invitee_nick + " " + chan_name);
        return ;
    }
	else
	{
		this->reply(M_CLIENT(i_pfds), ERR_NOSUCHCHANNEL, cmds[2]);
		return ;
	}
}