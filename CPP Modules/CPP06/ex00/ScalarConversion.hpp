/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:13:56 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/24 16:10:44 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERSION_HPP
#define SCALAR_CONVERSION_HPP

# include <cmath>
# include <string>
# include <iomanip>
# include <cstring>
# include <climits>
# include <iostream>

class ScalarConversion
{
	public:
		class Impossible : public std::exception
		{
			public:
				Impossible(void);
				Impossible(const Impossible &src);
				Impossible &operator=(const Impossible &src);
				virtual ~Impossible(void) throw();
				const char	*what(void) const throw();
		};
		class NonDisplayable : public std::exception
		{
			public:
				NonDisplayable(void);
				NonDisplayable(const NonDisplayable &src);
				NonDisplayable &operator=(const NonDisplayable &src);
				virtual ~NonDisplayable(void) throw();
				const char	*what(void) const throw();
		};
	public:
		ScalarConversion(void);
		~ScalarConversion(void);
		ScalarConversion(const ScalarConversion &src);
		char	convertChar(double res);
		int	convertInt(double res);
		double	convertDouble(double res);
		ScalarConversion	&operator=(const ScalarConversion &src);
		static void checkChar(ScalarConversion convert, double res);
		static void checkInt(ScalarConversion convert, double res);
		static void checkDouble(ScalarConversion convert, double res, int precision);
		static void checkFloat(ScalarConversion convert, double res, int precision);
};


#endif