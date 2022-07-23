/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:03:48 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/17 14:55:55 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define NUM 100

int main(void)
{
	{
		const AAnimal	*test[100];
		for (int i = 0; i < 50; i++)
			test[i] = new Dog();
		for (int i = 50; i < 100; i++)
			test[i] = new Cat();
		for (int i = 0; i < 100; i++)
		{
			i < NUM / 2 ? std::cout << "Dog: " : std::cout << "Cat: ";
			test[i]->makeSound();
		}
		for (int i = 0; i < 100; i++)
			delete test[i];
	}
	// {
	// 	Cat	test;
	// 	Dog	check;
		
	// 	for (int i = 0; i < 50; i++){ test.getBrains()->setIdeas("Cuddle"); }

	// 	for (int i = 50; i < 105; i++){ test.getBrains()->setIdeas("Attack Intruders"); }
		
	// 	for (int i = 0; i < 100; i++) { std::cout << test.getBrains()->ideas[i] << std::endl; }

	// 	for (int i = 0; i < 50; i++){ check.getBrains()->setIdeas("Lick a Bone"); }

	// 	for (int i = 50; i < 105; i++){ check.getBrains()->setIdeas("Protect My Owner"); }
		
	// 	for (int i = 0; i < 100; i++) { std::cout << check.getBrains()->ideas[i] << std::endl; }
	// }
	return (0);
}
