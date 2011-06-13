#ifndef LIST_H
#define LIST_H

#include "ListNode.h"
/************************************************************************/
/*                                                                      */
/* 		      Tipo de dados lista genérica                      */
/*                                                                      */
/************************************************************************/

class List
{
public:
	List();
	~List();

	int insertAtEnd(int content);

	int insertAtFront(int content);

	int removeFirst();

	int size();

	ListNode * getFirst() { return m_first; }

	ListNode * getLast() { return m_last; }

	void erase(int content);

private:
    int m_numElems;
    ListNode * m_first;
    ListNode * m_last;
};

#endif


