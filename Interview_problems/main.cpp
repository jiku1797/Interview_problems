#include <iostream>
#include <array>
#include <vector>
#include <numeric>

#include "Arrays.h"
#include "QuickSort.h"

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
  std::array<int, 8> testArr{7,5,2,3,-8,1,13,5};
  std::vector<double> testVec{7.5,5.4,2.8,3.0,-8.1,1.4,13.9,5.7};
  quickSort(testVec);
  printContainer(testVec);

  //pairsSumTo()
  return 0;
}
