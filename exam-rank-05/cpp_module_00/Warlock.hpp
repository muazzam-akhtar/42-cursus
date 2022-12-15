#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock(void);
		void	setTitle(const std::string &title);
		const std::string	&getName(void) const;
		const std::string	&getTitle(void) const;
		void introduce() const;
	private:
		std::string	_name;
		std::string	_title;
};

#endif