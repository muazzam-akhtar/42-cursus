/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:11:28 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/17 14:41:24 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat&operator=(const Cat &other);
		~Cat(void);
		void	makeSound(void) const;
		Brain	*getBrains(void);
	private:
		Brain	*brains;
		
};
#endif