/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listener.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:00:43 by wismith           #+#    #+#             */
/*   Updated: 2023/05/01 20:17:14 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Listener.hpp"

ft::Listener::Listener() : ft::SetSocket() {}

ft::Listener::~Listener() {}


/**	@brief setInfo method is used to set all the attributes for Listener object,
 * 			will call socket system call to initialize the socket fd (sock) attribute.
 * @note example input :
 * 			Domain: AF_INET, Service: SOCK_STREAM, protocol: 0, port: 6697, interface: INADDR_ANY
 * 	@note Throws SocketFailure Exception if socket system call fails. 
 */
std::string	ft::Listener::setInfo(int domain, int service, int protocol,
						int port, unsigned long interface)
{
	// int	opt = 1;
	struct sockaddr_in	newAddr;

	this->setSock(socket(domain, service, protocol));
	error().SocketCheck(this->getSock());

	newAddr.sin_family = domain;
	newAddr.sin_port = htons(port);
	newAddr.sin_addr.s_addr = htonl(interface);
	
	this->setAddress(newAddr);
	return ("Server Status: Socket fd set");
}

/**	@brief ListenConnect method initializes listening for the socket
 * @note Method requires no arguments, however, setInfo and BindConnect methods should
 * 			be called before ListenConnect.
 * @note example :
 * @note -> Listener.setInfo(arguments...)
 * @note ->	Listener.nonBlocking()
 * @note ->	Listener.BindConnect()
 * @note ->	Listener.ListenConnect()
 * 	@note Throws ListenFailure Exception if listen fails. 
 */
std::string	ft::Listener::ListenConnect()
{
	error().LstnCheck(listen(this->getSock(), this->getAddress().sin_port));
	return ("Server Status: Listening on Socket");
}

/**	@brief nonBlocking method uses fcntl system call to set socket
 * 			to non blocking.
 * 			Socket is is an attribute within the SetSocket class inherited by
 * 			Listener.
 *  @note Method requires no arguments, however setInfo method should be
 * 			called before nonBlocking, in order that the attributes of Listener
 * 			may be initialized. Attributes should be initialized for method to work.
 * 	@note throws FcntlFailure exception if fcntl system call fails
 */
std::string	ft::Listener::nonBlocking()
{
	error().BlockCheck(fcntl(this->getSock(), F_SETFL, O_NONBLOCK));
	return ("Server Status: Socket set to Non Blocking");
}

/**	@brief connect_net method used to perform bind system call
 * @note error class is used to check if bind was successful, and
 * 			will throw a BindingFailure Exception if not
 */
int	ft::Listener::connect_net(int sock, struct sockaddr_in addr)
{
	int	res = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
	error().BindCheck(res);
	return (res);
}

/**	@brief BindConnect method used to perform bind system call
 * 				assuming required vars have already been set using the value
 * 				constructor, or the setInfo method.
 * @note error class is used to check if bind was successful, and
 * 			will throw a BindingFailure Exception if not
 */
std::string	ft::Listener::BindConnect()
{
	this->setConnection(this->connect_net(this->getSock(), this->getAddress()));
	return ("Server Status: Binding Socket");
}

std::string	ft::Listener::setSockProto(int level, int option_name, int &opt)
{
	error().sockOptErr(setsockopt(this->getSock(), level, option_name, &opt, sizeof(opt)));
	std::string status = (option_name == SO_REUSEADDR ? "SO_REUSEADDR" : "SO_REUSEPORT");
	std::string	log = "Server Status: Set sock Opt \"" + status + "\"";
	return (log);
}

