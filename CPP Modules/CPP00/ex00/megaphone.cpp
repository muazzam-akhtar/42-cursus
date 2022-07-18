/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:11:09 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/06 12:11:10 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#define ERROR "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

std::string	ft_string_upper(char *str)
{
	std::string ret = str;
	for (unsigned int i = 0; i < ret.length(); i++)
		ret[i] = std::toupper(str[i]);
	return (ret);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << ERROR;
	else
		for (int i = 1; i < argc; i++)
			std::cout << ft_string_upper(argv[i]);
	std::cout << std::endl;
	return (0);
}
