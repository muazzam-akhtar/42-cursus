/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:10:28 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/09 10:22:41 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

Sed::Sed(std::string s1, std::string s2):string1(s1), string2(s2){}
Sed::~Sed(void) { return ; }

std::string	Sed::ft_reading(char *str)
{
	std::ifstream	inFile(str);
	std::string	buf;
	std::string	content;
	while (getline(inFile, content))
	{
		if (buf.empty())
			buf = content;
		else
		{
			buf = buf.append("\n");
			buf = buf.append(content);
		}
	}
	this->buffer = buf;
	return (this->buffer);
}

int	Sed::check_buffer(void)
{
	if (this->buffer.empty())
		return (1);
	return (0);
}

void	Sed::replacement(char *str)
{
	int	ret = 0;
	std::string	tmp;

	ret = this->buffer.find(this->string1, ret);
	if (ret == -1)
	{
		std::cout << "No occurence of string1" << std::endl;
		return ;
	}
	while (ret >= 0)
	{
		if (ret >= 0)
		{
			tmp = this->buffer.substr(ret, this->string1.length());
			if (tmp == this->string1)
			{
				this->buffer.erase(ret, this->string1.length());
				this->buffer.insert(ret, this->string2);
			}
		}
		ret = this->buffer.find(this->string1, ret);
	}
	std::string	newFile;
	newFile = str;
	newFile.append(".replace");
	std::ofstream	outfile(newFile);
	outfile << this->buffer << std::endl;
	std::cout << "Replaced all the occurence of string 1 with string 2" << std::endl;
}

void	Sed::print_buffer(void)
{
	std::cout << this->buffer << std::endl;
}