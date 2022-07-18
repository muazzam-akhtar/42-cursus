/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:10:49 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 14:12:59 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iomanip>
#include <iostream>
#include <string>

#define RED "\001\033[1;91m\002"
#define GREEN "\001\033[1;92m\002"
#define BLUE "\001\033[1;94m\002"
#define YELLOW "\001\033[1;93m\002"
#define DEFAULT "\001\033[0;39m\002"

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void complain( std::string level );
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif