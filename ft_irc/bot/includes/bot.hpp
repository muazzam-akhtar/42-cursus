/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:45:00 by wismith           #+#    #+#             */
/*   Updated: 2023/05/26 14:29:06 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef BOT_HPP
# define BOT_HPP

# ifndef PORT
# define PORT 6667
#endif

# ifndef PASS
# define PASS std::string("bob")
#endif

# ifndef MSGFILE
# define MSGFILE std::string("bot/msg.txt")
#endif

# define NPOLL(nfd) (struct pollfd){ .fd = nfd, .events = POLLIN | POLLOUT, .revents = 0 }

# include <poll.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <signal.h>
# include <vector>
# include <string>
# include <fstream>

# include "../../ftServerUtils/includes/error.hpp"
#include "../includes/parser.hpp"

namespace ft
{
	class bot
	{
		private :
			int							fd;
			struct pollfd				pfd;
			std::string					buffer;
			ft::parser					pars;
			std::vector<std::string>	msgs;
			std::vector<std::string>	backlog;
			std::vector<std::string>	chan;
			bool						sendingCmd;

		public	:
										bot ();
										~bot ();

			void						init (int);
			void						Connect(std::string);
			void						run ();

			void						catch_signals();
			std::string					Read(int fd);
			void						retrieveMsgs();
			void						selCmd(std::vector<std::string>);
			std::string					toLower(const std::string);
	};
};

#endif