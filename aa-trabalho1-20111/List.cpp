#include "List.h"
#include "ListNode.h"
#include <stdio.h>

List::List()
{
    m_first = NULL;
    m_last = NULL;
    m_numElems = 0;
}

List::~List()
{
	// DOES NOTHING
}

int List::insertAtEnd(int content)
{
    ListNode * node = new ListNode(content);

    /* Primeiro elemento */
    if ((m_first == NULL) && (m_last == NULL)) {
        m_first = node;
        m_last = node;
    } else {
        m_last->setNext(node);
        m_last = node;
    }
	
    m_numElems++;

    return 0;
}

int List::insertAtFront(int content)
{
    ListNode * node = new ListNode(content);

    /* Primeiro elemento */
    if ((m_first == NULL) && (m_last == NULL)) {
        m_first = node;
        m_last = node;
		node->setNext(NULL);
    } else {
        node->setNext(m_first);
        m_first = node;
    }

    m_numElems++;

    return 0;
}

int List::removeFirst()
{
	if (m_numElems == 0) {
		return -1;
	}

    ListNode * node = m_first;

    int content = node->getContent();

    m_first = m_first->next();

    delete node;

    m_numElems--;

    return content;
}

int List::size()
{
    return m_numElems;
}

void List::erase(int content)
{
	ListNode * previous = NULL;

	for(ListNode * node = m_first; node != NULL; node = node->next()) {

		if(content == node->getContent()) {

			// Primeiro da listaL
			if (node == m_first) {
				if (m_numElems == 1) {
					m_first = NULL;
					m_last = NULL;
				} else {
					m_first = node->next();
				}
			} else {
				previous->setNext(node->next());

				if (node == m_last) {
					m_last = previous;
				}
			}
			
			m_numElems--;
			delete node;
			return;
		}
		previous = node;
	}
}


