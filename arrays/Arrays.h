#ifndef ARRAYS_H
#define ARRAYS_H

#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

/*How do you find the missing number in a given
 * integer array of 1 to 100?
 * We assume given arr is 1 short, i.e. of
 * length 99
*/
template <std::size_t N>
int missingNum(const std::array<int, N>& arr)
{
  // sum of all ints [1, N+1]
  const int lSum{(N + 1)*(N + 2) / 2};
  // sum over given arr
  const int sSum = std::accumulate(std::begin(arr),
                                   std::end(arr), 0);

  return lSum - sSum;
}

/* How do you find the duplicate number on a given integer array?
 * We find the smallest duplicate element
*/
template <std::size_t N>
int smallestNonUnique(std::array<int, N> arr)
{
  std::sort(std::begin(arr), std::end(arr));
  auto it{std::adjacent_find(std::begin(arr), std::end(arr))};

  if(it != std::end(arr))
  {
    return *it;
  }

  return -1;
}
#endif // ARRAYS_H
