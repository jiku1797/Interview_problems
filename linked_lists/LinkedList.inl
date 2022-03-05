template<typename T>
SList<T>::~SList()
{
  auto* cur = m_head;
  while(cur)
  {
    popHead();
    cur = cur->m_next;
  }
}

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
void SList<T>::insertAt(int pos, const T& val)
{
  if(pos < 0) return;
  if(pos == 0)
  {
    insertHead(val);
    return;
  }

  Node<T>* pre;
  Node<T>* cur;
  cur = m_head;
  for(int i=0; i<pos; ++i)
  {
    pre = cur;
    cur = cur->m_next;
  }

  auto* tmp = new Node(val);
  pre->m_next = tmp;
  tmp->m_next = cur;
}

template <typename T>
void SList<T>::popHead()
{
  auto* tmp = m_head;
  m_head = m_head->m_next;
  std::cout << "Deleting value: "
            << tmp->m_val << '\n';
  delete tmp;
}

template <typename T>
void SList<T>::popTail()
{
  if(m_head == m_tail) popHead();

  auto* tmp = m_tail;
  auto* cur = m_head;

  while(cur)
  {
    if(cur->m_next == m_tail)
    {
      m_tail = cur;
      m_tail->m_next = nullptr;
    }
    cur = cur->m_next;
  }

  delete tmp;
}

template <typename T>
void SList<T>::popAt(int pos)
{
  auto* cur = m_head;
  auto* pre = m_head;

  if(pos == 0)
  {
    popHead();
    return;
  }

  for(int i=0; i<pos; ++i)
  {
    pre = cur;
    cur = cur->m_next;
  }

  pre->m_next = cur->m_next;
  delete cur;
}

template <typename T>
void SList<T>::print()
{
  Node<T>* tmp = m_head;
  while(tmp)
  {
   std::cout << tmp->m_val << '\n';
   tmp = tmp->m_next;
  }
}
