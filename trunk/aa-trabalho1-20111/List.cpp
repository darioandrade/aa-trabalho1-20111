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

ListNode* List::insertAtEnd(int content)
{
    ListNode * node = new ListNode(content);
	ListNode * previous = NULL;

    /* Primeiro elemento */
    if ((m_first == NULL) && (m_last == NULL)) {
        m_first = node;
        m_last = node;
    } else {
        node->setPrevious( m_last );
		previous = m_last;
        m_last->setNext(node);
        m_last = node;
    }

    m_numElems++;

    return node;
}

int List::insertAtFront(int content)
{
    ListNode * node = new ListNode(content);

    /* Primeiro elemento */
    if ((m_first == NULL) && (m_last == NULL)) {
        m_first = node;
        m_last = node;
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
    m_first->setPrevious( NULL );
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

			// Primeiro da lista
			if (node == m_first) {
				if (m_numElems == 1) {
					m_first = NULL;
					m_last = NULL;
				} else {
					m_first = node->next();
                    m_first->setPrevious( NULL );
				}
			} else {
				previous->setNext(node->next());

				if (node == m_last) {
					m_last = previous;
				}
                else
                {
                    node->next()->setPrevious( previous );
                }
			}


				m_numElems--;
			delete node;
			return;
		}
		previous = node;
	}
}


void List::remove( ListNode* node )
{
	if (node == NULL)
		return;

    ListNode* previous = node->previous();
    
	// primeiro da lista
	if (node == m_first)
	{
		if (m_numElems == 1)
		{
			m_first = NULL;
			m_last = NULL;
		}
		else
		{
			m_first = node->next();
            m_first->setPrevious( NULL );
		}
	}
	else
	{
		previous->setNext(node->next());

		if (node == m_last)
		{
			m_last = previous;
		}
        else
        {
            node->next()->setPrevious( previous );
        }
	}

	m_numElems--;

	delete node;
}
