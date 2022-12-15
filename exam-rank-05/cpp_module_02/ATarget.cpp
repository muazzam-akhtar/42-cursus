#include "ATarget.hpp"

ATarget::ATarget() : _type("Empty") {}

ATarget::~ATarget() {}

const std::string	&ATarget::getType(void) const { return (this->_type); }

ATarget::ATarget(const ATarget &src)
{
	*this = src;
}

ATarget::ATarget(const std::string &type) : _type(type) {}

ATarget	&ATarget::operator=(const ATarget &src)
{
	this->_type = src._type;
	return (*this);
}

void	ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << this->_type << " has been " << spell.getEffects() << std::endl;
}