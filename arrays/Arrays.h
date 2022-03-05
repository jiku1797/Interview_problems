#ifndef ARRAYS_H
#define ARRAYS_H

#include <array>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#include "Util.h"

/* How do you find the missing number in a given
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

/* How do you find the largest and smallest number in an unsorted integer array?
 * Returns pair w/ (min, max)
*/
template <typename T, std::size_t N>
auto getMinAndMax(const std::array<T, N>& arr)
{
  auto min{arr.at(0)};
  auto max{arr.at(0)};

  std::for_each(std::begin(arr), std::end(arr), [&min, &max](const auto elem)
  {
    if(elem < min)
      min = elem;
    else if(elem > max)
      max = elem;
  });

  return std::make_pair(min, max);
}

/* How do you find all pairs of an integer array whose sum is
 * equal to a given number?
*/
template <std::size_t N>
std::vector<std::pair<int, int>> pairsSumTo(std::array<int, N> arr, const int sum)
{
  // to simplify looping and inserts we start with a
  // sorted array
  std::sort(std::begin(arr), std::end(arr));

  // for sake of uniqueness we first
  // store pairs in a set
  // notice non-default hash function
  std::unordered_set<std::pair<int, int>, pair_hash> tmpSet;

  for(auto it = arr.begin(); (*it < sum) && it != arr.end(); ++it)
  {
    for(auto itt = it+1;  itt != arr.end(); ++itt)
    {
      const auto current{*it};
      const auto other{*itt};
      if(current + other == sum)
      {
        tmpSet.emplace(current, other);
      }
    }
  }
  std::vector<std::pair<int, int>> ret;
  ret.reserve(tmpSet.size());
  std::copy(std::begin(tmpSet), std::end(tmpSet), std::back_inserter(ret));

  return ret;
}

/* How do you find duplicate numbers in an array if it contains
 * multiple duplicates?
 * \return Map of duplicated element and its multiplicity
*/
template <typename T, std::size_t N>
std::unordered_map<T, int> findAllDuplicates(std::array<T, N> arr)
{
  std::unordered_map<T, int> ret;
  std::sort(arr.begin(), arr.end(), std::less<T>());

  int count{0};
  for(auto it=arr.begin(); it!=arr.end();)
  {
    count = 1;
    while(it + count != arr.end())
    {
      if(*it == *(it + count))
      {
        ++count;
      }
      else
        break;
    }

    ret.insert({*it, count});
    ++it;
  }

  return ret;
}

/*
 * How are duplicates removed from an array without using any library?
*/
template <typename T, std::size_t N>
std::vector<T> rmDuplNoLib(const std::array<T, N>& arr)
{
  std::unordered_set<T> set{std::begin(arr), std::end(arr)};
  std::vector<T> ret{std::begin(set), std::end(set)};
  return ret;
}
#endif // ARRAYS_H
