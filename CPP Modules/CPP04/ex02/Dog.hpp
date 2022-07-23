/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:07:11 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/17 14:42:38 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog&operator=(const Dog &other);
		~Dog(void);
		void	makeSound(void) const;
		Brain	*getBrains(void);
	private:
		Brain	*brains;
		
};

#endif
