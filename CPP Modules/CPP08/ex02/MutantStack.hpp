/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:12:33 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/29 01:29:58 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <algorithm>
#include <stack>
#include <iostream>
template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(void) {};
		MutantStack<T>(const MutantStack<T> &src) { *this = src; };
		~MutantStack(void) {};
		MutantStack<T> &operator=(const MutantStack<T> &src) { (void)src; };
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void) { return (this->c.begin()); };
		iterator	end(void) { return (this->c.end()); };
};

#endif
