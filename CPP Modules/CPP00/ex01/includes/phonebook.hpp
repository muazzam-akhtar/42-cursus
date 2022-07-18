/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:11:03 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/06 12:11:04 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

const int	FIELD_WIDTH = 10;

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact(void);
		void	showPhonebook();
		void	search_contact();
	private:
		Contact	phone[8];
		int		index;
};

#endif