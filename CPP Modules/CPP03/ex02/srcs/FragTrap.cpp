#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default Constructor called with name: " << this->_name << std::endl;
}

FragTrap::FragTrap(const std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Constructor called with name" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap: Assignement operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: Hey Guys, How about a High Five?" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;	
}