#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct Node
{
  Node(T val) : m_val{val}, m_next{nullptr} {}
  Node() = default;

  Node<T>* m_next{nullptr};
  T m_val{};
};

template<typename T>
class SList
{
public:
  void createNode(const T& val);
  void print();

private:
  Node<T>* m_head{nullptr};
  Node<T>* m_tail{nullptr};
};

#include "LinkedList.inl"

#endif // LINKEDLIST_H
