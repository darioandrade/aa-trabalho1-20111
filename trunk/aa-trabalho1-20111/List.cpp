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

std::pair<ListNode *, ListNode *> List::insertAtEnd(int content)
{
    ListNode * node = new ListNode(content);
	ListNode * previous = NULL;

    /* Primeiro elemento */
    if ((m_first == NULL) && (m_last == NULL)) {
        m_first = node;
        m_last = node;
    } else {
		previous = m_last;
        m_last->setNext(node);
        m_last = node;
    }

	fprintf(stderr, "pre insertAtEnd %d\n", m_numElems );
    m_numElems++;
	fprintf(stderr, "pos insertAtEnd %d\n", m_numElems );

    return std::pair<ListNode*, ListNode*>(previous, node);
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

    fprintf(stderr, "pre insertAtFront %d\n", m_numElems );
    m_numElems++;
	fprintf(stderr, "pos insertAtFront %d\n", m_numElems );

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

	fprintf(stderr, "pre removeFirst %d\n", m_numElems );
    m_numElems--;
	fprintf(stderr, "pos removeFirst %d\n", m_numElems );

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


				fprintf(stderr, "pre erase %d\n", m_numElems );
				m_numElems--;
				fprintf(stderr, "pos erase %d\n", m_numElems );
			delete node;
			return;
		}
		previous = node;
	}
}


void List::remove( ListNode* previous, ListNode* node )
{
	if (node == NULL)
		return;
	
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
		}
	}
	else
	{
		previous->setNext(node->next());

		if (node == m_last)
		{
			m_last = previous;
		}
	}

	fprintf(stderr, "pre remove %d\n", m_numElems );
	m_numElems--;
	fprintf(stderr, "pos remove %d\n", m_numElems );

	delete node;
}