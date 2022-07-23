/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:54:53 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/15 11:53:34 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
# include <iostream>
# include <string>
# include <iomanip>

# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"
# define BLUE "\001\033[1;94m\002"

class Animal
{
	public:
		Animal(void);
		Animal(const Animal &other);
		Animal(const std::string type);
		virtual ~Animal(void);
		const std::string	getType(void) const;
		virtual void	makeSound(void) const;
		Animal	&operator=(const Animal &other);
	protected:
		std::string	type;
};

#endif