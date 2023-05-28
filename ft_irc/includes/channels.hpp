/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:43:42 by wismith           #+#    #+#             */
/*   Updated: 2023/05/10 19:52:55 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CHANNELS_HPP
# define CHANNELS_HPP

# include <vector>
# include <map>
# include <string>

#include "client.hpp"

# define IS_OPP bool

namespace ft
{
	class channels
	{
		private :
			std::vector<int>			fds;
			std::string					_chan;
			std::string					_pass;
			int							_len;
			int							_limit;
			std::string					_topic;
			bool						_is_topic;
			bool						_invite_only;
			std::vector<std::string>	_invited_users;
			std::map<CLIENT_FD, CLIENT>	&clients;
			std::map<CLIENT_FD, IS_OPP> opps;

		public :
										channels( std::map<CLIENT_FD, CLIENT> &client );
										channels( const channels &other );
										~channels();

			channels					&operator=(const channels &);

			std::vector<int>			&getFds();
			void						setChannelName( const std::string & );
			void						setChannelPass( const std::string & );
			void						op( int fd );
			bool						&getOp(int fd);
			void						add_clients( int fd );
			void						kick_client( std::string &, std::string &);
			int							get_length( void );
			void						print_clients();
			std::string					get_pass();
			std::string					getChannelName();
			void						sendToAll( const std::string &, std::map<int, CLIENT> &, int );
			void						set_mode( const std::string & );
			std::string					get_mode();
			void						set_topic( const std::string & );
			std::string					get_topic();
			std::string					get_users();
			bool						is_user( const std::string & );
			void						add_op( const std::string & );
			void						remove_op( const std::string & );
			int							string_to_int( const std::string & );
			void						set_invite_only( bool );
			bool						get_invite_only();
			void						set_limit( int );
			int							get_limit();
			void						set_is_topic( bool );
			bool						get_is_topic();
			void						add_invited_user( const std::string & );
			bool						is_invited( const std::string & );
	};
};

#endif