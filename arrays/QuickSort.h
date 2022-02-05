/*
 * Quicksort implemented using STL's partition
*/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>

template <typename ForwardIt>
void quickSortImpl(ForwardIt first, ForwardIt last)
{
  if (first == last) return;

  auto pivot = *std::next(first, std::distance(first,last)/2);
  ForwardIt pItLeft = std::partition(first, last, [pivot](const auto& em){ return em < pivot; });
  ForwardIt pItRight = std::partition(pItLeft, last, [pivot](const auto& em){ return !(pivot < em); });

  quickSortImpl(first, pItLeft);
  quickSortImpl(pItRight, last);
}

// Quicksort algorithm
template <typename Container>
void quickSort(Container& arr)
{
  quickSortImpl(std::begin(arr), std::end(arr));
}

#endif // QUICKSORT_H
