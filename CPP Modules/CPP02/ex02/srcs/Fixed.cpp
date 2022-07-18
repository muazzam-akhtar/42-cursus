/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:05:20 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/13 10:16:19 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(void)
{
	this->_num = 0;
}

Fixed::~Fixed(void){}

Fixed::Fixed(const int value)
{
	this->_num = value << this->bits;
}

Fixed::Fixed(const float value)
{
	this->_num = roundf(value * (1 << this->bits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
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

Fixed	&Fixed::operator=(const Fixed &op)
{
	if (this != &op)
		this->_num = op.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &op) const
{
	return (this->_num > op._num);
}

bool	Fixed::operator<(const Fixed &op) const
{
	return (this->_num < op._num);
}

bool	Fixed::operator<=(const Fixed &op) const
{
	return (this->_num <= op._num);
}

bool	Fixed::operator>=(const Fixed &op) const
{
	return (this->_num >= op._num);
}

bool	Fixed::operator==(const Fixed &op) const
{
	return (this->_num == op._num);
}

bool	Fixed::operator!=(const Fixed &op) const
{
	return (this->_num != op._num);
}

Fixed	Fixed::operator+(const Fixed &op) const
{
	return (Fixed(this->toFloat() + op.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &op) const
{
	return (Fixed(this->toFloat() - op.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &op) const
{
	return (Fixed(this->toFloat() * op.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &op) const
{
	return (Fixed(this->toFloat() / op.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	this->_num += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	operator++();
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_num -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

int	Fixed::toInt(void)const
{
	return ((int)(this->_num >> bits));
}

float	Fixed::toFloat(void)const
{
	return ((float)(this->_num) / (1 << this->bits));
}

Fixed	&Fixed::min(Fixed &v1, Fixed &v2)
{
	return (v1 < v2 ? v1 : v2);
}

const Fixed	&Fixed::min(const Fixed &v1, const Fixed &v2)
{
	return (v1 < v2 ? v1 : v2);
}

Fixed	&Fixed::max(Fixed &v1, Fixed &v2)
{
	return (v1 > v2 ? v1 : v2);
}

const Fixed	&Fixed::max(const Fixed &v1, const Fixed &v2)
{
	return (v1 > v2 ? v1 : v2);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &val)
{
	out << val.toFloat();
	return (out);
}