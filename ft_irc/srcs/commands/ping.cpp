#include "../../includes/commands.hpp"

using namespace ft;

ping::ping(std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw) : ft::cinterface(c, p, pw) {}

ping::~ping() {}

void	ping::exec(int i_pfds, const std::vector<std::string> &cmds)
{
	ft::client	&client = M_CLIENT(i_pfds);

	if (cmds.size() == 2)
		client.addBacklog("PONG " + cmds[1] + "\r\n");
	else
		client.addBacklog("461 " + client.getNick() + " PING :Not enough parameters\r\n");
}