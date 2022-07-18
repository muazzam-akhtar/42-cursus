/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:10:55 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/06 12:10:56 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

Contact::Contact(void) { return ; }
Contact::~Contact(void) { return ; }

PhoneBook::PhoneBook(void) : index(0) { return ; }
PhoneBook::~PhoneBook(void) { return ; }

std::string	Contact::get_first_name()
{
	return (this->first_name);
}

std::string	Contact::get_last_name()
{
	return (this->last_name);
}

std::string	Contact::get_nickname()
{
	return (this->nickname);
}

std::string	Contact::get_num()
{
	return (this->ph_number);
}

std::string	Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}

void	Contact::set_first_name(std::string str)
{
	this->first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	this->last_name = str;
}

void	Contact::set_ph_num(std::string str)
{
	this->ph_number = str;
}

void	Contact::set_nickname(std::string str)
{
	this->nickname = str;
}

void	Contact::set_darkest_secret(std::string str)
{
	this->darkest_secret = str;
}
