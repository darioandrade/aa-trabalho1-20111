#include "DegreeHeapAdjacencyList.h"
#include "VertexVectorAdjacencyList.h"

DegreeHeapAdjacencyList::DegreeHeapAdjacencyList( )
{
}
DegreeHeapAdjacencyList::~DegreeHeapAdjacencyList( )
{
    delete m_heap;
}

void DegreeHeapAdjacencyList::Allocate( int nVertex )
{
    AdjacencyList::Allocate( nVertex );
    
    m_heap = new Heap( nVertex );
}

int DegreeHeapAdjacencyList::RemoveHighestDegreeVertex( int debug )
{
    // remove the highest degree vertex from heap
    std::pair<int, int> vertex;
    m_heap->removeFromHeap( vertex );
    int iHighestDegreeVertex = vertex.first;
    
    List * neighbors = m_arrAdjLists[ iHighestDegreeVertex ];
    
    if ( debug >= 2 )
    {
        fprintf( stderr, "  vertice %d tem %d vizinhos\n",
                 iHighestDegreeVertex,
                 neighbors->size() );
    }
    
    // decrease its neighbor's degree
    for ( ListNode * node = neighbors->getFirst();
		node != NULL;
		node = node->next())
    {
        int iNeighbor = node->getContent();

        // update this vertex's neighbor's list that this vertex is being removed
        m_arrAdjLists[ iNeighbor ]->erase( iHighestDegreeVertex );

        // remove edge from this vertex
        m_nEdges --;

        // decrement degree from neighbor
        m_heap->DecrementDegree( iNeighbor );        
    }
    
    // remove edges to neighbors, and let the vertex linger
    //neighbors.clear( );
    
    return iHighestDegreeVertex;
    
}

void DegreeHeapAdjacencyList::updateData( )
{
	
    for( int i = 0; i < m_nVertex; i++ )
    {
        m_heap->insertOnHeap( i, (int) m_arrAdjLists[i]->size() );
    }
}
