#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title){ std::cout << this->_name << ": This looks like another boring day.\n"; }

Warlock::~Warlock(void) { std::cout << this->_name << ": My job here is done!\n"; }

void Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!\n";
}

void	Warlock::setTitle(const std::string &title)
{
	this->_title = title;
}

const std::string	&Warlock::getName(void) const
{
	return (this->_name);
}

const std::string	&Warlock::getTitle(void) const
{
	return (this->_title);
}

void	Warlock::learnSpell(ASpell *spell)
{
	this->_arr.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string &spellName)
{
	this->_arr.forgetSpell(spellName);
}

void	Warlock::launchSpell(std::string spellName, ATarget &target)
{
	this->_arr.launchSpell(spellName, target);
}