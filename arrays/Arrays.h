#ifndef ARRAYS_H
#define ARRAYS_H

#include <array>
#include <vector>
#include <numeric>

/*How do you find the missing number in a given
 * integer array of 1 to 100?
 * We assume given arr is 1 short, i.e. of
 * length 99
*/
template <std::size_t N>
int missingNum(const std::array<int, N> arr)
{
  // sum of all ints [1, N+1]
  const int lSum{(N + 1)*(N + 2) / 2};
  // sum over given arr
  const int sSum = std::accumulate(std::begin(arr),
                                   std::end(arr), 0);

  return lSum - sSum;
}
#endif // ARRAYS_H
