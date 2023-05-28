/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:07:24 by wismith           #+#    #+#             */
/*   Updated: 2023/05/12 15:22:47 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/channels.hpp"
#include <iostream>

using namespace ft;

channels::channels(std::map<CLIENT_FD, CLIENT> &client) : _len(0), clients(client)
{
	this->_pass = "";
	this->_limit = -1;
	this->_is_topic = false;
	this->_invite_only = false;
}

channels::channels(const channels &other) : clients(other.clients)
{
	this->fds = other.fds;
	this->_chan = other._chan;
	this->_pass = other._pass;
	this->_len = other._len;
}

channels	&channels::operator=(const channels &other)
{
	if (this != &other)
	{
		this->fds = other.fds;
		this->_chan = other._chan;
		this->_pass = other._pass;
		this->_len = other._len;
		this->clients = other.clients;
	}
	return (*this);
}

channels::~channels() {}

void						channels::op( int fd )
{
	this->opps[fd] = true;
}

void	channels::setChannelName(const std::string &name)
{
	this->_chan = name.substr(1, name.length());
}

void	channels::setChannelPass(const std::string &pass)
{
	this->_pass = pass;
}

std::string	channels::get_pass() { return (this->_pass); }

std::string	channels::getChannelName() { return (this->_chan); }

void	channels::add_clients(int fd)
{
	std::cout << "Length: " << this->_len << std::endl;
	for (std::vector<int>::iterator it = this->fds.begin(); it  != this->fds.end(); it++)
	{
		if (*it == fd)
		{
			std::cout << "Already a Member" << std::endl;
			return ;
		}
	}
	this->fds.push_back(fd);
	this->_len++;
}

void	channels::kick_client(std::string &nickname, std::string &msg)
{
	std::vector<int>::iterator	it;

	for (it = this->fds.begin(); it != this->fds.end(); it++)
	{
		if (this->clients[*it].getNick() == nickname)
		{
			this->_len--;
			this->clients[*it].addBacklog(msg);
			sendToAll(msg, clients, *it);
			break;
		}
	}
	this->fds.erase(it);

}

bool	&channels::getOp(int fd)
{
	return (this->opps[fd]);
}

int	channels::get_length() { return (this->_len); }

std::vector<int>	&channels::getFds() { return (this->fds); }

void	channels::sendToAll(const std::string &msg, std::map<int, CLIENT> &clients, int fd)
{
	for (std::vector<int>::iterator it = this->fds.begin(); it != this->fds.end(); it++)
	{
		if (*it != fd)
			clients[*it].addBacklog(msg);
	}
}

void	channels::set_mode(const std::string &mode)
{
	if (mode[0] == '+')
	{
		for (size_t i = 1; i < mode.length(); i++)
		{
			if (mode[i] == 'k')
				this->setChannelPass(mode.substr(i + 1, mode.length()));
			if (mode[i] == 'l')
				this->_limit = string_to_int(mode.substr(i + 1, mode.length()));
		}
		if (mode[1] == 't')
			this->_is_topic = true;
		if (mode[1] == 'i')
			this->_invite_only = true;
	}
	else if (mode[0] == '-')
	{
		for (size_t i = 1; i < mode.length(); i++)
		{
			if (mode[i] == 'k')
				this->setChannelPass("");
			if (mode[i] == 'l')
				this->_limit = -1;
			if (mode[i] == 't')
				this->_is_topic = false;
			if (mode[i] == 'i')
				this->_invite_only = false;
		}
	}
}

std::string	channels::get_mode() 
{
	std::string	mode;

	mode = "+";
	if (this->_is_topic)
		mode += "t";
	if (this->_invite_only)
		mode += "i";
	if (this->_limit != -1)
	{
		std::string	ret;
		ret << (this->_limit);
		mode += "l" + ret;
	}
	if (!this->_pass.empty())
		mode += "k" + this->_pass;
	return (mode);
}

void	channels::set_topic(const std::string &topic) { this->_topic = topic; }

std::string	channels::get_topic() { return (this->_topic); }

std::string	channels::get_users()
{
	std::string	users;

	for (size_t i = 0; i < this->fds.size(); i++)
	{
		if (this->getOp(fds[i]))
			users += "@" + this->clients[fds[i]].getNick() + " ";
		else
			users += this->clients[fds[i]].getNick() + " ";
	}
	return (users);
}

bool	channels::is_user(const std::string &nick)
{
	for (std::vector<int>::iterator it = this->fds.begin(); it != this->fds.end(); it++)
	{
		if (this->clients[*it].getNick() == nick)
			return (true);
	}
	return (false);
}


void	channels::add_op(const std::string &nick)
{
	for (std::vector<int>::iterator it = this->fds.begin(); it != this->fds.end(); it++)
	{
		if (this->clients[*it].getNick() == nick)
		{
			this->opps[*it] = true;
			break;
		}
	}
}

void	channels::remove_op(const std::string &nick)
{
	for (std::vector<int>::iterator it = this->fds.begin(); it != this->fds.end(); it++)
	{
		if (this->clients[*it].getNick() == nick)
		{
			this->opps[*it] = false;
			break;
		}
	}
}

int	channels::string_to_int(const std::string &str)
{
	std::stringstream	ss(str);
	int					res;

	ss >> res;
	return (res);
}

void	channels::set_invite_only(bool invite_only)
{
	this->_invite_only = invite_only;
}

bool	channels::get_invite_only() { return (this->_invite_only); }

void	channels::set_limit(int limit) { this->_limit = limit; }

int		channels::get_limit() { return (this->_limit); }

void	channels::set_is_topic(bool is_topic) { this->_is_topic = is_topic; }

bool	channels::get_is_topic() { return (this->_is_topic); }

void	channels::add_invited_user(const std::string &nick)
{
	this->_invited_users.push_back(nick);
}

bool	channels::is_invited(const std::string &nick)
{
	for (std::vector<std::string>::iterator it = this->_invited_users.begin(); it != this->_invited_users.end(); it++)
	{
		if (*it == nick)
			return (true);
	}
	return (false);
}


void	channels::print_clients()
{
	for (std::vector<int>::iterator it = this->fds.begin(); it != this->fds.end(); it++)
		std::cout << *it << std::endl;
}