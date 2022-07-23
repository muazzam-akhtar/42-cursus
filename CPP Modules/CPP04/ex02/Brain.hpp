/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:05:03 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/17 14:39:54 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &other);
		Brain&operator=(const Brain &other);
		~Brain(void);
		void	setIdeas(std::string idea);
		std::string	ideas[100];
};
#endif