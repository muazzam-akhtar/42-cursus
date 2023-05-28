/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:45:38 by wismith           #+#    #+#             */
/*   Updated: 2023/05/11 18:15:29 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.hpp"

bool	ft::g_server_run = true;

/** @brief Port and Password Constructor
 * 		initializes values to default settings
*/
ft::server::server(int nport, std::string pw) : network(pw), state(SHUTDOWN), opt(1),
				port(nport), lstn() {}

/** @brief Destructor 
 * @note closes any open file descriptors 
*/
ft::server::~server()
{
	this->log << "Closing client fds\n";
	for (size_t i = 0; i < this->pfds.size(); i++)
		(i ? close (this->pfds[i].fd) : (int) i);
	this->log << "Shutting Down Server";
	std::cout << "Shutting Down Server" << std::endl;
}

/** @brief server init calls lstnInit to initialize the listener,
 * 			pushes a new struct pollfd with values initialized with the macro NPOLL,
 * 			if an exception hasn't been thrown yet, the state is set to RUNNING
*/
void	ft::server::init()
{
	ft::catch_signals();
	this->log << "initializing the listener";
	std::cout << "Initializing Listener" << std::endl;
	this->lstnInit();
	this->pfds.push_back(NPOLL(this->lstn.getSock()));
	this->state = RUNNING;
}

/** @brief lstnInit initializes the listener with the port
 * 			Taken as param for constructor.
 * 			Inits sockaddr_in.
 * 			Sets the socket to non blocking.
 * 			Binds the socket to fd.
 * 			Listens with the socket.
*/
void	ft::server::lstnInit()
{
	this->opt = 1;
	this->log << this->lstn.setInfo(AF_INET, SOCK_STREAM, IPPROTO_TCP, this->port, INADDR_ANY);
	this->log << this->lstn.setSockProto(SOL_SOCKET, SO_REUSEADDR, this->opt);
	this->log << this->lstn.setSockProto(SOL_SOCKET, SO_REUSEPORT, this->opt);
	this->log << this->lstn.nonBlocking();
	this->log << this->lstn.BindConnect();
	this->log << this->lstn.ListenConnect();
}

/** @brief registers a new  client
 * 	@note new client is stored within a std::map
 * 			with key values being the file descriptor returned
 * 			by accept.
 * 		Each client is associated with a pollfd structure stored
 * 			within a vector.
*/
void	ft::server::regNewClient()
{
	std::string	fdStr;
    int 		fd = -1;
    int 		addrlen = 0;
    struct 		sockaddr_in address;
    memset(&address, 0, sizeof(address));
	
	this->log << "Client Attempting to Connect";
    if ((fd = accept(this->lstn.getSock(), (sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
		this->log << "Client unable to connect!\n";
	else
	{
		this->clients[fd] = ft::client(fd);
		this->pfds.push_back(NPOLL(fd));
		this->log << "Accepting new client, fd : " + (fdStr << fd);
	}
}

void	ft::server::receiveCmds(size_t i)
{
	std::string	cmd;

	cmd << M_CLIENT(i);
	this->log << " << " + cmd;
	this->pRecv(cmd);
	for (size_t j = 0; j < this->getCmds().size(); j++)
	{
		if (this->getCmdSec(j)[0].size())
		{
			this->printCmds(this->getCmdSec(j));
			this->selCmd(this->getCmdSec(j), i);
		}
	}
}

void	ft::server::sendReply(size_t i)
{
	std::string	reply;
	std::string	rep;
	ft::client	&client = M_CLIENT(i);

	while (client.getBacklogSize())
	{
		rep = client.retrBacklog();
		reply += rep;
		this->log << " >> " + rep;
	}
	reply >> client;
}

bool	ft::server::rmClient(size_t i)
{
	close (pfds[i].fd);
	this->clients.erase(pfds[i].fd);
	this->pfds.erase(pfds.begin() + i);
	return (true);
}

void	ft::server::run()
{
	std::string	cmd;
	bool		clientRM = false;

	std::cout << "Server Running ..." << std::endl;

	/** @brief main server loop, will run until a specific
	 * 			signal is received, or the state changes.
	*/
	while (ft::g_server_run && this->state)
	{
		/** @brief checks the array of fds in the vector to see
		 * 			if they are ready to read or write to.
		*/
		poll(this->pfds.data(), this->pfds.size(), -1);

		/** @brief 0'th index of pfds is the master socket/fd.
		 * 			Checking POLLIN of the master fd establishes
		 * 			whether a client is trying to connect, and
		 * 			registers new client with regNewClient;
		*/
		if (this->pfds[0].revents & POLLIN)
				this->regNewClient();

		/** @brief loops through each index of the pfds vector
		 * 			checking for POLLIN and POLLOUT of each client
		*/
		for (size_t i = 1; i < this->pfds.size(); i++)
		{
			/** @brief finds the right client */
			ft::client	&client = M_CLIENT(i);

			/** @brief checks whether client is ready to write
			 * 			to using the following :
			 * 				this->pfds[i].revents & POLLOUT
			*/
			if (this->pfds[i].revents & POLLOUT)
				this->sendReply(i);

			/** @brief sending welcome message when
			 * 			a client gets registered.
			 * 			The welcome class is similar to a command
			 * 				in that it inherits from cinterface, however
			 * 				it is not a command.
			*/
			if ( !client.getReg().welcomeSent
					&& client.is_registered() )
				client.getReg().welcomeSent
					= ft::welcome( this->clients,
									this->pfds,
									this->password ).Welcome( client );

			/** @brief a client that requests /quit command is
			 * 			marked for deletion in the quit command.
			 * 			The removal happens when a call to rmClient
			 * 			method is made with index to client.
			*/
			if (client.getIsMarkForDel())
			{
				clientRM = this->rmClient(i);
				break ;
			}

			/** @brief section to receive command/string from
			 * 			client fd. 
			 * 			If the following evaluates to true that
			 * 			signifies the client is ready to read from :
			 * 				this->pfds[i].revents & POLLIN
			*/
			if (!clientRM && this->pfds[i].revents & POLLIN)
				this->receiveCmds(i);

			clientRM = false;

			/** @brief clears the cmds vector of the command received
			 * 			and it's arguments.
			*/
			this->clear();
		}
	}
}

/** @brief Non-members */

void	sighandlr(int signum)
{
	(void) signum;
	ft::g_server_run = false;
	std::cout << "\nStopping server!" << std::endl;
}

void	ft::catch_signals()
{
	signal(SIGINT, sighandlr);
	signal(SIGQUIT, sighandlr);
	signal(SIGHUP, sighandlr);
	signal(SIGTERM, sighandlr);
	signal(SIGPIPE, sighandlr);
}
