#include "../../includes/commands.hpp"

using namespace ft;

dcc::dcc( std::map<CLIENT_FD, CLIENT> &c, std::vector<pollfd> &p, std::string &pw ) :
	ft::cinterface( c, p, pw ) {}

dcc::~dcc() {}

std::string	dcc::getClientDir()
{
	char	s[100];
	std::string	cwd;
	std::string	_dir = CLIENTDIR;
	chdir("/");
	_dir = _dir.append("/");
	_dir = _dir.append(getenv("USER"));
	chdir(_dir.c_str());
	cwd = getcwd(s, 100);
	cwd = cwd.append("/");
	return (cwd);
}

void	dcc::sendingData(ft::client &clientSender, ft::client	&clientReceiver, const std::vector<std::string> &cmds )
{
	std::string	receivingFile;
	std::string	filename = getClientDir();
	filename += cmds[3];
	std::string	tmp = filename.substr(0, filename.find_last_of('/') + 1);
	chdir("/");
	chdir(tmp.c_str());
	filename = filename.substr(filename.find_last_of('/') + 1, filename.length());
	receivingFile = filename;
	std::ifstream	file(filename.c_str());
	if (file.good())
	{
		std::map<int, int>	tmp;
		tmp[clientSender.getFd()] = clientReceiver.getFd();
		if ((this->_sender[tmp] == true) && this->_fileSending[tmp] == receivingFile)
			clientSender.addBacklog("You have already sent a file request!\r\n");
		else
		{
			this->_fileSending[tmp] = receivingFile;
			for (std::string line; getline(file, line);)
				this->_data[tmp] = this->_data[tmp].append(line);
			clientSender.addBacklog("File is offered to " + cmds[2] + "\r\n");
			this->_data[tmp] = this->_data[tmp].substr(0, this->_data[tmp].length() - 1);
		}
		this->_sender[tmp] = true;
		file.close();
		return ;
	}
	clientSender.addBacklog("File does not exist \r\n");
}

void	dcc::retrievingData(ft::client &clientSender, ft::client	&clientReceiver, const std::vector<std::string> &cmds )
{
	std::map<int, int>	getPair;
	getPair[clientSender.getFd()] = clientReceiver.getFd();
	if (this->_sender[getPair] == true)
	{
		if (_fileSending[getPair] != cmds[3])
		{
			clientReceiver.addBacklog("File not offered\r\n");
			return ;
		}
		std::string	rootDir = getClientDir();
		std::ofstream	outFile(_fileSending[getPair].c_str());
		if (outFile.good())
			outFile << this->_data[getPair];
		outFile.close();
		clientReceiver.addBacklog("File received successfully from " + cmds[2] + "\r\n");
		this->_sender[getPair] = false; 
		_fileSending[getPair] = "";
	}
	else
		clientReceiver.addBacklog("You don't have any file requests!\r\n");
}

void	dcc::exec( int i_pfds, const std::vector<std::string> &cmds )
{
	if (cmds.size() == 4)
	{
		std::string	receivingFile;
		ft::client	nick;
		std::size_t	it;
		std::cout << cmds[2] << std::endl;
		for (it = 0; it < this->pfds.size(); it++)
		{
			if (M_CLIENT(it).getNick() == cmds[2])
			{
				nick = M_CLIENT(it);
				break;
			}
		}
		if (it != this->pfds.size())
		{
			if (M_CLIENT(i_pfds).getFd() == nick.getFd())
			{
				M_CLIENT(i_pfds).addBacklog("That's Funny!\r\n");
				return ;
			}
			if (cmds[1] == "SEND")
				sendingData(M_CLIENT(i_pfds), nick, cmds);
			else if (cmds[1] == "GET")
				retrievingData(nick, M_CLIENT(i_pfds), cmds);
		}
		else
			M_CLIENT(i_pfds).addBacklog("Client does not exist\r\n");
	}
	else
		M_CLIENT(i_pfds).addBacklog("Expected 4 arguments\r\n");
}