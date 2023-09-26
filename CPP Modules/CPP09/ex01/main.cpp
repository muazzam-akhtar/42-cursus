#include "RPN.hpp"

int main(int argc, char **argv)
{
  if (argc == 2)
  {
    RPN	op(argv[1]);
    if (op.readingInput())
      return (EXIT_FAILURE);
    if (op.execution())
      return (EXIT_FAILURE);
    if (op.printResult())
      return (EXIT_FAILURE);
  }
  else
  {
    std::cerr << std::endl << "\033[1;31m*************ERROR*************\033" << std::endl;
    std::cerr << ": " << "More than one Argument!" << std::endl << std::endl;
  }
  return (0);
}