/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_phonebook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:10:49 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/06 12:10:50 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

static bool	valid_index(std::string buffer)
{
	for(std::string::size_type i = 0; i < buffer.length(); i++)
	{
		if (!(std::isdigit(buffer[i])))
			return (false);
	}
	return (true);
}

void	PhoneBook::search_contact()
{
	int			index;
	std::string	buffer;

	std::cout << "Write the index" << std::endl;
	while (getline(std::cin, buffer, '\n'))
	{
		if (valid_index(buffer) == true)
			break;
		else
			std::cout << "Input is not valid" << std::endl;
	}
	if (buffer.empty())
		return ;
	if (buffer.length() > 0)
	{
		std::istringstream(buffer) >> index;
		if (index >= 0 && index <= 7)
		{
			if (index < this->index)
			{
				std::cout << "" << std::endl;
				buffer = this->phone[index].get_first_name();
				std::cout << "First name: ";
				std::cout << buffer << std::endl;
				buffer = this->phone[index].get_last_name();
				std::cout << "Last name: ";
				std::cout << buffer << std::endl;
				buffer = this->phone[index].get_nickname();
				std::cout << "Nickname: ";
				std::cout << buffer << std::endl;
				buffer = this->phone[index].get_num();
				std::cout << "Contact Number: ";
				std::cout << buffer << std::endl;
				buffer = this->phone[index].get_darkest_secret();
				std::cout << "Darkest Secret: ";
				std::cout << buffer << std::endl;
			}
			else
				std::cout << "Index is NULL" << std::endl;
		}
		else
			std::cout << "Given index is wrong" << std::endl;
	}
	else
		std::cout << "Given index is wrong" << std::endl;
	std::cout << "" << std::endl;
}

static std::string
update_width(std::string field)
{
    field = field.erase((FIELD_WIDTH - 1), \
    field.length() - (FIELD_WIDTH - 1));
    field.append(".");
    return (field);
}

void	PhoneBook::showPhonebook()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	int	n;

	if (this->index <= 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
	// std::cout << std::setw(FIELD_WIDTH);
	std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
	n = this->index;
	if (this->index >= 8)
		n = 8;
	for (int i = 0; i < n; i++)
	{
		first_name = this->phone[i].get_first_name();
		last_name = this->phone[i].get_last_name();
		nickname = this->phone[i].get_nickname();

		std::cout << "|" << std::setw(FIELD_WIDTH) << i;
        first_name = (first_name.length() > FIELD_WIDTH) ? \
            update_width(first_name) : first_name;
		std::cout << "|" << std::setw(FIELD_WIDTH) << first_name;

		last_name = (last_name.length() > FIELD_WIDTH) ? \
            update_width(last_name) : last_name;
		std::cout << "|" << std::setw(FIELD_WIDTH) << last_name;

		nickname = (nickname.length() > FIELD_WIDTH) ? \
            update_width(nickname) : nickname;
		std::cout << "|" << std::setw(FIELD_WIDTH) << nickname;
		std::cout << "|" << std::endl;
	}
	search_contact();
}