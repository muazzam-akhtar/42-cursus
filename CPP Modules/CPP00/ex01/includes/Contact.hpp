/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:11:05 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/06 17:54:11 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <iomanip>

class	Contact
{
	public:
		Contact(void);
	    ~Contact(void);
		void			set_first_name(std::string);
		void			set_last_name(std::string);
		void			set_nickname(std::string);
		void			set_ph_num(std::string);
		void			set_darkest_secret(std::string);
		std::string		get_first_name(void);
		std::string		get_last_name(void);
		std::string		get_nickname(void);
		std::string		get_num(void);
		std::string		get_darkest_secret(void);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	ph_number;
		std::string	darkest_secret;
};

#endif