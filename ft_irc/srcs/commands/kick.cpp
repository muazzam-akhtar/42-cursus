#include "../../includes/commands.hpp"

using namespace ft;

kick::kick(std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw,
	std::map<std::string, ft::channels *>	&chans) :
	ft::cinterface(c, p, pw), chan(chans) {}

kick::~kick() {}

void	kick::exec(int i_pfds, const std::vector<std::string> &cmds)
{
	ft::client	&client = M_CLIENT(i_pfds);

	if (cmds.size() >= 3)
	{
		std::map<std::string, ft::channels *>::iterator	it = this->chan.find(cmds[1]);
		if (it != this->chan.end())
		{
			std::vector<int>	&getFd = this->chan[cmds[1]]->getFds();
			std::vector<int>::iterator	lookUpClient = getFd.begin();

			for (lookUpClient = getFd.begin(); lookUpClient != getFd.end(); lookUpClient++)
			{
				if (this->clients[*lookUpClient].getNick() == cmds[2])
					break;
			}
			if (it != this->chan.end() && lookUpClient != getFd.end())
			{
				if (this->chan[cmds[1]]->getOp(client.getFd()) == true)
				{
					std::string	cpy = cmds[2];

					std::string	msg = ":"
										+ this->sender(client)
										+ " KICK "
										+ cmds[1]
										+ " "
										+ cmds[2]
										+ " :"
										+ cmds[2] 
										+ "\r\n";

					this->chan[cmds[1]]->kick_client(cpy, msg);
				}
				else
					client.addBacklog("Not a channel Operator!\r\n");
			}
			else
				client.addBacklog(": "
									+ ERR_NOSUCHNICK
									+ " "
									+ client.getNick()
									+ " "
									+ cmds[2] + " :No such nick\r\n");
		}
		else
			M_CLIENT(i_pfds).addBacklog("Channel doesn't exist\r\n");
	}
}