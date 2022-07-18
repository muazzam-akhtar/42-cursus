/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:10:59 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/06 12:10:59 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"
#include <cctype>

static bool	valid(std::string buffer)
{
	std::string::iterator ret;
	ret = buffer.end();
	ret--;
	if (!(std::isspace(*ret)))
		return (true);
	return (false);
}

static bool	valid_ph(std::string buffer)
{
	for(std::string::size_type i = 0; i < buffer.length(); i++)
	{
		if (!(std::isdigit(buffer[i])))
			return (false);
	}
	return (true);
}

void PhoneBook::add_contact(void)
{
	std::string					buffer;
	int	i;

	i = 0;
	if (this->index >= 8)
		i = this->index % 8;
	else 
		i = this->index;
	std::cout << "First name : ";
	while (std::getline(std::cin, buffer))
	{
		if (buffer.length() > 0 && valid(buffer) == true)
		{
			this->phone[i].set_first_name(buffer);
			break;
		}
		else
			std::cout << "Wrong input\nFirst name : ";
	}
	std::cout << "Last name : ";
	while (std::getline(std::cin, buffer))
	{
		if (buffer.length() > 0 && valid(buffer) == true)
		{
			this->phone[i].set_last_name(buffer);
			break;
		}
		else
			std::cout << "Wrong input\nLast name : ";
	}
	std::cout << "Nickname : ";
	while (std::getline(std::cin, buffer))
	{
		if (buffer.length() > 0 && valid(buffer) == true)
		{
			this->phone[i].set_nickname(buffer);
			break;
		}
		else
			std::cout << "Wrong input\nNickname : ";
	}
	std::cout << "Phone Number : ";
	while (std::getline(std::cin, buffer))
	{
		if (buffer.length() > 0 && valid_ph(buffer) == true)
		{
			this->phone[i].set_ph_num(buffer);
			break;
		}
		else
			std::cout << "Wrong input\nPhone Number : ";
	}
	std::cout << "Darkest Secret : ";
	while (std::getline(std::cin, buffer))
	{
		if (buffer.length() > 0 && valid(buffer) == true)
		{
			this->phone[i].set_darkest_secret(buffer);
			break;
		}
		else
			std::cout << "Wrong input\nDarkest Secret : ";
	}
	if (buffer.empty())
		std::cout << std::endl << "Contact was not added" << std::endl;
	else
		std::cout << std::endl << "Everything saved. Cool. :D" << std::endl;
	this->index++;
}
