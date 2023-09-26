#include "PmergeMe.hpp"

int	PmergeMe::makePairVectors()
{
	std::vector<int>	tmp;
	int					pairs;

	for (std::vector<int>::iterator i = this->_vectorStore.begin(); i != this->_vectorStore.end(); i++)
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
		this->_pairwiseVectors.push_back(tmpPair);
	}
	return ((tmp.size() % 2));
}

std::size_t	PmergeMe::sortSubVector(std::size_t index, bool* status)
{
	if (index == this->_pairwiseVectors.size() - 1)
	{
		*status = true;
		return (EXIT_SUCCESS);
	}
	if (this->_pairwiseVectors.at(index).first > this->_pairwiseVectors.at(index + 1).first)
	{
		Pair	tmp = this->_pairwiseVectors.at(index);
		this->_pairwiseVectors[index] = this->_pairwiseVectors[index + 1];
		this->_pairwiseVectors[index + 1] = tmp;
		if (index > 0)
			sortSubVector(index - 1, status);
	}
	return (index);
}

void	PmergeMe::printVectors(std::vector<int>& vctr)
{
	for (std::vector<int>::iterator it = vctr.begin(); it != vctr.end(); it++)
		std::cout << *it << std::endl;
}

int	PmergeMe::lookupLowerBound(std::vector<int>& v2)
{
	int	num = 0;

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

int	PmergeMe::mergeVectors(int rem)
{
	std::vector<int>	v2;
	for (std::vector<Pair>::iterator it = this->_pairwiseVectors.begin();
		it != this->_pairwiseVectors.end(); it++)
	{
		this->_sortedVector.push_back(it->first);
		v2.push_back(it->second);
	}
	if (rem != 0)
		v2.push_back(this->_vectorStore.at(this->_vectorStore.size() - 1));
	while (!v2.empty())
	{
		int	num = lookupLowerBound(v2);

		this->_sortedVector.insert((std::lower_bound(this->_sortedVector.begin(),
			this->_sortedVector.end(), num) - this->_sortedVector.begin())
			+ this->_sortedVector.begin(), num);
		v2.erase(std::find(v2.begin(), v2.end(), num));
	}
	return (EXIT_SUCCESS);
}

int	PmergeMe::sortVectors()
{
	int	rem;
	std::size_t	index = 0;
	bool	status = false;
	rem = divideVector();
	while (!status)
	{
		index = sortSubVector(index, &status);
		index++;
	}
	mergeVectors(rem);
	return (EXIT_SUCCESS);
}

int	PmergeMe::divideVector()
{
	int	rem = makePairVectors();
	return (rem);
}