/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:49:12 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/28 13:51:36 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
	private:
		unsigned int _size;
		std::vector<int>	_vectors;
	public:
		Span(void);
		~Span(void);
		Span(unsigned int size);
		Span(const Span &src);
		Span	&operator=(const Span &src);
		void	addNumber(const int  num);
		unsigned int	size(void) const;
		std::vector<int>	getVectors(void) const;
		int	shortestSpan(void);
		int	longestSpan(void);
};

std::ostream	&operator<<(std::ostream &ostr, const Span &src);
#endif