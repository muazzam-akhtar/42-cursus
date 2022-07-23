#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Default Constructor called with name: " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Constructor called with name: " << this->_name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor ScavTrap called with name: " << this->_name << std::endl;	
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap: Assignement operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		this->_hitPoints = other._hitPoints;
	}
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap: " << this->_name << BLUE << " is in Gate Keeper mode. Keep Out!" << DEFAULT << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints && this->_energyPoints)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << YELLOW << " attacks " << target << DEFAULT << ", causing "
			<<  this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap: Can't attack, Either the energy points is not positive or hit points" << std::endl;
}