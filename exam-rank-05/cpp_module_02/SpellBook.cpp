#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {}

void	SpellBook::learnSpell(ASpell *spell)
{
	this->spellBook.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void	SpellBook::forgetSpell(std::string &spellName)
{
	std::map<std::string, ASpell *>::iterator	it;

	it = this->spellBook.find(spellName);
	if (it != this->spellBook.end())
	{
		delete it->second;
		this->spellBook.erase(it);
	}
}

void	SpellBook::launchSpell(std::string spellName, ATarget &target)
{
	std::map<std::string, ASpell *>::iterator	it;
	ASpell	*spell;

	it = this->spellBook.find(spellName);
	if (it != this->spellBook.end())
	{
		spell = it->second;
		spell->launch(target);
	}
}

ASpell* SpellBook::createSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator	it;

	it = this->spellBook.find(spellName);
	if (it != this->spellBook.end())
		return (it->second);
	return (NULL);
}