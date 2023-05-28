/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:52:49 by wismith           #+#    #+#             */
/*   Updated: 2023/05/11 17:53:11 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands.hpp"

using namespace ft;

quit::quit(std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw,
	std::map<std::string, ft::channels *>	&chans) :
	ft::cinterface(c, p, pw), chan(chans) {}

quit::~quit() {}

std::string	pars(const std::vector<std::string> &cmds)
{
	std::string	res;

	for (size_t i = 1; i < cmds.size(); i++)
	{
		res += cmds[i];
		if (i != cmds.size() - 1)
			res += ' ';
	}
	return (res);
}

void	quit::exec(int i_pfds, const std::vector<std::string> &cmds)
{
	ft::client	&client = M_CLIENT(i_pfds);

	for (std::map<std::string, ft::channels *>::iterator it = this->chan.begin();
		it != this->chan.end(); it++)
		{
			ft::channels	*tmp = it->second;
			std::vector<int>	clients_fds;
			
			clients_fds = tmp->getFds();
			std::string msg;
			msg += ":" + sender(client) + " QUIT :Quit: has quit the server!\r\n";
			for (std::vector<int>::iterator iter = clients_fds.begin(); iter != clients_fds.end(); iter++)
			{
				if (*iter == M_CLIENT(i_pfds).getFd())
					tmp->sendToAll(msg, this->clients, M_CLIENT(i_pfds).getFd());
			}
		}
	client.markClientForDel();
	client.addBacklog(":" + client.getNick()
		+ " QUIT :" + pars(cmds) + "\r\n");
}
