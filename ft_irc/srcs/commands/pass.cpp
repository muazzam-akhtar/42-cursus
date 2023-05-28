/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:45:04 by wismith           #+#    #+#             */
/*   Updated: 2023/05/12 02:00:51 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands.hpp"

using namespace ft;

/** @brief constructor for pass,
 * 			constructs the inherited cinterface class
 * 			that takes the map of clients, vector of pollfds,
 * 			and the password as reference.
*/
pass::pass( std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw ) :
	ft::cinterface( c, p, pw ) {}

/** @brief Destructor for pass */
pass::~pass() {}

/** @brief pass exec command function:
 * 			executes the pass command with it's 
 * 			parameter.
 * @note i_pdfs - index for pollfd vector (pfds) of that client.
 * 
 * 			Use:
 * 				ft::client &client = M_CLIENT(i_pdfs);
 * 					retrieves the client.
 * 
 * @note if number of params is less than 2 ERR_NEEDMOREPARAMS
 * 			is sent to the client.
 * @note if password doesn't match, ERR_PASSWDMISMATCH is sent
 * 			to the client.
*/
void	pass::exec( int i_pfds, const std::vector<std::string> &cmds )
{
	ft::client	&client = M_CLIENT( i_pfds );

	if ( cmds.size() < 2 )
		return ( this->reply( client,
				 ERR_NEEDMOREPARAMS,
				":Password needs more params!" ) );

	if ( this->password != cmds[1] )
	{
		this->reply( client,
			ERR_PASSWDMISMATCH,
			":Incorrect Password!" );
		return ( client.setStatus(ILLEGAL) );
	}
	client.setPassCheck( true );
}
