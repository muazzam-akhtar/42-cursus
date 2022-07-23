/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:23:14 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/28 00:18:17 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <algorithm>
#include <iostream>
#include <exception>

template<typename T>

typename T::iterator	easyfind(T &container, int i)
{
	typename T::iterator	result = find(container.begin(), container.end(), i);
	if (result == container.end())
	{
		throw(std::out_of_range("No occurence found"));
	}
	return (result);
}

#endif