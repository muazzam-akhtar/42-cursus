/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:01:01 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/24 16:44:15 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

static int	getPrecision(char *str)
{
	size_t	before;
	size_t	after;
	for (before = 0; str[before] && str[before] != '.'; before++);
	after = before + 1;
	for (after = before + 1; str[after] && isdigit(str[after]); after++);
	after -= before;
	return (strlen(str) == before || after == 1 ? 1 : after - 1);
}

int main(int argc, char **argv)
{
	double	val;
	int		precision;
	ScalarConversion	convert;
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			if (i > 1)
				std::cout << std::endl;
			std::cout << "String: " << argv[i] << std::endl;
			precision = getPrecision(argv[i]);
			val = atof(argv[i]);
			convert.checkChar(convert, val);
			convert.checkInt(convert, val);
			convert.checkFloat(convert, val, precision);
			convert.checkDouble(convert, val, precision);
		}
	}
	else
		return (1);
	return(0);
}