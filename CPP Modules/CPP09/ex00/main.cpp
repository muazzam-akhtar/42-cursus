#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        BitcoinExchange BCE;
        std::string filename = argv[1];
		if (!BCE.readingInputData(filename))
		{
        	std::cerr << "Error: could not open file.\n";
			return (0);
		}
        BCE.parsingData();
    }
    else
        std::cerr << "Error: could not open file.\n";
    return (0);
}