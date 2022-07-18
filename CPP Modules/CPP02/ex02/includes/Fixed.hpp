/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:05:16 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/13 10:05:17 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &other);
		Fixed(const int num);
		Fixed(const float real);
		Fixed	&operator=(const Fixed &ptr);
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);
		bool	operator>(const Fixed &op) const;
		bool	operator<(const Fixed &op) const;
		bool	operator<=(const Fixed &op) const;
		bool	operator>=(const Fixed &op) const;
		bool	operator==(const Fixed &op) const;
		bool	operator!=(const Fixed &op) const;
		Fixed	operator+(const Fixed &op) const;
		Fixed	operator-(const Fixed &op) const;
		Fixed	operator*(const Fixed &op) const;
		Fixed	operator/(const Fixed &op) const;
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		int	toInt(void)const;
		float	toFloat(void)const;
		static Fixed	&min(Fixed &v1, Fixed &v2);
		const static Fixed	&min(const Fixed &v1, const Fixed &v2);
		static Fixed	&max(Fixed &v1, Fixed &v2);
		const static Fixed	&max(const Fixed &v1, const Fixed &v2);
	private:
		int _num;
		static const int	bits = 8;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &val);

#endif