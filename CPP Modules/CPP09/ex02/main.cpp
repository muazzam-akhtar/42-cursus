#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		PmergeMe	PMe(argv);

		if (PMe.parseInput())
			return (EXIT_FAILURE);
		PMe.execution();
		return (EXIT_SUCCESS);
	}
	std::cerr << std::endl << "\033[1;31m*************ERROR*************\033" << std::endl;
    std::cerr << ": " << "Invalid number of Arguments" << std::endl << std::endl;
	return (EXIT_FAILURE);
}