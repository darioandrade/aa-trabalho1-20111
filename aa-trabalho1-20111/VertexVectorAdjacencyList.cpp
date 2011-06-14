#include <malloc.h>

#include "VertexVectorAdjacencyList.h"

VertexVectorAdjacencyList::VertexVectorAdjacencyList ( )
{
    m_lastHighestDegree = 0;
    m_nVertex = 0;
}

VertexVectorAdjacencyList::~VertexVectorAdjacencyList ( )
{

}

void VertexVectorAdjacencyList::Allocate( int nVertex )
{
    AdjacencyList::Allocate( nVertex );

    m_lastHighestDegree = nVertex - 2;
    m_vectorVertex = new List * [ nVertex - 1 ];

	for(int i = 0; i <  nVertex - 1; i++) {
		m_vectorVertex[i] = new List();
	}

	m_elementList = new ListNode *[nVertex];
	m_previousElementList = new ListNode *[nVertex];

	for(int i = 0; i < nVertex; i++) {
		m_elementList[i] = NULL;
		m_previousElementList[i] = NULL;
	}

}

void VertexVectorAdjacencyList::DecrementDegree( int iVertex, int iCurrentDegree )
{
	// remove da lista atual e ..
	ListNode* previous = m_previousElementList[ iVertex ];
	ListNode* element  = m_elementList[ iVertex ];
	m_vectorVertex[ iCurrentDegree ]->remove( previous, element );

	// insere na lista respectiva ao grau-1
	std::pair<ListNode*, ListNode*> pointers = m_vectorVertex[ iCurrentDegree - 1 ]->insertAtEnd( iVertex );
	m_previousElementList[ iVertex ] = pointers.first;
	m_elementList[ iVertex ] = pointers.second;

	//m_vectorVertex[ iCurrentDegree ]->erase( iVertex );
    //m_vectorVertex[ iCurrentDegree - 1]->insertAtEnd( iVertex );
}

void VertexVectorAdjacencyList::RemoveFromVertexVector( int iVertex, int iDegree )
{
    //m_vectorVertex[ iDegree ]->erase( iVertex );
	ListNode* previous = m_previousElementList[ iVertex ];
	ListNode* element  = m_elementList[ iVertex ];

	m_vectorVertex[ iDegree ]->remove( previous, element );

	m_previousElementList[ iVertex ] = NULL;
	m_elementList[ iVertex ] = NULL;
}

int VertexVectorAdjacencyList::RemoveHighestDegreeVertex( int debug )
{
    int iHighestDegreeVertex = GetHighestDegreeVertex();
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
        int iNeighbor = node->getContent();
        int iCurrentDegree = (int) m_arrAdjLists[ iNeighbor ]->size();

        // update this vertex's neighbor's list that this vertex is being removed
        //m_arrAdjLists[ iNeighbor ]->erase( iHighestDegreeVertex );

        // remove edge from this vertex
        m_nEdges --;

		fprintf(stderr, "iHighestDegreeVertex: %d\n", iHighestDegreeVertex);
        // decrement degree from neighbor
        DecrementDegree( iNeighbor, iCurrentDegree );        
    }

	fprintf(stderr, "iHighestDegreeVertex: %d\n", iHighestDegreeVertex);

    // reset degree
    RemoveFromVertexVector( iHighestDegreeVertex, neighbors->size() );
    
    // remove edges to neighbors, and let the vertex linger and ...
    //neighbors.clear( );
    
    return iHighestDegreeVertex;
}

int VertexVectorAdjacencyList::GetHighestDegreeVertex( )
{
    for(int i = m_lastHighestDegree; i >= 0; i--)
    {
        if(m_vectorVertex[i]->size() != 0)
        {
            m_lastHighestDegree = i;
            return (m_vectorVertex[i]->getFirst())->getContent();
        }
    }
    
    return -1;
}

void VertexVectorAdjacencyList::updateData()
{
    for( int i = 0; i < m_nVertex; i++ )
    {
        // the vertex degree is its position in the vector
        std::pair<ListNode*, ListNode*> pointers = m_vectorVertex[ m_arrAdjLists[i]->size() ]->insertAtEnd( i );

		m_previousElementList[i] = pointers.first;
		m_elementList[i] = pointers.second;
    }
}
