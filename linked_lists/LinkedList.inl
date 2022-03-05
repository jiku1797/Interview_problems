template <typename T>
void SList<T>::createNode(const T& val)
{
  auto* tmp = new Node(val);

  if(!m_head)
  {
    m_head = tmp;
    m_tail = tmp;
    tmp = nullptr;
  }
  else
  {
    m_tail->m_next = tmp;
    m_tail = tmp;
  }
}

template <typename T>
void SList<T>::insertHead(const T& val)
{
  auto* tmp = new Node(val);
  tmp->m_next = m_head;
  m_head = tmp;
}

template <typename T>
void SList<T>::insertTail(const T& val)
{
  auto* tmp = new Node(val);
  m_tail->m_next = tmp;
  m_tail = tmp;
}

template <typename T>
void SList<T>::print()
{
  Node<T>* tmp = m_head;
  while(tmp != nullptr)
  {
   std::cout << tmp->m_val << '\n';
   tmp = tmp->m_next;
  }
}
