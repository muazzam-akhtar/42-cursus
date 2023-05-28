/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:17:52 by wismith           #+#    #+#             */
/*   Updated: 2023/05/11 17:44:24 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/network.hpp"

using namespace ft;

network::network(std::string pw) : ft::parser(), clients(), pfds(), password(pw)
{
	this->cmds["CAP"] = new ft::cap(this->clients, this->pfds, this->password);		//? 0
	this->cmds["PASS"] = new ft::pass(this->clients, this->pfds, this->password);	//? 1
	this->cmds["NICK"] = new ft::nick(this->clients, this->pfds, this->password);	//? 2
	this->cmds["USER"] = new user(this->clients, this->pfds, this->password);		//? 3
	this->cmds["QUIT"] = new ft::quit(this->clients, this->pfds, this->password, this->chans);	//? 4
	this->cmds["DCC"] = new ft::dcc(this->clients, this->pfds, this->password);

	this->cmds["JOIN"] = new ft::join(this->clients, this->pfds, this->password, this->chans);
	this->cmds["PING"] = new ping(this->clients, this->pfds, this->password);
	this->cmds["PRIVMSG"] = new privmsg(this->clients, this->pfds, this->password, this->chans);
	this->cmds["PART"] = new part(this->clients, this->pfds, this->password, this->chans);
	this->cmds["LIST"] = new list(this->clients, this->pfds, this->password, this->chans);

	this->cmds["MODE"] = new mode(this->clients, this->pfds, this->password, this->chans);
	this->cmds["INVITE"] = new invite(this->clients, this->pfds, this->password, this->chans);
	this->cmds["KICK"] = new ft::kick(this->clients, this->pfds, this->password, this->chans);
	this->cmds["TOPIC"] = new topic(this->clients, this->pfds, this->password, this->chans);
}

network::~network()
{
	std::map<std::string, ft::cinterface *>::iterator	it;
	std::map<std::string, ft::channels *>::iterator		chan_it;

	for (it = this->cmds.begin(); it != this->cmds.end(); it++)
		delete	it->second;
	for (chan_it = this->chans.begin(); chan_it != this->chans.end(); chan_it++)
		delete	chan_it->second;
}

bool	network::firstFour(const std::string &cmd)
{
	return ( cmd == "CAP" ? true :
			 cmd == "PASS" ? true :
			 cmd == "NICK" ? true :
			 cmd == "USER" ? true :
			 cmd == "QUIT" ? true :
			 cmd == "JOIN" ? true :
			 cmd == "DCC" ? true :
			 false );
}

void	network::selCmd(const std::vector<std::string> &v_cmds, int i_pfds)
{
	std::map<std::string, ft::cinterface *>::iterator	it;
	ft::client	&client = M_CLIENT(i_pfds);

	it = this->cmds.find(v_cmds[0]);
	if (client.getPassCheck() == true && client.is_registered())
			client.setStatus(VERIFIED);
	if (it != this->cmds.end())
	{
		if ((client.getStatus() == ILLEGAL && firstFour(v_cmds[0])) ||
			client.getStatus() == VERIFIED)
			it->second->exec(i_pfds, v_cmds);
		else
			std::cout << "Wrong Permissions" << std::endl;
	}
}