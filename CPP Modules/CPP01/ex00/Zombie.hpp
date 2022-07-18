/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:06:32 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 13:06:33 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
	
	private:
		void		prefix(void);
		std::string	name;
};

Zombie	*newZombie(std::string name);
void randomChump( std::string name );

#endif