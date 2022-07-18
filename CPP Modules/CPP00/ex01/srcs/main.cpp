/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:10:52 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/06 17:53:37 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

void	menu()
{
	std::cout<<"\033[0;31m\033[1m			██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗\n";
	std::cout<<"			██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝\n";
	std::cout<<"			██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝ \n";
	std::cout<<"			██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗ \n";
	std::cout<<"			██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗\n";
	std::cout<<"			╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝\n";
	std::cout<<"			                                                                             \n\033[0m";
}

void	display(void)
{
	std::cout<<"Available Commands:\n";
	std::cout<<"1: ADD\t";
	std::cout<<"2: SEARCH\t";
	std::cout<<"3: EXIT\n";
}

int main(int argc, char **argv)
{
	std::string	cmd;
	PhoneBook book;

	(void)argv;
	if (argc != 1)
	{
		std::cout << "Run with executable ./phonebook" << std::endl;
		return (0);
	}
	menu();
	display();
	while (getline(std::cin, cmd, '\n'))
	{
		if (cmd == "ADD")
			book.add_contact();
		else if (cmd == "SEARCH")
			book.showPhonebook();
		else if (cmd == "EXIT")
			break ;
		display();
	}
	return (0);
}