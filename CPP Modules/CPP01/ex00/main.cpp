/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:06:20 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 17:16:01 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	std::cout << "Creating the first Zombie, Robert, \"manually\"" << std::endl;
	{
		Zombie	robert("Robert");
		robert.announce();
	}
	std::cout << "Creating the second Zombie, Georges, using the function newZombie"<< std::endl;
	{
		Zombie	*georges = newZombie("Georges");
		georges->announce();
		delete georges;
	}
	{
		std::cout << "Creating the third Zombie, Mark, using the function randomChump"<< std::endl;
		randomChump("Mark");
	}
}