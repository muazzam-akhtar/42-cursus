/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:13:18 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/27 12:12:43 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
int main(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 10;
        numbers[i] = value;
        mirror[i] = value;
    }
	std::cout << std::endl;
    //SCOPE
    {
		Array<int> tmp = numbers;
        Array<int> test(45);
        test = tmp;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << mirror[i] << " ";
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

// int	main(void)
// {
// 	{
// 		Array<int>	aryInt(10);
// 		std::cout << "Int array of size - " << aryInt.size() << std::endl;
// 		try
// 		{
// 			for (unsigned int i = 0; i < aryInt.size(); i++)
// 				aryInt[i] = i * 123;
// 			for (unsigned int i = 0; i < aryInt.size() + 1; i++)
// 				std::cout << i << " - " << aryInt[i] << std::endl;
// 		}
// 		catch (std::exception &e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 		std::cout << std::endl;

// 		Array<int>	empty;
// 		std::cout << "Empty array of size - " << empty.size() << std::endl;
// 		try
// 		{
// 			for (unsigned int i = 0; i < empty.size() + 1; i++)
// 				std::cout << i << " - " << empty[i] << std::endl;
// 		}
// 		catch (std::exception &e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 		std::cout << "Empty array after operator= of size - " << empty.size() << std::endl;
// 		empty = aryInt;
// 		try
// 		{
// 			for (unsigned int i = 0; i < empty.size() + 1; i++)
// 				std::cout << i << " - " << empty[i] << std::endl;
// 		}
// 		catch (std::exception &e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 	}
// 	std::cout << std::endl;
// 	{
// 		Array<std::string>	aryStr(4);

// 		std::cout << "> String array" << std::endl;
// 		aryStr[0] = "What ";
// 		aryStr[1] = "should ";
// 		aryStr[2] = "I ";
// 		aryStr[3] = "eat today?";
// 		try
// 		{
// 			for (unsigned int i = 0; i < aryStr.size(); i++)
// 				std::cout << aryStr[i];
// 			std::cout << std::endl;
// 		}
// 		catch (std::exception &e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 	}
// 	return (0);
// }