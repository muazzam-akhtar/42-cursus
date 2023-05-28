/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:50:50 by wismith           #+#    #+#             */
/*   Updated: 2023/05/20 13:13:12 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/welcome.hpp"

using namespace ft;

welcome::welcome (std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw)
	: ft::cinterface(c, p, pw) {}

welcome::~welcome () {}

bool	welcome::Welcome(ft::client &c)
{
	time_t		now = time( 0 );
	tm			*gmtm = gmtime( &now );
	std::string time( asctime( gmtm ) );

	this->reply( c, RPL_WELCOME, ":Welcome to the irc server!" );
	this->reply( c, RPL_YOURHOST, ":Your host is ircserv, running version 1.0.0" );
	this->reply( c, RPL_CREATED, ":Server started " + time );
	this->reply( c, RPL_MYINFO, ":ircserv ircserv-1.0.0" );
	this->reply( c, RPL_ISUPPORT, ":are available on this server" );
	this->msgOfTheDay( c );
	if ( !c.getPassCheck() )
		c.addBacklog( ":ircserv NOTICE AUTH :*** Incorrect PASSWORD received...\n\r" );
	return ( true );
}

std::string	welcome::randomMsgOfTheDay()
{
	std::string res;

	switch (random() % 7)
	{
		case 0:
			res = "The only way to do great work is to love what you do. - Steve Jobs";
			break;
		case 1:
			res = "If you can dream it, you can do it. - Walt Disney";
			break;
		case 2:
			res = "The secret of getting ahead is getting started. - Mark Twain";
			break;
		case 3:
			res = "If you can dream it, you can do it. - Walt Disney";
			break;
		case 4:
			res = "Never give up. Today is hard, tomorrow will be worse, but the day after tomorrow will be sunshine. - Jack Ma";
			break;
		case 5:
			res = "Life is hard. It's even harder when you're stupid. - John Wayne";
			break;
		case 6:
			res = "You can't wait until life isn't hard anymore before you decide to be happy. - Nightbird";
			break;
		default:
			res = "Life is like a box of chocolates. - Forrest Gump";
			break;
	}
	return (res);
}

void	welcome::msgOfTheDay(ft::client &c)
{
	this->reply(c, RPL_MOTDSTART, ":- ircserv Message of the Day");

	this->reply(c, RPL_MOTD, ":-                                                  ");
	this->reply(c, RPL_MOTD, ":-                                                  ");
	this->reply(c, RPL_MOTD, ":-                                                  ");
	this->reply(c, RPL_MOTD, ":-        ______________________________________    ");
	this->reply(c, RPL_MOTD, ":-       |\x1B[32m    _                                 \x1B[0m|   ");
	this->reply(c, RPL_MOTD, ":-       |\x1B[32m   (_)                                \x1B[0m|   ");
	this->reply(c, RPL_MOTD, ":-       |\x1B[32m    _ _ __ ___ ___  ___ _ ____   __   \x1B[0m|   ");
	this->reply(c, RPL_MOTD, ":-       |\x1B[32m   | | '__/ __/ __|/ _ \\ '__\\ \\ / /   \x1B[0m| ");
	this->reply(c, RPL_MOTD, ":-       |\x1B[32m   | | | | (__\\__ \\  __/ |   \\ V /    \x1B[0m| ");
	this->reply(c, RPL_MOTD, ":-       |\x1B[32m   |_|_|  \\___|___/\\___|_|    \\_/     \x1B[0m| ");
	this->reply(c, RPL_MOTD, ":-       |            version : \x1B[31m1.0.0           \x1B[0m|   ");
	this->reply(c, RPL_MOTD, ":-        --------------------------------------    ");
	this->reply(c, RPL_MOTD, ":-                      Creators :                   ");
	this->reply(c, RPL_MOTD, ":-                                                  ");
	this->reply(c, RPL_MOTD, ":-      Muazzam Akhtar, Imran Mustafa, Willem Smith ");
	this->reply(c, RPL_MOTD, ":-                                                  ");
	this->reply(c, RPL_MOTD, ":-      ------------------------------------------- ");
	this->reply(c, RPL_MOTD, ":-       \"\x1B[35mWelcome to our IRC server! Ircserv was\x1B[0m   ");
	this->reply(c, RPL_MOTD, ":-     \x1B[35mcreated as required by the 42 ft_irc project.\x1B[0m");
	this->reply(c, RPL_MOTD, ":-      \x1B[35mWe are delighted to introduce to you our\x1B[0m    ");
	this->reply(c, RPL_MOTD, ":-                        \x1B[35mversion.\x1B[0m\"                ");
	this->reply(c, RPL_MOTD, ":-      ------------------------------------------- ");
	this->reply(c, RPL_MOTD, ":-                                                  ");
	this->reply(c, RPL_MOTD, ":-  " + this->randomMsgOfTheDay());
	this->reply(c, RPL_MOTD, ":-                                                  ");
	this->reply(c, RPL_MOTD, ":-                                                  ");
	this->reply(c, RPL_MOTD, ":-                                                  ");
	this->reply(c, RPL_MOTD, ":-                                                  ");

	this->reply(c, RPL_ENDOFMOTD, ":End of /MOTD command.");
}

void welcome::exec(int i_pfds, const std::vector<std::string> &cmds)
{
	(void) cmds;
	(void) i_pfds;
}
