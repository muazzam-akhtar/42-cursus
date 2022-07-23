/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:10:40 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/25 16:36:55 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <cstdlib>

template<typename T>

void	display(T &whatever)
{
	std::cout << "Variable's value is: " << whatever << std::endl;
}

void	setRandomValues(int &num)
{
	num = std::rand() % 100;
}

int main(void)
{
	std::string	strTable[3];
	int			*intTable = new int[5];

	strTable[0] = "Hi, How are you?";
	strTable[1] = "Fine, and you dear sir?";
	strTable[2] = "Very fine indeed";
	iter(strTable, 3, &display);
	for (int i = 0; i < 5; i++)
		setRandomValues(intTable[i]);
	iter(intTable, 5, &display);
	delete [] intTable;
	return (0);
}