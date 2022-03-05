template <typename T>
T SList<T>::getMiddleElem() const
{
  auto* slowIncr = m_head;
  auto* fastIncr = m_head;

  while(fastIncr && fastIncr->m_next)
  {
    fastIncr = fastIncr->m_next->m_next;
    slowIncr = slowIncr->m_next;
  }

  return slowIncr->m_val;
}
