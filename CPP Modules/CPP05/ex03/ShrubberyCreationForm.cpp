/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:35:29 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 16:15:32 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137) , _target("") { std::cout << BLUE << "Shrubbery Creation Form Default Constructor called" << DEFAULT << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137) , _target(target) { std::cout << BLUE << "Shrubbery Creation Form Standard Constructor called" << DEFAULT << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
	: Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << BLUE << "Shrubbery Creation Form Copy Constructor called" << DEFAULT << std::endl;
	src.getName();
	if (this != &src)
		*this = src;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "Can't Copy anything" << std::endl;
	src.getName();
	std::cout << BLUE << "Shrubbery Creation Form Assignment Constructor called" << DEFAULT << std::endl;
	return (*this);
}

const std::string	&ShrubberyCreationForm::getTarget(void) const { return (this->_target); }

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	myfile;
	std::string	filename = this->_target + "_shrubbery";

	this->checkExecutability(executor);
	myfile.open(filename.c_str(), std::ios::out);
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMMM" << GREEN << "WXK00KXXX00KXN" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << GREEN << "WWXXKOooloooooolllooxK" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << GREEN << "XkddolloxxdddxxxdxxxdlldxkKW" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMM" << GREEN << "WXOolddolloddddxxxddddddddddolxX" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMM" << GREEN << "XxolollllloodddddddddddddxxddddldKW" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMM" << GREEN << "WKOklcdxlcdxddddxdddooooodddxxdddddolodx0W" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMM" << GREEN << "NklooldxdddxddxxxxdollllollllllooddoodddolxN" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMM" << GREEN << "NxldxdddxdoooollloddddxxdddxddooollloooldxdcoKW" << DEFAULT << "MMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMM" << GREEN << "W0loxollllloollloddddddddddddddddxdoocodoloolcckW" << DEFAULT << "MMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMM" << GREEN << "WOoodo:lxdddxddddxdddddddddddddodddddxoodxdoddxolxKW" << DEFAULT << "MMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMM" << GREEN << "0loxo:cdxddddddddxxddddddddddoolllldddddddxdddoddocxX" << DEFAULT << "MMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMM" << GREEN << "KoodlcoddddddddddolllodddddddddxxdolloxddddddddoloxdcxW" << DEFAULT << "MMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMM" << GREEN << "WNdcdocoxdddddddddlcoooodddddddddddddxddddddddddxxlcoxloX" << DEFAULT << "MMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMM" << GREEN << "W0dlcodloxdddddxdoclddddddddddddddddddxxdxxdddddddxdlldlcxX" << DEFAULT << "MMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMM" << GREEN << "Xdoxddddddddddxddodxdddddddddddddddddoloollodddddddxdoddlc0" << DEFAULT << "MMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMM" << GREEN << "XdoxdoooddddxdddxddddddddddddddddddddoddddollloddddddddxoldK" << DEFAULT << "MMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMM" << GREEN << "KolxoldxdxddddddddddddxddddddddddddddddddddddooddolodxdddxldN" << DEFAULT << "MMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMM" << GREEN << "WxcddlodddddddddddddxddddxddddddddddddddddddddxxddxdccdxddxldN" << DEFAULT << "MMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMM" << GREEN << "Koodolddxdddddddddddoodddddddddddddddddxdddddddddddxocoxoocl0" << DEFAULT << "MMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMM" << GREEN << "OlddddddxdddddddddxdlodddddddddddddddddodddddddddddddoddooockW" << DEFAULT << "MMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMM" << GREEN << "KoldxxddddddddddddxdcoxdddddddddddddddxlcdxddddoloddddddddxldN" << DEFAULT << "MMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMM" << GREEN << "XdclddxdloxddddddddoclddddddddddddddxdccoddxdddlcdddddddoodK" << DEFAULT << "MMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMM" << GREEN << "Klclooolcodxddddddxoclddddddddddddxo::loddddxl:oddxddxd:dN" << DEFAULT << "MMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMM" << GREEN << "WOlclllllcldxddddddxoldxdxdddddddddc:lodddddl:lddddddlcl0" << DEFAULT << "MMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMM" << GREEN << "WXxcloollodxddxxddxdoloodxdddddol:clddxddooloddddddo;oN" << DEFAULT << "MMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMM" << GREEN << "WOolcccodddddddxdodolc" << DEFAULT << ":cddoo:" << GREEN << ",cooddxddddddxxddddocl0" << DEFAULT << "MMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMM" << GREEN << "WXKKkllodddddoc;:c:" << DEFAULT << ";cOXKK0l,:" << GREEN << "cccoddlcodddxdlcodxX" << DEFAULT << "MMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMM" << GREEN << "WKkxooooddl::::" << DEFAULT << ";ckNMXd:" << GREEN << ":c:;cdddddollllld0NW" << DEFAULT << "MMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMM" << GREEN << "WNNNNWWNd;cllccloc;cll:oKWWMMWNK000XW" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "Xl;lllllllllocc" << DEFAULT << "OMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "0:collllllll:d" << DEFAULT << "NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "Wd;llllllolll0" << DEFAULT << "NNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN "k;:cllllllccoloX" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "O,,:clllllc;:::kW" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "k,;:clollllc;:OW" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "Wd,:clllllll;;0" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "Xl;llllolcll,oW" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "O;:olllolccl;oN" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "Xl,lllloollcc::OW" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "W0l;clc:clllcclc:c0W" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "WKd::cc:;,:llc;,;:;;cON" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "X0OOOOko:clllc:cxkk0KN" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << BROWN << "WKkkkkkOOKW" << DEFAULT << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	myfile.close();
	std::cout << BLUE << "Created the shrug in " << this->_target << "_shrubbery" << DEFAULT << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { std::cout << RED << "Shrubbery Creation Form Destructor called" << DEFAULT << std::endl; }