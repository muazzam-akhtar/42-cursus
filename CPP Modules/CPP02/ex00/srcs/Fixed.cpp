/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:29:39 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/11 16:28:44 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(void): num(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &ptr)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ptr)
		this->num = ptr.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->num);
}

void	Fixed::setRawBits( int const raw )
{
	this->num = raw;
	std::cout << "setRawBits member function called" << std::endl;
}