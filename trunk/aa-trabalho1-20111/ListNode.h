
#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <stdio.h>

class ListNode
{
public:
	ListNode(int content);
	~ListNode();
	
	int getContent() { return m_content; }
	ListNode * next() { return m_next; }
	void setNext(ListNode * node) { m_next = node; }
private:
    int m_content;
    ListNode * m_next;
};

#endif


