#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;
class ATarget;

class TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();
		void	learnTargetType(ATarget* target);
		void	forgetTargetType(std::string const &target);
		ATarget*	createTarget(std::string const &target);
	
	private:
		std::map<std::string, ATarget *>	targets;
};

#endif