/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:14:03 by wismith           #+#    #+#             */
/*   Updated: 2023/05/09 00:25:08 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PARSER_HPP
# define PARSER_HPP

# include <string>
# include <vector>
# include <sstream>
# include <iostream>

namespace ft
{
	class parser
	{
		private :
		std::vector<std::string>		cmds;

		public :
										parser();
										~parser();

			void						pRecv(const std::string &str);
			void						printCmds(std::vector<std::string> vec);
			void						clear();

			std::vector<std::string>	&getCmds();
			std::vector<std::string>	getCmdSec(size_t i);
	};
};

#endif