#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class FragTrap : public	ClapTrap
{
	public:
		FragTrap( void );
		FragTrap(const std::string name);
		FragTrap	&operator=(const FragTrap &other);
		void highFivesGuys(void);
		~FragTrap(void);
};

#endif