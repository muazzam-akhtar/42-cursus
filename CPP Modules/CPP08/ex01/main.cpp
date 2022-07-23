/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:49:42 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/28 14:00:44 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <functional>
#include <string_view>

int main(void)
{
	try
	{
		/* code */
		int	num;
		Span	trial(5);
		srand(time(NULL));
		num = rand() % 50;
		trial.addNumber(num);
		num = rand() % 100;
		trial.addNumber(num);
		num = rand() % 100;
		trial.addNumber(num);
		num = rand() % 100;
		trial.addNumber(num);
		num = rand() % 100;
		trial.addNumber(num);
		std::cout << "Shortest Span: " << trial.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << trial.longestSpan() << std::endl;
		std::cout << trial << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}