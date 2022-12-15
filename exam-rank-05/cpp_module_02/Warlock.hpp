#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class ASpell;
class SpellBook;

class Warlock
{
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock(void);
		void	setTitle(const std::string &title);
		const std::string	&getName(void) const;
		const std::string	&getTitle(void) const;
		void introduce() const;
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string &spellName);
		void	launchSpell(std::string spellName, ATarget &target);
	private:
		std::string	_name;
		std::string	_title;
		SpellBook	_arr;
};

#endif