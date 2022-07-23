/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:11:28 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/17 14:00:41 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat&operator=(const Cat &other);
		~Cat(void);
		void	makeSound(void) const;
		Brain	*getBrain(void);
	private:
		Brain	*brains;
		
};
#endif