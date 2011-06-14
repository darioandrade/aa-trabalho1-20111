
#include "ListNode.h"


ListNode::ListNode(int content)
:
    m_vertex(content),
    m_degree(-1),
    m_next(NULL),
    m_previous(NULL)
{

}

ListNode::~ListNode()
{
	
}


