#include "ASpell.hpp"

ASpell::ASpell() : _name("Empty"), _effects("Emptiness") {}

ASpell::~ASpell() {}

const std::string	&ASpell::getName(void) const { return (this->_name); }

const std::string	&ASpell::getEffects(void) const { return (this->_effects); }

ASpell::ASpell(const ASpell &src)
{
	*this = src;
}

ASpell::ASpell(const std::string &name, const std::string &effects) : _name(name), _effects(effects) {}

ASpell	&ASpell::operator=(const ASpell &src)
{
	this->_name = src._name;
	this->_effects = src._effects;
	return (*this);
}

void	ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}