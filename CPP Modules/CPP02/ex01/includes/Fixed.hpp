/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:04:59 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/13 10:05:00 by makhtar          ###   ########.fr       */
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
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		int	toInt(void)const;
		float	toFloat(void)const;
	private:
		int _num;
		static const int	bits = 8;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &val);

#endif