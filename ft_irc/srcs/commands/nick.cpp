/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:38:01 by wismith           #+#    #+#             */
/*   Updated: 2023/05/11 17:34:38 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands.hpp"

using namespace ft;

nick::nick(std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw) :
	ft::cinterface(c, p, pw) {}

nick::~nick() {}

std::string	get_max_str(std::vector<std::string> &str)
{
	std::string	max;

	max = str[0];
	for (std::size_t i = 0; i < str.size(); i++)
	{
		if (max < str[i])
			max = str[i];
	}
	return (max);
}

std::string	ft_itoa(int num)
{
	std::string	ret;

	ret = ret << num;
	return (ret);
}

std::vector<std::string>	nick::get_original_nickname(std::string &nick, int &i_pfds)
{
	std::vector<std::string> tmp;
	for (size_t i = 1; i < this->pfds.size(); i++)
	{
		if (i != (size_t)i_pfds && M_CLIENT(i).getNick() == nick)
			tmp.push_back(M_CLIENT(i).getNick());
	}
	return (tmp);
}

void nick::creating_nick( std::string &nick, int &i_pfds )
{
	std::vector<std::string>	tmp;
	ft::client					&client = M_CLIENT( i_pfds );
	
	tmp = get_original_nickname( nick, i_pfds );
	std::string str = nick + "_";

	for ( size_t i = 1; i < this->pfds.size(); i++ )
	{
		ft::client	&checkClient = M_CLIENT( i );
		if ( checkClient.getNick().substr( 0, str.length() ) == str )
			tmp.push_back( checkClient.getNick() );
	}

	if (tmp.size() == 1)
	{
		nick += "_1";
		std::cout << nick << std::endl;
		client.addBacklog(":"
						+ sender(client)
						+ " NICK :"
						+ nick
						+ "\r\n");

		client.setNick(nick);
	}
	else if (tmp.size() > 1)
	{
		int		max_index = 0;
		for (std::size_t i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] == get_max_str(tmp))
			{
				max_index = i;
				break;
			}
		}

		nick = ( str
							+ ft_itoa( std::atoi(
									get_max_str( tmp ).substr( str.length(),
									tmp[max_index].length() ).c_str() ) + 1));

		client.addBacklog(":"
						+ sender(client)
						+ " NICK :"
						+ nick
						+ "\r\n");

		client.setNick( nick );
	}
}

void nick::exec(int i_pfds, const std::vector<std::string> &cmds)
{
	std::string nick;
	ft::client	&client = M_CLIENT(i_pfds);

	nick = cmds[1];
	if (client.getNick() == nick)
		return ;
	for (size_t i = 1; i < this->pfds.size(); i++)
	{
		if (i != (size_t)i_pfds && M_CLIENT(i).getNick() == nick)
		{
			// client.addBacklog(":ircserv " + ERR_NICKNAMEINUSE + " * " + nick + " :Nickname is already in use.\r\n");
			creating_nick(nick, i_pfds);
			// client.addBacklog(":" + this->sender(client) + " NICK :" + nick + "\r\n");
			client.getReg().recvNick = true;
			return;
		}
	}
	client.getReg().recvNick = true;

	client.addBacklog(":"
						+ sender(client)
						+ " NICK :"
						+ nick
						+ "\r\n");
	
	client.setNick(nick);
}