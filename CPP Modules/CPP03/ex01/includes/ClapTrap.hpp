#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>
# include <iomanip>

#define RED "\001\033[1;91m\002"
#define GREEN "\001\033[1;92m\002"
#define DEFAULT "\001\033[0;39m\002"
#define YELLOW "\001\033[1;93m\002"

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap( const ClapTrap &src );
		~ClapTrap(void);
		ClapTrap	&operator=(const ClapTrap &other);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		int		get_hitPoints(void);
		int		get_energyPoints(void);
		int		get_attackDamage(void);
		const std::string		get_name(void);
		void	print_info(void);

	protected:
		ClapTrap(void);
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

std::ostream	&operator<<(std::ostream &ostr, const ClapTrap &val);

#endif