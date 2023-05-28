/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:13:37 by wismith           #+#    #+#             */
/*   Updated: 2023/05/11 14:51:40 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.hpp"

using namespace ft;

parser::parser() : cmds() {}

parser::~parser() {}

void							parser::pRecv(const std::string &cmd)
{
	std::string	str = cmd;
	size_t	pos = str.npos;

	while ((pos = str.find('\r', pos + 1)) != str.npos)
		str.erase(pos, 1);

	std::stringstream			ss(str);
	std::string					line;

	while (!ss.eof())
	{
		getline(ss, line, '\n');
		this->cmds.push_back(line);
	}
}

void							parser::printCmds(std::vector<std::string> vec)
{
	std::cout << std::endl;
	for (size_t i = 0; i != vec.size(); i++)
		std::cout << i << ": " << vec[i] << std::endl;
}

/**	@brief Command used to clear the vector containing the parsed commands,
 * 			allowing the next commands to be pushed into the vector after
 * 			POLLIN.
*/
void							parser::clear()
{
	this->cmds.clear();
}

/** @brief retrieves the vector of commands
*/
std::vector<std::string>		&parser::getCmds()
{
	return (this->cmds);
}

/** @brief More than one command may be received at a time.
 * 			This function returns each command one at a time
 * 			with arguments parsed into vector.
 * @note argument is the index for the line command is on.
*/
std::vector<std::string>		parser::getCmdSec(size_t i)
{
	std::stringstream			ss(this->cmds[i]);
	std::vector<std::string>	indi_cmd;
	std::string					word;

	while (!ss.eof())
	{
		getline(ss, word, ' ');
		indi_cmd.push_back(word);
	}
	return (indi_cmd);
}
