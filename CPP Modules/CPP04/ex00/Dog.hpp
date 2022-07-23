/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:07:11 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/15 12:05:38 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog&operator=(const Dog &other);
		~Dog(void);
		void	makeSound(void) const;
};

#endif
