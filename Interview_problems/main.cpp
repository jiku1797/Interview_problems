#include <iostream>
#include <array>
#include <vector>
#include <numeric>

#include "Arrays.h"

template <typename T>
struct DefaultPrinter
{
  static void print(T elemToPrint)
  {
    std::cout << elemToPrint << '\n';
  }
};

template <typename T>
struct PairPrinter
{
  static void print(const std::pair<T, T>& pairToPrint)
  {
    std::cout << "First: " << pairToPrint.first
              << '\t' << "Second: " << pairToPrint.second
                 << '\n';
  }
};

template <typename T, typename Printer = DefaultPrinter<typename T::value_type>>
void printContainer(const T& vec)
{
  for(const auto elem : vec)
  {
    Printer::print(elem);
  }
}

int main(int argc, char *argv[])
{
  const std::array<int, 8> testArr{7,5,2,3,8,1,13,5};
  const auto res = pairsSumTo(testArr, 8);
  printContainer<std::vector<std::pair<int, int>>, PairPrinter<int>>(res);

  //pairsSumTo()
  return 0;
}
