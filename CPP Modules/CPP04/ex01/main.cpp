/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:03:48 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/17 14:31:32 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

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

#define NUM 100

/*int main(void)
{
	{	
		const Animal *j[NUM];

		for (int k = 0; k < NUM; k++)
			k % 2 == 0 ? j[k] = new Cat() : j[k] = new Dog();
		for (int k = 0; k < NUM; k++)
		{
			std::cout << "Animal " << k + 1 << " ";
			k % 2 == 0 ? std::cout << "Cat: " : std::cout << "Dog: ";
			j[k]->makeSound();
		}
		for (int k = 0; k < NUM; k++)
			delete j[k];
	}
	{
		const Animal *j[NUM];

		for (int k = 0; k < NUM; k++)
			k < NUM / 2 ? j[k] = new Cat() : j[k] = new Dog();
		for (int k = 0; k < NUM; k++)
		{
			std::cout << "Animal " << k + 1 << " ";
			k < NUM / 2 ? std::cout << "Cat: " : std::cout << "Dog: ";
			j[k]->makeSound();
		}
		for (int k = 0; k < NUM; k++)
			delete j[k];
	}
	// {
	// 	Dog	basic;
	// 	{	
	// 		Dog	tmp = basic;
	// 	}
	// }
	return (0);
}*/

int main() {
	// {	
	// 	Dog *basic = new Dog;
		
	// 	basic->getBrain()->set_ideas("Lick the bone\n");
	// 	Dog basic2 = *basic;
	// 	delete basic;
	// 	for (int i = 10; i < 20; i++)
	// 		std::cout << basic2.getBrain()->ideas[i];
	// 	std::cout << std::endl;
	// 	basic2.getBrain()->set_ideas("Hug a Human\n");
	// 	for (int i = 10; i < 20; i++)
	// 		std::cout << basic2.getBrain()->ideas[i];
	// 	basic2.makeSound();
	// }
	// {
	// 	Cat *basic = new Cat;
		
	// 	basic->getBrain()->set_ideas("Cuddle\n");
	// 	Cat basic2 = *basic;
	// 	delete basic;
	// 	for (int i = 10; i < 20; i++)
	// 		std::cout << basic2.getBrain()->ideas[i];
	// 	std::cout << std::endl;
	// 	basic2.makeSound();
	// }
	{
		const Animal *j[NUM];

		for (int k = 0; k < NUM; k++)
			k < NUM / 2 ? j[k] = new Cat() : j[k] = new Dog();
		for (int k = 0; k < NUM; k++)
		{
			std::cout << "Animal " << k + 1 << " ";
			k < NUM / 2 ? std::cout << "Cat: " : std::cout << "Dog: ";
			j[k]->makeSound();
		}
		for (int k = 0; k < NUM; k++)
			delete j[k];
	}
	{	
		const Animal *j[NUM];

		for (int k = 0; k < NUM; k++)
			k % 2 == 0 ? j[k] = new Cat() : j[k] = new Dog();
		for (int k = 0; k < NUM; k++)
		{
			std::cout << "Animal " << k + 1 << " ";
			k % 2 == 0 ? std::cout << "Cat: " : std::cout << "Dog: ";
			j[k]->makeSound();
		}
		for (int k = 0; k < NUM; k++)
			delete j[k];
	}
}

// int main()
// {
// 	{
// 		const Animal* meta = new Animal();
// 		const Animal* j = new Dog();
// 		const Animal* i = new Cat();
// 		std::cout << j->getType() << " " << std::endl;
// 		std::cout << i->getType() << " " << std::endl;
// 		i->makeSound(); //will output the cat sound!
// 		j->makeSound();
// 		meta->makeSound();
// 		delete	i;
// 		delete	j;
// 		delete	meta;
// 	}
// 	{
// 		const WrongAnimal* meta = new WrongAnimal();
// 		const WrongAnimal* i = new WrongCat();
// 		std::cout << i->getType() << " " << std::endl;
// 		i->makeSound(); //will output the cat sound!
// 		meta->makeSound();
// 		delete	i;
// 		delete	meta;
// 		return 0;
// 	}
// }