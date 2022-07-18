/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:07:10 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 13:07:10 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*zombieHorde = new Zombie[n];
	for (int i = 0; i < n; i++)
		zombieHorde[i].setName(name);
	return (zombieHorde);
}