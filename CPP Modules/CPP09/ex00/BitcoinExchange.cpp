#include "BitcoinExchange.hpp"
#include <vector>

BitcoinExchange::BitcoinExchange()
{
	std::ifstream   dbase("data.csv");
	if (dbase.good())
	{
		std::string line;
		std::getline(dbase, line);
		for (; std::getline(dbase, line);)
		{
			std::stringstream   sstream(line.substr(11));
			long double ld;
			sstream >> ld;
			this->_data.insert(std::pair<std::string, long double>(line.substr(0, 10), ld));
		}
		this->_months.insert(std::pair<std::string, int>("01", 31));
		this->_months.insert(std::pair<std::string, int>("02", 28));
		this->_months.insert(std::pair<std::string, int>("03", 31));
		this->_months.insert(std::pair<std::string, int>("04", 30));
		this->_months.insert(std::pair<std::string, int>("05", 31));
		this->_months.insert(std::pair<std::string, int>("06", 30));
		this->_months.insert(std::pair<std::string, int>("07", 31));
		this->_months.insert(std::pair<std::string, int>("08", 31));
		this->_months.insert(std::pair<std::string, int>("09", 30));
		this->_months.insert(std::pair<std::string, int>("10", 31));
		this->_months.insert(std::pair<std::string, int>("11", 30));
		this->_months.insert(std::pair<std::string, int>("12", 31));
	}
	else
		std::cout << "Error\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_data = other._data;
		this->_months = other._months;
		this->_rawData = other._rawData;
		this->_result = other._result;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

bool    BitcoinExchange::readingInputData(const std::string& filename)
{
	std::ifstream   dbase(filename.c_str());
	if (dbase.good())
	{
		std::string line;
		for (; std::getline(dbase, line);)
		{
			if (line.size() > 13 && line.find_first_of("|") < line.length())
			{
				std::stringstream   sstream(line.substr(13));
				long double ld;
				sstream >> ld;
				this->_rawData.insert(std::pair<std::string, std::string>(line.substr(0, line.find_first_of('|')), line.substr(line.find_first_of('|') + 1)));
			}
			else
				this->_result.insert(std::pair<std::string, std::string>(line.substr(0), "Error: bad input => " + line.substr(0, 10)));
		}
		return (true);
	}
	return (false);
}

int BitcoinExchange::getDaysofMonth(const std::string& month)
{
	std::map<std::string, int>::iterator  it;
	it = this->_months.find(month);
	if (it != this->_months.end())
		return(it->second);
	return (-1);
}

bool    BitcoinExchange::parsingDays(const std::string& date, int year)
{
	std::stringstream   dsstream(date.substr(8));
	int                 days;
	bool    valid = false;
	dsstream >> days;
	if (year % 100 == 0)
	{
		if (year % 400 == 0)
		{
			if (((date.substr(5, 2) == "02") && (days > 0
				&& days <= getDaysofMonth(date.substr(5, 2)) + 1))
				|| (days > 0 && getDaysofMonth(date.substr(5, 2)) > 0))
				valid = true;
		}
		else
		{
			std::stringstream   dsstream(date.substr(8));
			int                 days;
			dsstream >> days;
			if (days > 0 && days <= getDaysofMonth(date.substr(5, 2)))
				valid = true;
		}
	}
	else if (year % 4 == 0)
	{
		if (((date.substr(5, 2) == "02") && (days > 0
			&& days <= getDaysofMonth(date.substr(5, 2)) + 1))
			|| (days > 0 && days <= getDaysofMonth(date.substr(5, 2))))
			valid = true;
	}
	else
	{
		std::stringstream   dsstream(date.substr(8));
		int                 days;
		dsstream >> days;
		if (days > 0 && days <= getDaysofMonth(date.substr(5, 2)))
			valid = true;
	}
	return (valid);
}

bool    BitcoinExchange::parsingDate(const std::string& date)
{
	bool    valid = false;

	if (date.find_first_not_of("0123456789- ") < date.length() || date.length() != 11)
	{
		std::string tmp;
		tmp = "Error: bad input => " + date;
		this->_result.insert(std::pair<std::string, std::string>(date, tmp));
		return (valid);
	}
	std::stringstream   sstream(date.substr(0, 4));
	int                 year;
	sstream >> year;
	if (date.substr(8).size() == 3)
		valid = parsingDays(date, year);
	else
		valid = false;
	if (valid == false)
	{
		std::string tmp;
		tmp = "Error: bad input => " + date;
		this->_result.insert(std::pair<std::string, std::string>(date, tmp));
	}
	return (valid);
}

bool    BitcoinExchange::parsingPrices(const std::string& date, const std::string& price)
{
	if (price.find_first_of(" ") != price.find_last_of(" ")
		|| price.find_first_not_of("0123456789.- \r") < price.length() || price.at(0) != ' ')
	{
		std::string tmp;
		tmp = "Error: Not a valid number =>" + price;
		this->_result.insert(std::pair<std::string, std::string>(date, tmp));
		return (false);
	}
	std::stringstream   sstream(price);
	long double amount;
	sstream >> amount;
	if (amount < 0)
	{
		std::string tmp;
		tmp = "Error: Not a positive number =>" + price;
		this->_result.insert(std::pair<std::string, std::string>(date, tmp));
		return (false);
	}
	if ((price.size() < 6) && (amount >= 0 && amount <= 1000))
	{
		execution(date, amount);
		return (true);
	}
	std::string tmp;
	tmp = "Error: Too large a number =>" + price;
	this->_result.insert(std::pair<std::string, std::string>(date, tmp));
	return (false);
}

void    BitcoinExchange::parsingData()
{
	bool    valid = false;
	for (std::multimap<std::string, std::string>::iterator it = this->_rawData.begin();
		it != this->_rawData.end(); it++)
	{
		valid = false;
		(void)valid;
		std::string date = it->first;
		std::string price = it->second;
		valid = parsingDate(date);
		if (valid == true)
		{
			valid = parsingPrices(date, price);
		}
	}
	for (std::multimap<std::string, std::string>::iterator i = this->_result.begin(); i != this->_result.end(); i++)
		std::cout << i->second << std::endl;
}

void    BitcoinExchange::execution(const std::string& date, long double price)
{
	std::map<std::string, long double>::iterator  lower = _data.lower_bound(date);
	if (lower != _data.begin() && lower != _data.end() && (*lower).first != date)
		lower--;
	if (date < _data.begin()->first)
		this->_result.insert(std::pair<std::string, std::string>(date, "Error: Out of Range"));
	else
	{
		if (date > _data.rbegin()->first)
			lower = --_data.end();
		std::stringstream   sstream;
		std::stringstream   rstream;
		std::string   str;
		long double result = _data.find(lower->first)->second;
		result = result * price;
		sstream << price;
		sstream >> str;
		std::string tmp = date + " => " + str + " = ";
		rstream << result;
		rstream >> str;
		tmp += str;
		this->_result.insert(std::pair<std::string, std::string>(date, tmp));
	}
}
