/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:41:00 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/15 12:47:29 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
# include <iostream>
# include <string>
# include <iomanip>

# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"
# define BLUE "\001\033[1;94m\002"

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal(const std::string type);
		~WrongAnimal(void);
		const std::string	getType(void) const;
		void	makeSound(void) const;
		WrongAnimal	&operator=(const WrongAnimal &other);
	protected:
		std::string	type;
};

#endif