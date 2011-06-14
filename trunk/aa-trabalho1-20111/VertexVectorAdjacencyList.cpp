#include <malloc.h>
#include <stdlib.h>

#include "VertexVectorAdjacencyList.h"

VertexVectorAdjacencyList::VertexVectorAdjacencyList ( )
{
    m_lastHighestDegree = 0;
    m_nVertex = 0;
}

VertexVectorAdjacencyList::~VertexVectorAdjacencyList ( )
{
    delete m_elementList;

    for(int i = 0; i <  m_nVertex - 1; i++) {
        delete m_vectorVertex[i];
    }

    delete m_vectorVertex;
}

void VertexVectorAdjacencyList::Allocate( int nVertex )
{
    AdjacencyList::Allocate( nVertex );

    m_nVertex = nVertex;
    
    m_lastHighestDegree = nVertex - 2;
    m_vectorVertex = new List * [ nVertex - 1 ];

	for(int i = 0; i <  nVertex - 1; i++) {
		m_vectorVertex[i] = new List();
	}

	m_elementList = new ListNode *[nVertex];

	for(int i = 0; i < nVertex; i++) {
		m_elementList[i] = NULL;
	}

}

void VertexVectorAdjacencyList::DecrementDegree( int iVertex )
{
	// remove da lista atual e ..
	ListNode* element  = m_elementList[ iVertex ];
	int degree = element->getDegree();

    m_vectorVertex[ degree ]->remove( element );

	// insere na lista respectiva ao grau-1
	ListNode* node = m_vectorVertex[ degree - 1 ]->insertAtEnd( iVertex );

	node->setDegree( degree - 1 );

    m_elementList[ iVertex ] = node;
}

void VertexVectorAdjacencyList::RemoveFromVertexVector( int iVertex, int iDegree )
{
	ListNode* element  = m_elementList[ iVertex ];

	m_vectorVertex[ iDegree ]->remove( element );
	m_elementList[ iVertex ] = NULL;
}

int VertexVectorAdjacencyList::RemoveHighestDegreeVertex( int debug )
{
    ListNode * highestDegreeVertex = GetHighestDegreeVertex();
    int iHighestDegreeVertex = highestDegreeVertex->getVertex();
    List * neighbors = m_arrAdjLists[ iHighestDegreeVertex ];
    
    if ( debug >= 2 )
    {
        fprintf( stderr, "  vertice %d tem %d vizinhos\n",
                 iHighestDegreeVertex,
                 neighbors->size( ) );
    }
    
    for ( ListNode * node = neighbors->getFirst();
            node != NULL;
            node = node->next())
    {
        int iNeighbor = node->getVertex();
        //int iCurrentDegree = (int) m_arrAdjLists[ iNeighbor ]->size();

        // update this vertex's neighbor's list that this vertex is being removed
        //m_arrAdjLists[ iNeighbor ]->erase( iHighestDegreeVertex );
        
        // if the neighbor is still in vertex vector, it means it has not been removed
        // note: it may be on my neighbor's list, but already processed and removed, we need
        // to make sure we will be decrementing a degree from a neighbor that's already in the graph
        if ( m_elementList[ iNeighbor ] != NULL )
        {
            // remove edge from this vertex
            m_nEdges --;

            // decrement degree from neighbor
            DecrementDegree( iNeighbor );//, iCurrentDegree );
        }
    }


    // reset degree
    RemoveFromVertexVector( iHighestDegreeVertex, highestDegreeVertex->getDegree() );//neighbors->size() );
    
    // remove edges to neighbors, and let the vertex linger and ...
    //neighbors.clear( );
    
    return iHighestDegreeVertex;
}

ListNode* VertexVectorAdjacencyList::GetHighestDegreeVertex( )
{
    for(int i = m_lastHighestDegree; i >= 0; i--)
    {
        if(m_vectorVertex[i]->size() != 0)
        {
            m_lastHighestDegree = i;
            return m_vectorVertex[i]->getFirst();//)->getVertex();
        }
    }
    
    return NULL;
}

void VertexVectorAdjacencyList::updateData()
{
    for( int i = 0; i < m_nVertex; i++ )
    {
        int degree = m_arrAdjLists[i]->size();

        // the vertex degree is its position in the vector
        ListNode* node = m_vectorVertex[ degree ]->insertAtEnd( i );
        node->setDegree( degree );

		m_elementList[i] = node;
    }
}
