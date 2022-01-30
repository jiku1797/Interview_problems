#include <iostream>
#include <array>
#include <numeric>

#include "Arrays.h"

int main(int argc, char *argv[])
{
  std::array<int, 5> testArr{7,5,2,3,8};
  //std::iota(testArr.begin(), testArr.end(), 1);

  std::cout << smallestNonUnique(testArr) << '\n';
  return 0;
}
