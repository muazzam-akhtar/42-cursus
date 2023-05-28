/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:06:06 by wismith           #+#    #+#             */
/*   Updated: 2023/05/01 17:31:20 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef ERROR_HPP
# define ERROR_HPP

# include "ServerUtility.hpp"

/**	@brief : Included exceptions and error class */

/** @brief : Exception thrown when the port number provided in arguments
 * 		are invalid.
 * @note : port number should consist of only digits, and be 
 * 		(1024 < port number < 65353)
*/
class PortFailure : public std::exception
{
	public :
		const char* what() const throw()
		{
			return ("ft_irc: Err: Invalid port number!\n");
		}
};

/**	@brief : Included exceptions and error class */

/**	@brief : Exception thrown when arguments are incorrect
 * @note : arguments should be as follows:
 * 		./ft_irc <port number> <password>
 */
class IncorrectArgs : public std::exception
{
	public :
		const char* what() const throw()
		{
			return ("ft_irc: Err: Incorrect Arguments!\n");
		}
};

/**	@brief : Exception thrown when bind system call fails
 * @note : Upon failure bind returns -1
 */
class BindingFailure : public std::exception
{
	public :
		const char* what() const throw()
		{
			return ("ft_irc: Err: Failed to bind!\n");
		}
};

/**	@brief : Exception thrown when connect system call fails
 * @note : Upon failure bind returns -1
 */
class ConnectFailure : public std::exception
{
	public :
		const char* what() const throw()
		{
			return ("ft_irc: Err: Failed to connect!\n");
		}
};

/**	@brief : Exception thrown when socket system call fails
 * @note : Upon failure socket returns -1
 */
class SocketFailure : public std::exception
{
	public :
		const char* what() const throw()
		{
			return ("ft_irc: Err: Failed to create socket!\n");
		}
};

/**	@brief : Exception thrown when listen system call fails
 * @note : Upon failure listen returns -1
 */
class ListenFailure : public std::exception
{
	public :
		const char* what() const throw()
		{
			return ("ft_irc: Err: Failed to listen!\n");
		}
};

/**	@brief : Exception thrown when fcntl system call fails
 * @note : Upon failure fcntl returns -1
 */
class FcntlFailure : public std::exception
{
	public :
		const char* what() const throw()
		{
			return ("ft_irc: Err: Failed to perform fcntl op!\n");
		}
};

/**	@brief : Exception thrown when setsockopt system call fails
 * @note : Upon setsockopt fcntl returns -1
 */
class SockOptFailure : public std::exception
{
	public :
		const char* what() const throw()
		{
			return ("ft_irc: Err: Failed to perform setSockOpt op!\n");
		}
};

/** @brief : error class used to check socket connection system calls for errors
 * 		and for parsing errors.
 * @note : easily access the methods as follows :
 *! 			error().method(test);
*/
class error
{
	public :
		error();
		error(const error &e);
		~error();
		
		error	&operator=(const error &e);

		void	argc(const int num);
		size_t	port(const std::string &str);

		void	SocketCheck(int rtn);
		void	BindCheck(int rtn);
		void	LstnCheck(int rtn);
		void	ConnectionCheck(int rtn);
		void	BlockCheck(int rtn);
		void	sockOptErr(int rtn);
};

#endif