#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <iterator>
# include <vector>
# include <deque>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <utility>
# include <sys/time.h>

class PmergeMe
{
	public:

		/******* Constructors ********/
		
		PmergeMe();
		PmergeMe(char **str);
		PmergeMe(const PmergeMe &);
		PmergeMe	&operator=(const PmergeMe &);
		~PmergeMe();
		
		/******* Defined Types ********/
		
		typedef std::pair<int, int>		Pair;
		typedef std::vector<Pair>		vectorPairs;
		typedef std::deque<Pair>		dequePairs;

		/******* Parsing Functions ********/
		
		int			parseInput(void);
		int			validInputs(const  std::string &);
		int			printError(int);
		
		/******* Vectors Sorting Functions ********/
		
		int			sortVectors();
		int			divideVector();
		int			makePairVectors();
		std::size_t	sortSubVector(std::size_t, bool *);
		int			lookupLowerBound(std::vector<int> &);
		int			mergeVectors(int);

		/******* Deque Sorting Functions ********/
		
		int			sortDeque();
		int			divideDeque();
		int			makePairDeque();
		std::size_t	sortSubDeque(std::size_t, bool *);
		int			lookupLowerBoundDeque(std::deque<int> &);
		int			mergeDeques(int);

		/******* Utils ********/
		
		int			execution();
		double		getTime();
		void		printVectors(std::vector<int> &);
		void		printDeques(std::deque<int> &);
		void		printResult(double, double, int);

	private:

		/******* Private Variables ********/
		
		std::vector<std::string>	_str;
		std::vector<int>			_storeNumbers;
		
		/******* Deque Variables ********/

		std::deque<int>				_dequeStore;
		dequePairs					_pairwisedDeques;
		std::deque<int>			_sortedDeque;

		/******* Vector Variables ********/

		std::vector<int>			_vectorStore;
		vectorPairs					_pairwiseVectors;
		std::vector<int>			_sortedVector;
};

#endif