#include "DegreeHeapAdjacencyList.h"
#include "VertexVectorAdjacencyList.h"

DegreeHeapAdjacencyList::DegreeHeapAdjacencyList( )
{
    m_heap = new Heap( m_nVertex );
}
DegreeHeapAdjacencyList::~DegreeHeapAdjacencyList( )
{
    delete m_heap;
}

int DegreeHeapAdjacencyList::RemoveHighestDegreeVertex( int debug )
{
    // remove the highest degree vertex from heap
    std::pair<int, int> vertex;
    m_heap->removeFromHeap( vertex );
    int iHighestDegreeVertex = vertex.first;
    
    std::set<int> neighbors = m_arrAdjLists[ iHighestDegreeVertex ];
    
    if ( debug >= 2 )
    {
        fprintf( stderr, "  vertice %d tem %d vizinhos\n",
                 iHighestDegreeVertex,
                 ( int ) neighbors.size( ) );
    }
    
    // decrease its neighbor's degree
    for ( std::set< int >::iterator it = neighbors.begin( );
            it != neighbors.end( );
            it ++ )
    {
        int iNeighbor = *it;

        // update this vertex's neighbor's list that this vertex is being removed
        m_arrAdjLists[ iNeighbor ].erase( iHighestDegreeVertex );

        // remove edge from this vertex
        m_nEdges --;

        // decrement degree from neighbor
        m_heap->DecrementDegree( iNeighbor );        
    }
    
    // remove edges to neighbors, and let the vertex linger
    neighbors.clear( );
    
    return iHighestDegreeVertex;
    
}

void DegreeHeapAdjacencyList::updateData( )
{
    for( int i = 0; i < m_nVertex; i++ )
    {
        m_heap->insertOnHeap( i, (int) m_arrAdjLists->size() );
    }
}