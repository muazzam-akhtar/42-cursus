#include "../../includes/commands.hpp"

using namespace ft;

mode::mode(std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw,
	std::map<std::string, ft::channels *>	&chans) :
	ft::cinterface(c, p, pw), chan(chans) {}

mode::~mode() {}

void	mode::exec(int i_pfds, const std::vector<std::string> &cmds)
{
	std::string	chan_name;
	std::string	mode;
	std::string	chan_mode;

	if (cmds[1][0] != '#')
		return ;
	// if (cmds.size() < 2)
	// {
	// 	this->reply(M_CLIENT(i_pfds), ERR_NEEDMOREPARAMS, "MODE");
	// 	return ;
	// }
	chan_name = cmds[1];
	if (this->chan.find(chan_name) == this->chan.end())
	{
		this->reply(M_CLIENT(i_pfds), ERR_NOSUCHCHANNEL, chan_name);
		return ;
	}
	if (cmds.size() == 2)
	{
		chan_mode = this->chan[chan_name]->get_mode();
		this->reply(M_CLIENT(i_pfds), RPL_CHANNELMODEIS, chan_name + " " + chan_mode);
		return ;
	}
	if (this->chan[chan_name]->getOp(M_CLIENT(i_pfds).getFd()) == false)
	{
		this->reply(M_CLIENT(i_pfds), ERR_CHANOPRIVSNEEDED, chan_name + " " 
			+ M_CLIENT(i_pfds).getNick() + " :You're not channel operator");
		return ;
	}
	mode = cmds[2];
	ft::client	&client = M_CLIENT( i_pfds );
	if (mode[1] != 'o' && mode[1] != 'i' 
		&& mode[1] != 't' && mode[1] != 'l' 
		&& mode[1] != 'k')
	{
		// this->reply(M_CLIENT(i_pfds), ERR_UNKNOWNMODE, mode + " :is unknown mode to me");
		return ;
	}
	if (mode[0] == '+')
	{
		if (mode.find('o') != mode.npos)
		{
			(void)	client;
			if (cmds.size() > 3)
			{
				int fd;
				std::string nick = cmds[3];
				std::cout << "nick: " << nick << std::endl;
				find_fd(nick, fd);
				this->chan[chan_name]->add_op(nick);
				// M_CLIENT(fd).addBacklog("MODE " + chan_name + " +o " + nick + "\r\n");
				this->chan[chan_name]->sendToAll(":" + this->sender(client) 
					+ " MODE " + chan_name + " +o " + nick + "\r\n", this->clients, -1);
				this->reply(M_CLIENT(fd), RPL_UMODEIS, chan_name + " :You're now channel operator");
			}
			else
			{
				M_CLIENT(i_pfds).addBacklog(":" + this->sender(client) 
					+ "MODE " 
					+ chan_name + " +o " 
					+ M_CLIENT(i_pfds).getNick() + "\r\n");
				this->reply(M_CLIENT(i_pfds), RPL_UMODEIS, chan_name + " :You're now channel operator");
			}
		}
		if (mode.find('i') != mode.npos)
		{
			// M_CLIENT(i_pfds).addBacklog("MODE " + chan_name + " +i\r\n");
			this->chan[chan_name]->sendToAll(":" + this->sender(client) 
					+ " MODE " + chan_name + " +i\r\n", this->clients, -1);
		}
		if (mode.find('t') != mode.npos)
		{
			// M_CLIENT(i_pfds).addBacklog("MODE " + chan_name + " +t\r\n");
			this->chan[chan_name]->sendToAll(":" + this->sender(client) 
					+ " MODE " + chan_name + " +t\r\n", this->clients, -1);
		}
		if (cmds.size() > 3)
		{
			if (mode.find('l') != mode.npos)
			{
				// M_CLIENT(i_pfds).addBacklog("MODE " 
				// 	+ chan_name + " +l " + mode.substr(mode.find('l') + 1, mode.length()) + "\r\n");
				this->chan[chan_name]->sendToAll(":" + this->sender(client) 
					+ " MODE " + chan_name + " +l " + mode.substr(mode.find('l') 
					+ 1, mode.length()) + "\r\n", this->clients, -1);
			}
			if (mode.find('k') != mode.npos)
			{
				// M_CLIENT(i_pfds).addBacklog("MODE " + chan_name + " +k " + cmds[3] + "\r\n");
				this->chan[chan_name]->sendToAll(":" + this->sender(client) 
					+ " MODE " + chan_name + " +k " + cmds[3] + "\r\n", this->clients, -1);
			}
			this->chan[chan_name]->set_mode(mode + cmds[3]);
			return ;
		}
		this->chan[chan_name]->set_mode(mode);
	}
	else if (mode[0] == '-')
	{
		if (mode.find('o') != mode.npos)
		{
			if (cmds.size() > 3)
			{
				// M_CLIENT(i_pfds).addBacklog("MODE " + chan_name + " -o " + cmds[3] + "\r\n");
				this->chan[chan_name]->sendToAll(":" + this->sender(client) 
					+ " MODE " + chan_name + " -o " + cmds[3] + "\r\n", this->clients, -1);
			}
			else
			{
				M_CLIENT(i_pfds).addBacklog("MODE " + chan_name + " -o " + M_CLIENT(i_pfds).getNick() + "\r\n");
				this->chan[chan_name]->sendToAll(":" + this->sender(client) 
					+ " MODE " + chan_name + " -o\r\n", this->clients, -1);
			}

		}
		if (mode.find('i') != mode.npos || mode.find('t') != mode.npos 
			|| mode.find('l') != mode.npos || mode.find('k') != mode.npos)
		{
			// M_CLIENT(i_pfds).addBacklog("MODE " + chan_name + " " + mode + "\r\n");
			this->chan[chan_name]->sendToAll(":" + this->sender(client) 
					+ " MODE " + chan_name + " " + mode + "\r\n", this->clients, -1);
			this->chan[chan_name]->set_mode(mode);
		}
	}
	// this->chan[chan_name]->sendToAll(":" + M_CLIENT(i_pfds).getHostname() 
	// 	+ " " + RPL_CHANNELMODEIS + " " + M_CLIENT(i_pfds).getNick() + " "
	// 	+ chan_name + " " + this->chan[chan_name]->get_mode() + "\r\n", this->clients, i_pfds);
}	