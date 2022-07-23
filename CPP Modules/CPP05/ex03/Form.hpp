/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:22:27 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/18 23:43:24 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const std::string &name, int gradeSigned, int gradeExec);
		Form(const Form &src);
		Form	&operator=(const Form &src);
		virtual ~Form(void);
		const std::string	&getName(void) const;
		int			getGradeSigned(void) const;
		int			getGradeExec(void) const;
		bool		isSigned(void) const;
		// bool		beExec(const Bureaucrat &bur);
		bool		beSigned(const Bureaucrat &bur);
		void	checkGrade(void);
		void	checkExecutability(const Bureaucrat &bur) const;
		virtual void	execute(const Bureaucrat &executor) const = 0;
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSigned;
		const int			_gradeExec;
		static const int	lowGrade = 150;
		static const int	highGrade = 1;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form: The Grade is too High");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form: The Grade is too Low");
				}
		};
		class CantExecuteForm : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("The form cannot be executed, either because it wasn't sign"
					"ed, or because the executor has a rank too low");
				}
		};
};

std::ostream	&operator<<(std::ostream &ostr, const Form &src);

#endif