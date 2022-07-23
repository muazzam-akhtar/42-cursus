/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:23:17 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/27 22:44:03 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <cstdlib>

template<typename T>
void	displayIterator( T it, T end )
{
	if (it != end)
		std::cout << "iterator: " << *it << std::endl;
	else
		std::cout << "iterator reached the end of container" << std::endl;
}

int main(void)
{
	{
		int	trial;
		std::vector<int> v;
		srand(time(NULL));
		std::vector<int>::iterator	n;
		for (int i = 0; i < 10; i++)
		{
			trial = rand() % 100;
			v.push_back(trial);
			/* code */
		}
		v.push_back(25);
		std::cout << "v = ";
		for (n = v.begin(); n != v.end(); n++)
		{
	        std::cout << *n << " ";
	    }
		std::cout << std::endl;
		int	i = 5;
		std::vector<int>::iterator	ret;
		try
		{
			ret = easyfind(v, i);
			std::cout << *ret << std::endl;
			/* code */
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::vector<int>			vect;
		std::vector<int>::iterator	it;
		for (int i = 1; i < 59; i += 2)
			vect.push_back(i);
		try
		{
			it = easyfind(vect, 43);
			displayIterator(it, vect.end());
			/* code */
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			it = easyfind(vect, 42);
			displayIterator(it, vect.end());
			/* code */
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	return (0);
}