#include "../includes/ClapTrap.hpp"

int main(void)
{
	{
		ClapTrap	trial("Muazzam");

		trial.attack("Bassam");
		trial.beRepaired(50);
		trial.takeDamage(60);
		trial.beRepaired(40);
		trial.takeDamage(40);
		trial.attack("Patel");
		trial.takeDamage(40);
		trial.takeDamage(1040);
		trial.beRepaired(2040);
		trial.takeDamage(400);
		trial.takeDamage(1200);
		trial.beRepaired(1001);
		trial.takeDamage(1001);
	}
	{
		ClapTrap	file;

		file.attack("Bassam");
		std::cout << file;
	}
	return (0);
}