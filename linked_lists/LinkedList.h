#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct Node
{
  Node(T val) : m_next{nullptr}, m_val{val} {}
  Node() = default;

  Node<T>* m_next{nullptr};
  T m_val{};
};

template<typename T>
class SList
{
public:
  ~SList();

  void createNode(const T& val);
  void insertHead(const T& val);
  void insertTail(const T& val);
  void insertAt(int pos, const T& val);
  void popHead();
  void popTail();
  void popAt(int pos);

  void print();

  // special functions
  T getMiddleElem() const;

private:
  Node<T>* m_head{nullptr};
  Node<T>* m_tail{nullptr};
};

#include "LinkedList.inl"
#include "LinkedListSpecial.inl"

#endif // LINKEDLIST_H
