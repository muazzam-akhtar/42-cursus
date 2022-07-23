/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:47:09 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/13 15:50:06 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>
# include <iomanip>

# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"

class ClapTrap
{
	public:
		ClapTrap( void );
		ClapTrap(std::string name);
		ClapTrap( const ClapTrap &src );
		~ClapTrap(void);
		ClapTrap	&operator=(const ClapTrap &other);
		void attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		int		get_hitPoints(void);
		int		get_energyPoints(void);
		int		get_attackDamage(void);
		const std::string		get_name(void);
		void	print_info(void);

	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

std::ostream	&operator<<(std::ostream &ostr, ClapTrap const &ref);

#endif