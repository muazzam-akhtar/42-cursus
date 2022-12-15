#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	public:
		ASpell(void);
		virtual ~ASpell(void);
		const std::string	&getName(void) const;
		const std::string	&getEffects(void) const;
		ASpell(const std::string &name, const std::string &effects);
		ASpell(const ASpell &src);
		ASpell	&operator=(const ASpell &src);
		void	launch(const ATarget &target) const;
		virtual ASpell	*clone() const = 0;

	private:
		std::string	_name;
		std::string	_effects;
};

#endif