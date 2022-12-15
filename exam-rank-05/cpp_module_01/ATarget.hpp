#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	public:
		ATarget();
		virtual ~ATarget();
		ATarget(const ATarget &src);
		ATarget(const std::string &type);
		ATarget	&operator=(const ATarget &src);
		const std::string	&getType(void) const;
		void	getHitBySpell(const ASpell &spell) const;
		virtual ATarget	*clone() const = 0;

	private:
		std::string	_type;
};

#endif