#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->_name = "Marduk";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):_name(name)
{
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap Constructor called with name: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap: Assignement operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		this->_hitPoints = other._hitPoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called with name: " << this->_name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints && this->_energyPoints)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << YELLOW << " attacks " << target << DEFAULT << ", causing "
			<<  this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap: Can't attack, Either the energy points is not positive or hit points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints)
	{
		this->_energyPoints--;
		if (this->_hitPoints == 1000)
			std::cout << "ClapTrap " << this->_name << " has reached it's maximum value" << std::endl;
		else
		{
			this->_hitPoints += amount;
			if (this->_hitPoints > 0)
			{
				if (this->_hitPoints > 1000)
					this->_hitPoints = 1000;
			}
			std::cout << "ClapTrap " << this->_name << GREEN << " regains health with amount: " << amount << DEFAULT << ". Health remaining: " << this->_hitPoints << std::endl;
		}
	}
	else
		std::cout << "ClapTrap: No Energy Left" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " has reached it's minimum value" << std::endl;
	else
	{
		this->_hitPoints -= amount;
		if (this->_hitPoints < 0)
			this->_hitPoints = 0; 
		std::cout << "ClapTrap " << this->_name << RED << " got beat with damage " << amount << DEFAULT << ". Health remaining: " << this->_hitPoints << std::endl;
	}
}

int	ClapTrap::get_hitPoints(void)
{
	return (this->_hitPoints);
}

int	ClapTrap::get_energyPoints(void)
{
	return (this->_energyPoints);
}

int	ClapTrap::get_attackDamage(void)
{
	return (this->_attackDamage);
}

const std::string	ClapTrap::get_name(void)
{
	return (this->_name);
}

void	ClapTrap::print_info(void)
{
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Energy Points: " << this->get_energyPoints() << std::endl;
	std::cout << "Hit Points: " << this->get_hitPoints() << std::endl;
}

std::ostream	&operator<<(std::ostream &ostr, const ClapTrap &val)
{
	ClapTrap	trial = val;
	ostr << "Name: " << trial.get_name() << std::endl;
	ostr << "Attack Damage: " << trial.get_attackDamage() << std::endl;
	ostr << "Hit Points: " << trial.get_hitPoints() << std::endl;
	ostr << "Energy Points: " << trial.get_energyPoints() << std::endl;
	return (ostr);
}