/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:09:16 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 17:42:48 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class	Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string	&getType(void) const;
		bool				setType(const std::string &newType);  

	private:
		std::string	type;
};

#endif