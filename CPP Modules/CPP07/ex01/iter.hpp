/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 03:00:32 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/25 16:35:15 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void	iter(T *a, unsigned int length, void (*f)(const T &))
{
	for(unsigned int i = 0; i < length; i++)
	{
		f(a[i]);
	}
}
#endif