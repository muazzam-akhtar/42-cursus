/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:05:23 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/13 10:17:41 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
/*
int main(void)
{
	Fixed	a;
	// float	num;

	a = Fixed(15.45f);
	// num = 15.454787;
	std::cout << a - 2 << std::endl;
	std::cout << a-- << std::endl;
	// std::cout << a << std::endl;
	return (0);
}*/

/*
int main( void ) 
{
	Fixed a;
	a.setRawBits(16);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}*/

int main( void ) 
{
	Fixed a;

	a = Fixed(15.42f);
	a.setRawBits(16);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}