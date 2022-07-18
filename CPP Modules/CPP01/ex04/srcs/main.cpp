/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:10:25 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/09 10:23:18 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

std::string	ft_reading(char *str)
{
	std::ifstream	inFile(str);
	std::string	buffer;
	std::string	content;
	while (getline(inFile, content))
	{
		if (buffer.empty())
			buffer = content;
		else
		{
			buffer = buffer.append("\n");
			buffer = buffer.append(content);
		}
	}
	return (buffer);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][0] == 0)
		{
			std::cout << "string 1 is empty" << std::endl;
			return (1);
		}
		Sed	Val(argv[2], argv[3]);
		Val.ft_reading(argv[1]);
		if (Val.check_buffer())
		{
			std::cout << "No content in the given file" << std::endl;
			return (1);
		}
		Val.replacement(argv[1]);
		return (0);
	}
	else
		std::cout << "ERROR: " << "Program should start in this format\n./sed filename string1 string2" << std::endl;
	return (1);
}