/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:06:55 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 13:06:55 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void	announce(void);
		bool	setName(std::string newName);

	private:
		void	prefix(void);
		std::string	name;
};

Zombie	*zombieHorde(int n, std::string name);
#endif