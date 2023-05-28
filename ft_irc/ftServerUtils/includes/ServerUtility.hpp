/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerUtility.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:24:04 by wismith           #+#    #+#             */
/*   Updated: 2023/05/08 22:53:17 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SERVERUTILITY_HPP
# define SERVERUTILITY_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include <fstream>
# include <string>
# include <sstream>

# include "error.hpp"
# include "Listener.hpp"
# include "log.hpp"

/** @brief << template operator overload used to convert any variable
 * 				type to string.
 * 	@note	should use only integral types as arguments.
 //! @note e.g. :
 * 	@note			std::string() << 5; 
 *	@note			std::string() << 5.6;
 *	@note			std::string() << 'c';
 //! @note			or
 * 	@note 			std::string	example;
 * 	@note			example << "hi bob";
*/
template <class T>
std::string	&operator<<(std::string &str, T const &t)
{
	std::stringstream	ss;
	ss << t;
	str = ss.str();
	return (str);
}

#endif