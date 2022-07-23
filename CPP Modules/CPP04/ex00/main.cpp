/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:03:48 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/15 12:57:39 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int main(void)
// {
// 	{Cat	file;

// 	file.makeSound();}
// 	{
// 		Animal	trial;
// 		trial.makeSound();
// 	}
// 	{
// 		Animal	file("Muazzam");
// 		Animal	trial;
// 		trial = file;
// 		std::cout << trial.getType() << std::endl;
// 	}
// 	// const Animal* meta = new Animal();
// 	// const Animal* j = new Dog();
// 	// const Animal* i = new Cat();
// 	// std::cout << j->getType() << " " << std::endl;
// 	// std::cout << i->getType() << " " << std::endl;
// 	// i->makeSound(); //will output the cat sound!
// 	// j->makeSound();
// 	return (0);
// }

// int main()
// {
// 	{// const Animal* meta = new Animal();
// 	// const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	// std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	// j->makeSound();
// 	// meta->makeSound();
// 	delete	i;}
// 	// {
// 	// 	Animal	trial("Muazzam");
// 	// 	Animal	other(trial);
// 	// 	std::cout << other.getType() << std::endl;
// 	// }
// 	return (0);
// }

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete	i;
		delete	j;
		delete	meta;
	}
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		delete	i;
		delete	meta;
		return 0;
	}
}