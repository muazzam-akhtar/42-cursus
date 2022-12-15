#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;
class ATarget;

class SpellBook
{
	public:
		SpellBook();
		~SpellBook();
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string &spellName);
		void	launchSpell(std::string spellName, ATarget &target);
		ASpell* createSpell(std::string const &spellName);
	
	private:
		std::map<std::string, ASpell *>	spellBook;

};

#endif