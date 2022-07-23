/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:09:47 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 16:10:40 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		const std::string	&getTarget(void) const;
		virtual void	execute(const Bureaucrat &executor) const;
		virtual ~RobotomyRequestForm(void);
	private:
		const std::string	_target;	
};
#endif