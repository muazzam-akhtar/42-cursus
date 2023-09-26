#include "RPN.hpp"

RPN::RPN() : _str("") {}

RPN::RPN(const std::string &str) : _str(str) {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_stackInt = other._stackInt;
		this->_stackString = other._stackString;
		this->_str = other._str;
	}
	return (*this);
}

RPN::~RPN() {}

int	RPN::isOper(char c)
{
	std::string	opers = "+-/*";
	if (opers.find_first_of(c) > 3)
		return (0);
	return (1);
}

const std::string &RPN::getString() const { return (this->_str);  }

int	RPN::parseString(const std::string &str)
{
	std::stringstream strStream(str);
	long int	num;

	if (str.find_first_not_of("0123456789+-*/") < str.length())
		return (0);
	strStream >> num;
	if (num > -10 && num < 10 && str.length() > 2)
		return (0);
	if (str.find_first_of("+-") > 0 && str.find_first_of("+-") < str.length())
		return (0);
	if (num == 0 && str.length() > 1)
		return (0);
	if (num == 0)
		if (str.find_first_of("+-/*") < str.length())
			return (1);
	if (str.length() <= 11 && num >= -9 && num <= 9)
		return (2);
	return (0);
}

int	RPN::printError(int code)
{
	std::cerr << std::endl << "\033[1;31m*************ERROR*************\033" << std::endl;
	switch (code)
	{
		case 1:
			std::cerr << ": " << "Not an Operator at the end!" << std::endl << std::endl;
			break;
		case 2:
			std::cerr << ": " << "First two inputs are not operands!" << std::endl << std::endl;
			break;
		case 3:
			std::cerr << ": " << "Invalid Input!" << std::endl << std::endl;
			break;
		case 4:
			std::cerr << ": " << "Invalid Sequence!" << std::endl << std::endl;
			break;
		case 5:
			std::cerr << ": " << "Number divisible by 0!" << std::endl << std::endl;
			break;
		case 6:
			std::cerr << ": " << "Result too long!" << std::endl << std::endl;
			break;
		default:
			std::cerr << ": " << "Result too long!" << std::endl << std::endl;
			break;
	}
	return (EXIT_FAILURE);
}

int	RPN::executeOperation(int a, int b, char c)
{
	switch (c)
	{
		case '+':
			return(a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			return (a / b);
		default:
			return (0);
	}
}

int	RPN::checkOperation(int a, int b, char c)
{
	long int	res;
	if (c == '/' && b == 0)
		return (printError(5));
	res = executeOperation(a, b, c);
	if (res < INT_MIN || res > INT_MAX)
		return (printError(6));
	return (EXIT_SUCCESS);
}

int	RPN::printResult()
{
	if (_stackInt.size() > 1)
		return (printError(7));
	std::cout << std::endl << "\033[1;32m*************RESULT*************\033" << std::endl;
	std::cout << ": " << this->_str << " => " << _stackInt.top() << std::endl << std::endl;
	return (EXIT_SUCCESS);
}

int	RPN::parsingInput(std::stack<std::string, std::list<std::string> >reading)
{
	int	oper = 0;
	int	integers = 0;

	while (!reading.empty())
    {
        _stackString.push(reading.top());
		if (reading.size() <= 2)
		{
			if (parseString(reading.top()) == 1)
				return (printError(2));
		}
		if (parseString(reading.top()) == 1)
			oper++;
		else if (parseString(reading.top()) == 2)
			integers++;
		else if (parseString(reading.top()) == 0)
			return (printError(3));
        reading.pop();
    }
	if (integers - oper != 1)
		return (printError(4));
	return (EXIT_SUCCESS);
}

int	RPN::readingInput()
{
	std::stringstream strStream(_str);
    std::string s;
	std::stack<std::string, std::list<std::string> >	reading;

    while (std::getline(strStream, s, ' '))
	{
		if (s.size() > 0)
			reading.push(s);
	}
	if (reading.top().length() != 1 || !isOper(reading.top().at(0)))
		return (printError(1));
	if (parsingInput(reading))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	RPN::execution()
{
	while (!_stackString.empty())
	{
		std::stringstream	ss(_stackString.top());
		long int			num;
		ss >> num;
		if (num == 0 && _stackString.top().size() == 1
			&& _stackString.top().at(0) != '0')
		{
			long int	b;
			long int	a;

			if (_stackInt.size() < 2)
				return (printError(4));
			b = _stackInt.top();
			_stackInt.pop();
			a = _stackInt.top();
			_stackInt.pop();
			if (checkOperation(a, b, _stackString.top().at(0)))
				return (EXIT_FAILURE);
			_stackInt.push(executeOperation(a, b, _stackString.top().at(0)));
			_stackString.pop();
		}
		else
		{
			_stackInt.push(num);
			_stackString.pop();
		}
	}
	return (EXIT_SUCCESS);
}