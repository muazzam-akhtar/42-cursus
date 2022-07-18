/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:10:34 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 17:52:37 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

class	Sed
{
	public:
		Sed(std::string s1, std::string s2);
		~Sed(void);
		std::string	ft_reading(char *str);
		int			check_buffer(void);
		void	print_buffer(void);
		void	replacement(char *str);
		std::string	content;
	private:
		std::string	buffer;
		std::string	string1;
		std::string	string2;
};

#endif