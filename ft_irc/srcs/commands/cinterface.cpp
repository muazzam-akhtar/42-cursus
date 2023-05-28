/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cinterface.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:37:28 by wismith           #+#    #+#             */
/*   Updated: 2023/05/05 21:41:17 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands.hpp"

using namespace ft;

cinterface::cinterface(std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw) :
	clients(c), pfds(p), password(pw) {}

cinterface::~cinterface() {}

void	cinterface::reply(ft::client &c, const std::string &code, const std::string &msg)
{
	c.addBacklog(":" + c.getHostname() + " " + code + " " + c.getNick() + " " + msg + "\r\n");
}

std::string		cinterface::combineArgs(const std::vector<std::string> &args, size_t start, size_t end)
{
	std::string	res;

	while (start < end && start < args.size())
	{
		res += args[start];
		if (start != args.size() - 1)
			res += ' ';
		start++;
	}
	return (res);
}

std::string		cinterface::sender(ft::client &c)
{
	return (
			c.getNick() + "!~"
			+ c.getUsername()
			+ "@" + c.getHostname()
			);
}

void	cinterface::find_fd(std::string &nick, int &fd)
{
	std::map<CLIENT_FD, CLIENT>::iterator	it;

	for (it = this->clients.begin(); it != this->clients.end(); it++)
	{
		if (it->second.getNick() == nick)
		{
			fd = it->first;
			return ;
		}
	}
	fd = -1;
}
