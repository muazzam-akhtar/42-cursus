#include "../includes/ScavTrap.hpp"

int main(void)
{
	{
		ScavTrap demo("Demolisher");

		demo.attack("Jack");
		demo.takeDamage(6);
		demo.beRepaired(4);
		demo.takeDamage(3);
		demo.guardGate();
		demo.beRepaired(8);
		demo.takeDamage(17);
		demo.takeDamage(84);
		demo.beRepaired(101);
		std::cout << demo;
	}
	{
		ClapTrap phantom("Phantom");

		phantom.attack("Jack");
		phantom.takeDamage(6);
		phantom.beRepaired(4);
		phantom.takeDamage(3);
		phantom.beRepaired(8);
		phantom.takeDamage(17);
	}
	return (0);
}