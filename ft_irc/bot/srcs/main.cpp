/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:46:59 by wismith           #+#    #+#             */
/*   Updated: 2023/05/26 14:32:36 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bot.hpp"

int	main(int argc, char **argv)
{
	int			port;
	std::string	pw;

	if (argc != 3)
	{
		std::cerr << "Incorrect num arguments" << std::endl;
		return (-1);
	}

	ft::bot	bot;
	error	err;

	try{
		port = err.port(argv[1]);
	} catch (const std::exception &e)
	{
		std::cerr << e.what();
		return (-1);
	}
	pw = std::string(argv[2]);

	bot.init(port);
	bot.Connect(pw);
	bot.retrieveMsgs();
	bot.run();
}
