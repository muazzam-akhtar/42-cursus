/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:53:57 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 14:59:21 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDNTIALPARDONFORM_HPP
#define PRESIDNTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		const std::string	&getTarget(void) const;
		virtual void	execute(const Bureaucrat &executor) const;
		virtual ~PresidentialPardonForm(void);
	private:
		const std::string	_target;	
};

#endif