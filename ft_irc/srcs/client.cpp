/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:39:31 by wismith           #+#    #+#             */
/*   Updated: 2023/05/11 18:12:24 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.hpp"

using namespace ft;

//* ------------- Constructors ------------- *//

s_clientFlags::s_clientFlags(): recvCapLs(false), recvNick(false), recvUser(false),
	recvCapEnd(false), welcomeSent(false) {}

s_clientFlags::~s_clientFlags() {}

/** @brief client default constructor */
client::client() : fd(0), status(ILLEGAL), markForDel(false), 
	passCheck(false), data(), registration(), backlog()
{(void)this->markForKick;}

/** @brief client file descriptor constructor
 * @note initializes fd to one passed as parameter,
 * 		sets status as illegal (Default), and instantiates,
 * 		reader with file descriptor.
*/
client::client(int nfd) : fd(nfd), status(ILLEGAL), markForDel(false), 
	passCheck(false), data(), backlog() {}

/** @brief Copy Constructor */
client::client(const client &c) : fd(c.fd), status(c.status), markForDel(c.markForDel),
passCheck(false), data(), backlog(c.backlog) {}
//* ------------- End Constructors ------------- *//

/** @brief client destructor */
client::~client() {}

/** @brief Copy assignment operator overload */
client &client::operator=(const client &c)
{
	if (this != &c)
	{
		this->setFd(c.getFd());
		this->setNick(c.getNick());
		this->setStatus(c.getStatus());
	}
	return (*this);
}

//! ------------- Server Operation Methods ------------- *//
std::string	client::Read()
{
	char	buff[513];
	std::string	res;
	ssize_t bits = recv(this->fd, buff, 512, 0);
	if (!bits || bits > 512)
		return (std::string());

	buff[bits] = '\0';
	std::string	str(buff);
	if (bits > 0)
	{
		if (str.find('\n') == str.npos && str.find('\r') == str.npos)
			this->buffer += str;
		else
		{
			res = this->buffer + str;
			this->buffer.clear();
			return (res);
		}
	}
	return (std::string());
}

void	client::Write(std::string str)
{
	send(this->fd, str.c_str(), str.size(), 0);
}

void	client::addBacklog(const std::string reply)
{
	this->backlog.push_back(reply);
}

size_t	client::getBacklogSize() const
{
	return (this->backlog.size());
}

std::string	client::retrBacklog()
{
	std::string	str(this->backlog.front());

	this->backlog.pop_front();
	return (str);
}

void		client::markClientForDel()
{
	this->markForDel = true;
}
//! ------------- End Server Operation Methods ------------- *//

//? ------------- Setters ------------- *//
void	client::setFd(int nfd)
{
	this->fd = nfd;
}

void	client::setStatus(int stat)
{
	this->status = stat;
}

void	client::setNick(const std::string &Nick)
{
	this->data.nick = Nick;
}

void	client::setRealname(const std::string &Realname)
{
	this->data.realname = Realname;
}

void	client::setHostname(const std::string &Hostname)
{
	this->data.hostname = Hostname;
}

void	client::setMode(const std::string &Mode)
{
	this->mode = Mode;
}

void	client::setPassCheck(bool n)
{
	this->passCheck = n;
}

void	client::setUsername(const std::string &Username)
{
	this->data.username = Username;
}

void	client::setOper(bool n)
{
	this->data.isOper = n;
}

//? ------------- End Setters ------------- *//

//? ------------- Getters ------------- *//
int	client::getFd() const
{
	return (this->fd);
}

int	client::getStatus() const
{
	return (this->status);
}

std::string	client::getNick() const
{
	return (this->data.nick);
}

std::string	client::getRealname() const
{
	return (this->data.realname);
}

std::string	client::getHostname() const
{
	return (this->data.hostname);
}

std::string	client::getUsername() const
{
	return (this->data.username);
}

std::string	client::getMode() const
{
	return (this->mode);
}

bool		client::getIsMarkForDel() const
{
	return (this->markForDel);
}

bool		client::getPassCheck() const
{
	return (this->passCheck);
}

t_clientFlags	&client::getReg()
{
	return (this->registration);
}

bool			client::getOper() const
{
	return (this->data.isOper);
}

bool			client::is_registered()
{
	bool	cap_negotiation = ( 
				( this->registration.recvCapEnd
					&& this->registration.recvCapLs ) ||
				( !this->registration.recvCapEnd
					&& !this->registration.recvCapLs ) );

	return ( cap_negotiation
			&& this->registration.recvNick
			&& this->registration.recvUser );
}

//? ------------- End Getters ------------- *//


//! Non members

void	operator>>(const std::string &str, client &c)
{
	c.Write(str);
}

std::string		&operator<<(std::string &str, client &c)
{
	str = c.Read();
	return (str);
}
