/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:07:06 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/10 14:29:51 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &other);
		Fixed	&operator=(const Fixed &ptr);
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int num;
		static const int	bits = 8;
};

#endif