/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:18:20 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/22 11:36:18 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		const std::string	&getTarget(void) const;
		virtual void	execute(const Bureaucrat &executor) const;
		virtual ~ShrubberyCreationForm(void);
	private:
		const std::string	_target;
};
#endif