#include "../../includes/commands.hpp"

using namespace ft;

privmsg::privmsg(std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw,
	std::map<std::string, ft::channels *>	&chans) :
	ft::cinterface(c, p, pw), chan(chans) {}

privmsg::~privmsg() {}

void	privmsg::send(ft::client &Sender, ft::client &Receiver, std::string &msg)
{
	Receiver.addBacklog(":" + this->sender(Sender) + " PRIVMSG " + Receiver.getNick() + " " + msg + "\r\n");
}

void	privmsg::exec(int i_pfds, const std::vector<std::string> &cmds)
{
	std::string	chan_name;
	std::string	nick;
	std::string	msg;
	ft::client	&client = M_CLIENT(i_pfds);

	if (cmds.size() >= 3)
	{
		if (cmds[1][0] == '#')
		{
			chan_name = cmds[1];
			nick = client.getNick();
			msg = cmds[2];
			for (size_t i = 3; i < cmds.size(); i++)
					msg += " " + cmds[i];
			this->chan[chan_name]->sendToAll(":" + nick + " PRIVMSG " + chan_name + " " + msg + "\r\n", this->clients, client.getFd());
		}
		else
		{
			nick = cmds[1];
			msg = cmds[2];
			for (size_t i = 3; i < cmds.size(); i++)
			{
				if (i != (size_t)i_pfds)
					msg += " " + cmds[i];
			}
			for (size_t i = 0; i < this->pfds.size(); i++)
			{
				ft::client	&rec = M_CLIENT(i);
				if (rec.getNick() == nick)
					return (this->send(client, rec, msg));
			}
			client.addBacklog("401 " + client.getNick() + " " + nick + " :No such nick/channel\r\n");
		}
	}
	else
		reply(client, ERR_NEEDMOREPARAMS, " PRIVMSG :Not enough parameters");
}

