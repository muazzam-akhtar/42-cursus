/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:54:16 by wismith           #+#    #+#             */
/*   Updated: 2023/05/26 14:33:12 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bot.hpp"

using namespace ft;

bool		g_bot_run = true;

bot::bot () : fd(0), pfd(), buffer(), pars(), msgs(), backlog(),
	chan(), sendingCmd(false) {}

bot::~bot() {}

void	bot::init (int port)
{
	struct sockaddr_in serv_addr;

    if ((this->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        exit (1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{ exit (1); }

    if (connect(this->fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{ exit (1);}

	this->pfd = NPOLL(this->fd);
	this->catch_signals();
}

void	bot::Connect(std::string pass)
{
	std::string	cmd;

	cmd += "CAP LS\r\n";
	cmd += "CAP END\r\n";
	cmd += "PASS " + pass + "\r\n";
	cmd += "NICK bot\r\n";
	cmd += "USER bot bot localhost :ircbot\r\n";
	cmd += "JOIN #BotChat\r\n";
	this->chan.push_back("#BotChat");

	poll(&this->pfd, 1, -1);
	if (this->pfd.revents & POLLOUT)
		send(this->fd, cmd.c_str(), cmd.size(), 0);
}

void	bot::run ()
{
	std::string quit = "QUIT :bot is leaving!\r\n";

	while (g_bot_run)
	{
		poll(&this->pfd, 1, -1);

		if (this->pfd.revents & POLLOUT && this->backlog.size())
		{
			std::string	msg;

			if (!sendingCmd)
			{
				for (size_t i = 0; i < this->chan.size(); i++)
					msg += "PRIVMSG "
						+ this->chan[i] + " :"
						+ this->backlog.front() + "\r\n";
			}
			else
				msg += this->backlog.front();
			send(this->fd, msg.c_str(), msg.size(), 0);
			this->backlog.erase(this->backlog.begin());
			this->sendingCmd = false;
		}

		usleep (120000);

		if (this->pfd.revents & POLLIN)
		{
			pars.pRecv( Read(this->fd) );
			for (size_t j = 0; j < pars.getCmds().size(); j++)
				if (pars.getCmdSec(j)[0].size())
					this->selCmd(pars.getCmdSec(j));
		}
		pars.clear();
	}
	if (this->pfd.revents & POLLOUT)
		send(this->fd, quit.c_str(), quit.size(), 0);
    close(this->fd);
}

std::string	bot::toLower(const std::string str)
{
	char	nstr[str.size()];

	for (size_t	i = 0; i < str.size(); i++)
		nstr[i] = tolower(str.c_str()[i]);
	std::string res(nstr);
	return (res);
}

void		bot::selCmd(std::vector<std::string> cmd)
{
	if (cmd.size() < 3)
		return ;
	if (cmd[1] == "PRIVMSG"
		&& this->toLower(cmd[3]) == ":hello")
		this->backlog = this->msgs;
	else if (cmd[1] == "QUIT")
		this->backlog.push_back("Bye Bye!");
	else if (cmd[1] == "INVITE")
	{
		cmd[3].erase(cmd[3].begin());
		
		for (size_t i = 0; i < this->chan.size(); i++)
			if (this->chan[i] == cmd[3])
				return ;
		this->backlog.push_back("JOIN " + cmd[3] + "\r\n");
		this->chan.push_back(cmd[3]);
		this->sendingCmd = true;
	}
	else if (cmd[1] == "KICK")
	{
		this->backlog.push_back("JOIN " + cmd[2] + "\r\n");
		this->sendingCmd = true;
	}
}

std::string	bot::Read(int fd)
{
	char	buff[513];
	std::string	res;
	ssize_t bits = recv(fd, buff, 512, 0);
	if (!bits || bits > 512)
		return (std::string());

	buff[bits] = '\0';
	std::string	str(buff);
	if (bits > 0)
	{
		if (str.find('\n') == str.npos && str.find('\r') == str.npos)
			this->buffer += str;
		else
		{
			res = this->buffer + str;
			this->buffer.clear();
			return (res);
		}
	}
	return (std::string());
}

void	bot::retrieveMsgs()
{
	std::ifstream	infile(MSGFILE.c_str());

	for (int i = 0; i < 2; i++)
		this->msgs.push_back(std::string(" -- "));
	if (infile.good())
		for (std::string line; getline(infile, line);)
			this->msgs.push_back(line);
	else
	{
		std::cout << "No file exists!\n";
		return ;
	}
	for (int i = 0; i < 2; i++)
		this->msgs.push_back(std::string(" -- "));
	infile.close();
}

void	sighandlr(int signum)
{
	(void) signum;
	g_bot_run = false;
	std::cout << "\nStopping bot!" << std::endl;
}

void	bot::catch_signals()
{
	signal(SIGINT, sighandlr);
	signal(SIGQUIT, sighandlr);
	signal(SIGHUP, sighandlr);
	signal(SIGTERM, sighandlr);
	signal(SIGPIPE, sighandlr);
}
