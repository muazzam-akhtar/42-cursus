/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:28:03 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/25 01:55:40 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
# include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename T>
T min(T &a, T&b)
{
	return (a < b ? a : b);
}

template <typename T>
T max(T &a, T&b)
{
	return (a > b ? a : b);
}

#endif