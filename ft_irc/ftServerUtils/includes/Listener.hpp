/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listener.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:57:26 by wismith           #+#    #+#             */
/*   Updated: 2023/05/08 16:46:31 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LISTENER_HPP
# define LISTENER_HPP

# include "ServerUtility.hpp"
# include "SetSocket.hpp"

namespace ft
{
	class Listener : public ft::SetSocket
	{
		private :
			int					connect_net(int sock, struct sockaddr_in addr);

		public :
								Listener();
								~Listener();

			std::string			setInfo(int domain, int service, int protocol,
								int port, unsigned long interface);

			std::string			setSockProto(int level, int option_name, int &opt);
			std::string			nonBlocking();
			std::string			BindConnect();
			std::string			ListenConnect();

	};
};

#endif