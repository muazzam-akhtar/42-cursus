/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:46:47 by wismith           #+#    #+#             */
/*   Updated: 2023/05/20 13:14:36 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef WELCOME_HPP
# define WELCOME_HPP

# include "commands.hpp"

namespace	ft
{
	class welcome : public ft::cinterface
	{
		public :
						welcome (std::map<CLIENT_FD, CLIENT> &,
									std::vector<pollfd> &,
									std::string &);
						~welcome ();
			
			bool		Welcome(ft::client &c);
			void		msgOfTheDay(ft::client &c);
			std::string	randomMsgOfTheDay();

		private :
			void 		exec(int i_pfds, const std::vector<std::string> &cmds);
	};
};

#endif