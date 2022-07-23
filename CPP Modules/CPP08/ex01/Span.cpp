/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:07:06 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/29 01:06:47 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _size(0) { std::cout << "Default Constructor called" << std::endl; }

Span::Span(unsigned int size) : _size(size), _vectors(0)
{
	std::cout << "Standard Constructor called" << std::endl;
}

Span::Span(const Span &src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

Span	&Span::operator=(const Span &src)
{
	std::cout << "Assignment operator overload called" << std::endl;
	if (this != &src)
	{
		this->_size = src._size;
		this->_vectors = src._vectors;
	}
	return (*this);
}

unsigned int	Span::size(void) const
{
	return (this->_vectors.size());
}

void	Span::addNumber(const int num)
{
	if (this->_size == this->size())
	{
		throw(std::out_of_range("No Space left"));
	}
	this->_vectors.push_back(num);
}

int	Span::shortestSpan(void)
{
	int	min = -1;
	int	check = 0;
	if (this->_vectors.size() == 0 || this->_vectors.size() == 1)
		throw(std::out_of_range("No Span can be found"));
	std::vector<int>	tmp;
	tmp = this->getVectors();
	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator i = tmp.begin(); i != tmp.end(); i++)
	{
		if (i != tmp.begin())
		{
			check = *(i) - *(i - 1);
			if (min == -1)
				min = *(i) - *(i - 1);
			else if (check < min)
				min = check;
		}
		/* code */
	}
	return (min);
}

int	Span::longestSpan(void)
{
	int	max = -1;
	int	check = 0;
	if (this->_vectors.size() == 0 || this->_vectors.size() == 1)
		throw(std::out_of_range("No Span can be found"));
	std::vector<int>	tmp;
	tmp = this->getVectors();
	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator i = tmp.begin(); i != tmp.end(); i++)
	{
		if (i != tmp.begin())
		{
			check = *(i) - *(i - 1);
			if (max == -1)
				max = *(i) - *(i - 1);
			else if (check > max)
				max = check;
		}
		/* code */
	}
	return (max);
}

Span::~Span(void) { std::cout << "Destructor called" << std::endl; }

std::vector<int>	Span::getVectors(void) const { return (this->_vectors); }

std::ostream	&operator<<(std::ostream &ostr, const Span &src)
{
	std::vector<int>	v = src.getVectors();
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		ostr << *i << " ";
	}
	return (ostr);
}