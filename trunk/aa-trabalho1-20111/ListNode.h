
#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <stdio.h>

class ListNode
{
public:
	ListNode(int content);
	~ListNode();
	
	int getVertex() { return m_vertex; }
	int getDegree() { return m_degree; }
    void setDegree(int degree) { m_degree = degree; }
	ListNode * next() { return m_next; }
	void setNext(ListNode * node) { m_next = node; }
        ListNode * previous() { return m_previous; }
	void setPrevious(ListNode * node) { m_previous = node; }

private:
    int m_vertex;
    int m_degree;
    ListNode * m_next;
    ListNode* m_previous;
};

#endif


