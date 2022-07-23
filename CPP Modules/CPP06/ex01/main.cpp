/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:42:01 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/24 20:56:18 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

typedef struct	s_Data
{
	std::string	data;
}				Data;

uintptr_t	serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data	*deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
int	main( void )
{
	{
		Data		*ptr = new Data;
		Data		*new_ptr;
		uintptr_t	raw;
		ptr->data = "Hi, how's going";
		raw = serialize(ptr);
		new_ptr = deserialize(raw);
		std::cout << "new_ptr->data = " << raw << std::endl;
		std::cout << "new_ptr->data = " << new_ptr->data << std::endl;
		delete ptr;
	}
	{
		int	*p = new int(65);
		char	*ch = reinterpret_cast<char*>(p);
		std::cout << ch << std::endl;
		std::cout << *p << std::endl;
		delete p;
	}
	return (0);
}