/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:39:43 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/24 23:24:02 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

Base	*generate(void)
{
	srand((unsigned int)time(NULL));
	int	classType = rand() % 3;
	std::cout << "Num: " << rand() << ", classType: " << classType << std::endl;
	if (classType == 0)
		return (new A);
	else if (classType == 1)
		return (new B);
	else if (classType == 2)
		return (new C);
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	Base	a;
	Base	b;
	Base	c;
	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}catch(const std::exception& e) { std::cout << "A: Not this\n"; }

	try
	{
		b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}catch(const std::exception& e) { std::cout << "B: Not this\n"; }

	try
	{
		c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}catch(const std::exception& e) { std::cout << "C: Not this\n"; }
	
}

int main(void)
{
	Base	*ptr = generate();
	Base	*ref = generate();

	identify(ptr);
	identify(*ref);
	delete	ptr;
	delete	ref;
	return (0);
}