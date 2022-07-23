/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:11:28 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/15 12:14:10 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat&operator=(const Cat &other);
		~Cat(void);
		void	makeSound(void) const;
};
#endif