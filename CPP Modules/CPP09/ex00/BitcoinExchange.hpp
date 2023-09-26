#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <map>
# include <iterator>
# include <string>
# include <iostream>
# include <sstream>
# include <fstream>
# include <iomanip>


class BitcoinExchange
{
public:

	/******* Constructors ********/

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange	&operator=(const BitcoinExchange &);
	~BitcoinExchange();

	/******* Execution Functions ********/

	bool    readingInputData(const std::string&);
	void    parsingData(void);
	int     getDaysofMonth(const std::string&);
	bool    parsingDate(const  std::string &);
	bool    parsingPrices(const  std::string &, const  std::string &);
	bool    parsingDays(const std::string&, int);
	void    execution(const  std::string &, long double);

private:

	/******* Private Variables ********/

	std::multimap<std::string, long double>    _data;
	std::multimap<std::string, std::string>    _rawData;
	std::multimap<std::string, std::string>    _result;
	std::multimap<std::string, int>            _months;
};

#endif