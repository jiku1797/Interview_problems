#include <iostream>
#include <array>
#include <vector>
#include <numeric>

#include "Arrays.h"
#include "QuickSort.h"
#include "LinkedList.h"

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
  //std::array<int, 11> testArr{7,5,7,3,-8,3,7,5,3,3,3};
  //std::vector<double> testVec{7.5,5.4,2.8,3.0,-8.1,1.4,13.9,5.7};
  SList<int> myLst;
  myLst.createNode(5);
  myLst.createNode(7);

  myLst.print();
  return 0;
}
