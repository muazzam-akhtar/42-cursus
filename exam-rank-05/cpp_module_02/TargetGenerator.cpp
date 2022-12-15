#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void	TargetGenerator::learnTargetType(ATarget* target)
{
	this->targets.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void	TargetGenerator::forgetTargetType(std::string const &target)
{
	std::map<std::string, ATarget *>::iterator	it;

	it = this->targets.find(target);
	if (it != this->targets.end())
	{
		delete it->second;
		this->targets.erase(it);
	}
}

ATarget*	TargetGenerator::createTarget(std::string const &target)
{
	std::map<std::string, ATarget *>::iterator	it;

	it = this->targets.find(target);
	if (it != this->targets.end())
		return (it->second);
	return (NULL);
}