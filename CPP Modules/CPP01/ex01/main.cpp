/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:06:43 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 13:06:43 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	announceAllZombies(Zombie *zombiehorde, size_t n)
{
	for (size_t i = 0; i < n; i++)
		zombiehorde[i].announce();
}

int main(void)
{
	std::cout << "Creating the first Zombie horde of Muaz" << std::endl;
	{
		Zombie	*first = zombieHorde(4, "12");
		announceAllZombies(first, 4);
		delete	[] first;
	}
}