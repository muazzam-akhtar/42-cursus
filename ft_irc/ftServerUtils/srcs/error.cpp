/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:16:09 by wismith           #+#    #+#             */
/*   Updated: 2023/04/20 14:35:53 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error.hpp"

/**	@brief : Default Constructor */
error::error(){}

/**	@brief : Copy Constructor */
error::error(const error &e){(void)e;}

/**	@brief : Destrutcor */
error::~error(){}

/**	@brief : Copy Assignment Operator Overload */
error &error::operator=(const error &e){(void)e; return (*this);}

/**	@brief : Argc method check 3 arguments are present
 * @note : Arguments should be : ./ft_irc <port number> <password>
 */
void	error::argc(const int num){(num != 3 ? throw(IncorrectArgs()) : (void)num);}

/**	@brief : port method checks validity of the port number provided
 * @note : port_ should consist only of digits and should be between 
 * 		1024 and 65353, 1024 being the minimum, and 65353 being the max.
 * @note : example: the default for original irc was 6667
 * @return : will return the converted result in size_t
 */
size_t	error::port(const std::string &port_)
{
	size_t margin = port_.find_first_not_of("0123456789");
	int	res = std::atoi(port_.c_str());

	(margin != port_.npos ? throw(PortFailure()) :
	(res < 1024 || res > 65353 ? throw(PortFailure()) :
		(void)port_));
	return ((size_t)res);
}

/**	@brief : Checks the return of socket function
 * @note : upon success socket will return a valid file descriptor.
 * 			Throws SocketFailure exception if parameter < 0
 */
void	error::SocketCheck(int rtn)
{
	if (rtn < 0)
		throw (SocketFailure());
}

/**	@brief : Checks the return of Connect function.
 * @note : binding will return 0 on success,
 * 			throws ConnectFailure exception if parameter != 0
 */
void	error::ConnectionCheck(int rtn)
{
	if (rtn)
		throw (ConnectFailure());
}

/**	@brief : Checks the return of binding function.
 * @note : binding will return 0 on success.
 * 				throws BindingFailure exception if parameter != 0
 */
void	error::BindCheck(int rtn)
{
	if (rtn)
		throw (BindingFailure());
}

/**	@brief : Checks the return of listen function.
 * @note : listen will return 0 on success.
 * 			Throws ListenFailure exception if parameter != 0
 */
void	error::LstnCheck(int rtn)
{
	if (rtn)
		throw (ListenFailure());
}

/**	@brief : Checks the return of fcntl function.
 * @note : fcntl will return -1 on failure
 * 			Throws FcntlFailure exception if parameter == -1
 */
void	error::BlockCheck(int rtn)
{
	if (rtn == -1)
		throw (FcntlFailure());
}

/**	@brief : Checks the return of setsockopt function.
 * @note : setsockopt will return -1 on failure
 * 			Throws SockOptFailure exception if parameter == -1
 */
void	error::sockOptErr(int rtn)
{
	if (rtn == -1)
		throw (SockOptFailure());
}