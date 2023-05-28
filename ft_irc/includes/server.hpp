/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:30:56 by wismith           #+#    #+#             */
/*   Updated: 2023/05/11 17:49:22 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SERVER_HPP
# define SERVER_HPP


# include <map>
# include <sys/poll.h>
# include <sys/signal.h>
# include <string>
# include <vector>

# include "client.hpp"
# include "network.hpp"
# include "welcome.hpp"
# include "../ftServerUtils/includes/Listener.hpp"

/** @brief NPOLL macro is used to define a pollfd struct
 * 	@note takes a new fd as arg
*/
# define NPOLL(nfd) (struct pollfd){ .fd = nfd, .events = POLLIN | POLLOUT, .revents = 0 }

# define RUNNING 1
# define SHUTDOWN 0

/*
*	struct pollfd
*	{
*		int fd;
*		int	events = POLLIN | POLLOUT;
*		int revents = 0;
*	}
*
*	struct pollfd *pfds
*/

namespace ft
{
	class server : public network
	{
		private :
			int				state;
			int				opt;
			int				port;
			ft::Listener	lstn;

			void			lstnInit();
			void			regNewClient();
			void			receiveCmds(size_t);
			void			sendReply(size_t);
			bool			rmClient(size_t);

		public :
							server (int nport, std::string pw);
							~server ();

			void			init();
			void			run();
	};

	/**	@brief : global determines whether server keeps running */
	extern bool	g_server_run;

	/**	@brief : signal handler prototype */

	/**	@brief : signals that terminate are caught by catch_signals
	 * @note : We want to catch signals to avoid memory leaks.
	 * 	Instead of terminating the program immediately, we break the
	 * 		server loop so the program can move on to freeing and exiting,
	 * 		properly.
	 */
	void	catch_signals();
};

#endif