#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"
#define BLUE "\001\033[1;94m\002"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap(void);
		ScavTrap	&operator=(const ScavTrap &other);
		void guardGate( void );
		void	attack(const std::string &target);
};

#endif