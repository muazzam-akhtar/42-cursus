/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:29:39 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/13 14:38:17 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(void): _num(0)
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

Fixed::Fixed(const int num)
{
	this->_num = num << this->bits;
	std::cout << this->_num << std::endl;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float real)
{
	this->_num = roundf(real * (1 << this->bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &ptr)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &ptr)
		this->_num = ptr.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_num);
}

void	Fixed::setRawBits( int const raw )
{
	this->_num = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

int	Fixed::toInt(void)const
{
	return ((int)(this->_num >> bits));
}

float	Fixed::toFloat(void)const
{
	return ((float)(this->_num) / (1 << this->bits));
}

std::ostream	&operator<<(std::ostream &out, Fixed const &val)
{
	out << val.toFloat();
	return (out);
}