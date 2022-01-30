#include <iostream>
#include <array>
#include <numeric>

#include "Arrays.h"

int main(int argc, char *argv[])
{
  const std::array<int, 8> testArr{7,5,2,3,8,1,13,5};
  //std::iota(testArr.begin(), testArr.end(), 1);

  std::cout << getMinAndMax(testArr).first << '\n'
            << getMinAndMax(testArr).second << '\n';
  return 0;
}
