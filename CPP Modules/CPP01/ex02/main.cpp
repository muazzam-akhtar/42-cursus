/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:31:13 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 12:31:13 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string	originalString = "HI THIS IS BRAIN";
	std::string	*stringPTR = &originalString;
	std::string	&stringREF = originalString;

	std::cout << "Original String address: " << &originalString << std::endl;
	std::cout << "Using String PTR: " << &(*stringPTR) << std::endl;
	std::cout << "Using String REF: " << &stringREF << std::endl;

	std::cout << "Original String: " << originalString << std::endl;
	std::cout << "Using String PTR: " << *stringPTR << std::endl;
	std::cout << "Using String REF: " << stringREF << std::endl;
	return (0);
}
