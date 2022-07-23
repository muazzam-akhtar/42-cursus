/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:22:17 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/27 12:11:02 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

# include <iomanip>

template<typename T>
class Array
{
	public:
		Array<T>(void) : _size(0), _array(NULL), check(false) { std::cout << "Empty Constructor called" << std::endl; }
		Array<T>(const unsigned int size) : _size(size)
		{
			this->_array = NULL;
			std::cout << "Size Constructor called" << std::endl;
			if (size < 0)
				throw std::overflow_error("Index out of bounds");
			this->_array = new T[size];
			this->check = true;
		}
		~Array<T>(void)
		{
			std::cout << "Destructor called" << std::endl;
			if (this->_size > 0)
				delete [] this->_array;
		}
		T&	operator[](long long int i)
		{
			if (i >= this->_size || i < 0)
				throw std::overflow_error("Index out of range");
			return(this->_array[i]);
		}
		const T	&operator[](const long long int i) const
		{
			if (i >= this->_size || i < 0)
				throw std::overflow_error("Index out of range");
			return(this->_array[i]);
		}
		Array<T>(const Array<T> &src)
		{
			this->check = false;
			std::cout << "Copy Constructor called" << std::endl;
			*this = src;
		}
		Array<T>	&operator=(const Array <T> &src)
		{
			std::cout << "Assignment Constructor called" << std::endl;
			if (this != &src)
			{
				if (this->check == true && this->_size > 0)
					delete [] this->_array;
				this->_size = src.size();
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = src._array[i];
				this->check = true;
			}
			return (*this);
		}
		unsigned int	size(void) const
		{
			return (this->_size);
		}
	private:
		unsigned int	_size;
		T	*_array;
		bool	check;
};

#endif