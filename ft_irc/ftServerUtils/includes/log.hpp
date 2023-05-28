/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:36:23 by wismith           #+#    #+#             */
/*   Updated: 2023/05/11 15:22:56 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LOG_HPP
# define LOG_HPP

# include <iostream>
# include <string>
# include <list>

namespace ft
{
	class log
	{
		private :
			int 			lineNum;
			std::string		Name; 		//!file name
			std::string		Content;	//! file content
			std::string		lastLog;	//! last log message
			std::list<std::string>	nextLog;
			
			void			parsLog(const std::string &msg);

		public :
			//! Constructor & Destructor
							log (const std::string &name);
							~log ();

			//! file modifier
			void			pushLog(const std::string &msg);
			
			//! Getters
			std::string		getFileName() const;
			std::string		getLastLog() const;
			int				getNumLines() const;
	};
};

/** @brief operator to push new message into the log file 
 * 	@note e.g.:
 * @note this->log << "My log message";
*/
ft::log	&operator<<(ft::log &l, std::string const &msg);

# include "ServerUtility.hpp"

#endif