#include <iostream>
#include <array>
#include <numeric>

#include "Arrays.h"

int main(int argc, char *argv[])
{
  std::array<int, 99> testArr;
  std::iota(testArr.begin(), testArr.end(), 1);
  testArr.at(77) = 100;

  std::cout << missingNum(testArr);
  return 0;
}
