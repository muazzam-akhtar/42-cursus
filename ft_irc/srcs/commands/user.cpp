#include "../../includes/commands.hpp"

using namespace ft;

user::user(std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw) : ft::cinterface(c, p, pw) {}

user::~user() {}

void	user::exec(int i_pfds, const std::vector<std::string> &cmds)
{
	ft::client	&client = M_CLIENT(i_pfds);
	std::string	realname;

	if (client.getStatus() == VERIFIED)
		return (this->reply(client, ERR_ALREADYREGISTRED, ":Client already registered"));
	if (cmds.size() > 4)
	{
		client.setUsername(cmds[2]);
		client.setHostname(cmds[3]);

		realname = this->combineArgs(cmds, 4, cmds.size());
		realname.erase(realname.begin());
		client.setRealname(realname);
		client.getReg().recvUser = true;
		return ;
	}
	this->reply(client, ERR_NEEDMOREPARAMS, ":Not enough parameters");
}