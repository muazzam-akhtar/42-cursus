#ifndef RPN_HPP
# define RPN_HPP

# include <algorithm>
# include <stack>
# include <iterator>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <list>
# include <string>
# include <sstream>
# include <climits>

class RPN
{
	public:

		/******* Constructors ********/
	
		RPN();
		RPN(const std::string &);
		RPN(const RPN &);
		RPN	&operator=(const RPN &);
		~RPN();
		
		/******* Parsing Functions ********/

		int		printError(int);
		int		readingInput();
		int		parsingInput(std::stack< std::string, std::list<std::string> >);
		const	std::string &getString() const;
		int		isOper(char c);
		void	storeChars();
		int		parseString(const std::string &str);

		/******* Execution Functions ********/

		int		execution();
		int		checkOperation(int a, int b, char c);
		int		executeOperation(int a, int b, char c);
		int		printResult();
		
	private:

		/******* Private Variables ********/
		
		std::stack< int, std::list<int> >					_stackInt;
		std::stack< std::string, std::list<std::string> >	_stackString;
		std::string											_str;
};

#endif