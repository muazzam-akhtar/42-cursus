#include "PmergeMe.hpp"

void	PmergeMe::printDeques(std::deque<int> &vctr)
{
	for (std::deque<int>::iterator it = vctr.begin(); it != vctr.end(); it++)
		std::cout << *it << std::endl;
}

int	PmergeMe::makePairDeque()
{
	std::deque<int>	tmp;
	int					pairs;

	for (std::deque<int>::iterator i = this->_dequeStore.begin(); i != this->_dequeStore.end(); i++)
		tmp.push_back(*i);
	pairs = tmp.size() / 2;
	for (int i = 0; i < pairs; i++)
	{
		Pair	tmpPair(tmp.at(i * 2), tmp.at((i * 2) + 1));
		if (tmpPair.first < tmpPair.second)
		{
			int	tmp1 = tmpPair.first;
			tmpPair.first = tmpPair.second;
			tmpPair.second = tmp1;
		}
		this->_pairwisedDeques.push_back(tmpPair);
	}
	return ((tmp.size() % 2));
}

int	PmergeMe::divideDeque()
{
	int	rem = makePairDeque();
	return (rem);
}

std::size_t	PmergeMe::sortSubDeque(std::size_t index, bool *status)
{
	if (index == this->_pairwisedDeques.size() - 1)
	{
		*status = true;
		return (EXIT_SUCCESS);
	}
	if (this->_pairwisedDeques.at(index).first > this->_pairwisedDeques.at(index + 1).first)
	{
		Pair	tmp = this->_pairwisedDeques.at(index);
		this->_pairwisedDeques[index] = this->_pairwisedDeques[index + 1];
		this->_pairwisedDeques[index + 1] = tmp;
		if (index > 0)
			sortSubDeque(index - 1, status);
	}
	return (index);
}

int	PmergeMe::lookupLowerBoundDeque(std::deque<int> &v2)
{
	int	num;

	num = 0;
	if (v2.size() == 1)
		num = v2.front();
	else if (v2.size() == 2)
		num = v2.front() > v2.back() ? v2.back() : v2.front();
	else if ((std::lower_bound(v2.begin(), v2.end(), v2.front())) == v2.end())
		num = v2.back();
	else
		num = v2.at((std::lower_bound(v2.begin(), v2.end(), v2.front()) - v2.begin()));
	return (num);
}

int	PmergeMe::mergeDeques(int rem)
{
	std::deque<int>	v2;
	for (std::deque<Pair>::iterator it = this->_pairwisedDeques.begin();
		it != this->_pairwisedDeques.end(); it++)
	{
		this->_sortedDeque.push_back(it->first);
		v2.push_back(it->second);
	}
	if (rem != 0)
		v2.push_back(this->_dequeStore.at(this->_dequeStore.size() - 1));
	while (!v2.empty())
	{
		int	num = lookupLowerBoundDeque(v2);

		this->_sortedDeque.insert((std::lower_bound(this->_sortedDeque.begin(),
			this->_sortedDeque.end(), num) - this->_sortedDeque.begin())
			+ this->_sortedDeque.begin(), num);
		v2.erase(std::find(v2.begin(), v2.end(), num));
	}
	return (EXIT_SUCCESS);
}

int	PmergeMe::sortDeque()
{
	int	rem;
	std::size_t	index = 0;
	bool	status = false;
	rem = divideDeque();
	while (!status)
	{
		index = sortSubDeque(index, &status);
		index++;
	}
	mergeDeques(rem);
	return (EXIT_SUCCESS);
}