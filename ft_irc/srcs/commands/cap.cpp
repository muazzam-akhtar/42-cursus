/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:27:19 by wismith           #+#    #+#             */
/*   Updated: 2023/05/09 16:55:51 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands.hpp"

using namespace ft;

cap::cap(std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw) :
	ft::cinterface(c, p, pw) {}

cap::~cap() {}

void	cap::exec(int i_pfds, const std::vector<std::string> &cmds)
{
	if (cmds.size() < 2)
		return ;
	ft::client	&client = M_CLIENT(i_pfds);
	if (cmds[1] == "LS")
	{
		client.getReg().recvCapLs = true;
		client.addBacklog("CAP * LS\r\n");
	}
	else if (cmds[1] == "REQ")
		client.addBacklog("CAP * ACK\r\n");
	else if (cmds[1] == "END")
		client.getReg().recvCapEnd = true;
}
