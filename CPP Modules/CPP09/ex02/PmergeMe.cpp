#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char** str)
{
	int	i = 1;

	while (str[i])
	{
		this->_str.push_back(str[i]);
		i++;
	}
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_dequeStore = other._dequeStore;
		this->_pairwisedDeques = other._pairwisedDeques;
		this->_pairwiseVectors = other._pairwiseVectors;
		this->_sortedDeque = other._sortedDeque;
		this->_sortedVector = other._sortedVector;
		this->_storeNumbers = other._storeNumbers;
		this->_str = other._str;
		this->_vectorStore = other._vectorStore;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

int	PmergeMe::validInputs(const std::string& s)
{
	std::string	str = "0123456789";

	if (s.find_first_not_of(str) < str.size() || s.compare("2147483647") == 1)
		return (0);
	return (1);
}

int	PmergeMe::printError(int code)
{
	std::cerr << std::endl << "\033[1;31m*************ERROR*************\033" << std::endl;
	if (code == 0)
		std::cerr << ": " << "Duplicate Inputs!" << std::endl << std::endl;
	if (code == 1)
		std::cerr << ": " << "Invalid Input!" << std::endl << std::endl;
	return (EXIT_FAILURE);
}

double	PmergeMe::getTime()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec);
}

void	PmergeMe::printResult(double start, double end, int type)
{
	std::cout << "\033[1;31m\nBefore:\t\033";
	std::cout << "\033[1;33m\033";
	if (type == 0)
	{
		for (std::vector<int>::iterator it = this->_vectorStore.begin(); it != this->_vectorStore.end() /*&& (it - this->_vectorStore.begin() < 10)*/; it++)
			std::cout << *it << " ";
		std::cout << "\033[1;31m\n\nAfter:\t\033";
		std::cout << "\033[1;33m\033:";
		for (std::vector<int>::iterator it = this->_sortedVector.begin(); it != this->_sortedVector.end() /*&& (it - this->_sortedVector.begin() < 10)*/; it++)
			std::cout << *it << " ";
		std::cout << "\033[1;32m\033";
		std::cout << "\n: Time to process a range of " << this->_vectorStore.size() << " elements with std::vector : " << (end - start) << " us\n";
		std::cout << "\033[1;34m\n***********************************************************************************************************************************************************************************************************************\n\033";
	}
	else
	{
		for (std::deque<int>::iterator it = this->_dequeStore.begin(); it != this->_dequeStore.end()/* && (it - this->_dequeStore.begin() < 10)*/; it++)
			std::cout << *it << " ";
		std::cout << "\033[1;31m\n\nAfter:\t\033";
		std::cout << "\033[1;33m\033:";
		for (std::deque<int>::iterator it = this->_sortedDeque.begin(); it != this->_sortedDeque.end() /*&& (it - this->_sortedDeque.begin() < 10)*/; it++)
			std::cout << *it << " ";
		std::cout << "\033[1;32m\033";
		std::cout << "\n: Time to process a range of " << this->_dequeStore.size() << " elements with std::deque : " << (end - start) << " us\n";
		std::cout << "\033[1;34m\n***********************************************************************************************************************************************************************************************************************\n\033";
	}
}

int	PmergeMe::execution()
{
	double	start;
	double	end;

	start = getTime();
	for (std::vector<int>::iterator it = _storeNumbers.begin(); it != _storeNumbers.end(); it++)
		this->_vectorStore.push_back(*it);
	if (this->_vectorStore.size() <= 1)
	{
		std::cerr << "Error: Unsorted Sequences needs more than one element\n";
		return (EXIT_SUCCESS);
	}
	sortVectors();
	end = getTime();
	printResult(start, end, 0);
	start = getTime();
	for (std::vector<int>::iterator it = _storeNumbers.begin(); it != _storeNumbers.end(); it++)
		this->_dequeStore.push_back(*it);
	sortDeque();
	end = getTime();
	printResult(start, end, 1);
	return (EXIT_SUCCESS);
}

int	PmergeMe::parseInput(void)
{
	std::vector<int>	_list;
	while (!this->_str.empty())
	{
		std::stringstream	sstream(this->_str.back());
		long int			num;

		sstream >> num;
		if (num < 0 || (num == 0 && this->_str.back().size() > 1) || !validInputs(this->_str.back()))
			return (printError(1));
		if (std::find(_list.begin(), _list.end(), num) != _list.end())
			return (printError(0));
		_list.insert(_list.begin(), num);
		this->_str.pop_back();
	}
	_storeNumbers = _list;
	return (EXIT_SUCCESS);
}