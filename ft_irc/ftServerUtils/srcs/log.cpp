/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:50:54 by wismith           #+#    #+#             */
/*   Updated: 2023/05/11 15:56:09 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/log.hpp"

/** @brief Name Constructor: inits all values
 * 	@note takes a file name as parameter. File does not have
 * 			to be an existing file.
 */
ft::log::log (const std::string &name) : lineNum(0), Name(name),
	Content(), lastLog() {}

/** @brief Destructor*/
ft::log::~log() {}

/** @brief removes any '\r' characters before splitting
 * 			by '\n' and pushing each segment into the nextLog list,
 * 			ready to be pushed to the log file.
*/
void			ft::log::parsLog(const std::string &msg)
{
	std::string	str = msg;
	size_t	pos = -1;

	while ((pos = str.find('\r', pos + 1)) != str.npos)
		str.erase(pos, 1);

	std::stringstream			ss(str);
	std::string					line;

	pos = -1;
	while (!ss.eof())
	{
		getline(ss, line, '\n');
		this->nextLog.push_back(line);
	}
}

/** @brief pushLog method used to push a new log message into chosen
 * 			log file. If Log file exists prior to log object construction
 * 			content within will be replaced with new content upon initial 
 * 			call to method, afterwhich content will simply be added below
 * 			current content.
*/
void	ft::log::pushLog(const std::string &msg)
{
	std::string	lnStr;
	std::ofstream	outfile(this->Name.c_str());
	this->lastLog = msg;
	this->parsLog(msg);

	while (this->nextLog.size())
	{
		this->lineNum++;
		this->Content += (lnStr << this->lineNum) + " : ";
		this->Content += this->nextLog.front();
		this->Content += "\n";
		this->nextLog.pop_front();
	}
	if (outfile.good())
	{
		outfile << this->Content;
		outfile << "\n";
	}
	outfile.close();
}

/** @brief returns a string of the log file's name */
std::string	ft::log::getFileName() const
{
	return (this->Name);
}

/** @brief returns a string of the last logged message */
std::string	ft::log::getLastLog() const
{
	return (this->lastLog);
}

/** @brief returns an int of number of lines logged within file */
int			ft::log::getNumLines() const
{
	return (this->lineNum);
}

/** @brief << operator overload used to push new message into
 * 			the log file.
*/
ft::log	&operator<<(ft::log &l, std::string const &msg)
{
	l.pushLog(msg);
	return (l);
}
