/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:15:29 by wismith           #+#    #+#             */
/*   Updated: 2023/05/10 19:46:33 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef NETWORK_HPP
# define NETWORK_HPP

/** @brief external */
# include <unistd.h>
# include <map>
# include <vector>
# include <string>
# include <iostream>

/** @brief local */
# include "client.hpp"
# include "parser.hpp"
# include "channels.hpp"

/** @brief commands */
# include "commands.hpp"

namespace ft
{
	class network : public ft::parser
	{
		protected :
			std::map<std::string, ft::cinterface *>	cmds;
			std::map<CLIENT_FD, CLIENT>				clients;
			std::vector<pollfd>						pfds;
			std::string								password;
			std::map<std::string, ft::channels *>	chans;

			bool									firstFour(const std::string &cmd);
		public :
													network (std::string pw);
													~network ();

			void									selCmd(const std::vector<std::string> &cmds, int i_pfds);
	};
};


#endif