#ifndef LIST_H
#define LIST_H

#include <utility>
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

	std::pair<ListNode *, ListNode *> insertAtEnd(int content);

	int insertAtFront(int content);

	int removeFirst();

	int size();

	ListNode * getFirst() { return m_first; }

	ListNode * getLast() { return m_last; }

	void erase(int content);

	void remove( ListNode* previous, ListNode* node );

private:
    int m_numElems;
    ListNode * m_first;
    ListNode * m_last;
};

#endif


