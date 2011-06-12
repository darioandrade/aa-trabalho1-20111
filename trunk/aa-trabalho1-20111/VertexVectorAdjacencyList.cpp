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
    m_vectorVertex = new std::set<int> [ nVertex - 1 ];
}

void VertexVectorAdjacencyList::DecrementDegree( int iVertex, int iCurrentDegree )
{
    m_vectorVertex[ iCurrentDegree ].erase( iVertex );
    
    m_vectorVertex[ iCurrentDegree - 1].insert( iVertex );
}

void VertexVectorAdjacencyList::RemoveFromVertexVector( int iVertex, int iDegree )
{
    m_vectorVertex[ iDegree ].erase( iVertex );
}

int VertexVectorAdjacencyList::RemoveHighestDegreeVertex( int debug )
{
    int iHighestDegreeVertex = GetHighestDegreeVertex();
    std::set< int > neighbors = m_arrAdjLists[ iHighestDegreeVertex ];
    
    if ( debug >= 2 )
    {
        fprintf( stderr, "  vertice %d tem %d vizinhos\n",
                 iHighestDegreeVertex,
                 ( int ) neighbors.size( ) );
    }
    
    for ( std::set< int >::iterator it = neighbors.begin( );
            it != neighbors.end( );
            it ++ )
    {
        int iNeighbor = *it;
        int iCurrentDegree = (int) m_arrAdjLists[ iNeighbor ].size();

        // update this vertex's neighbor's list that this vertex is being removed
        m_arrAdjLists[ iNeighbor ].erase( iHighestDegreeVertex );

        // remove edge from this vertex
        m_nEdges --;

        // decrement degree from neighbor
        DecrementDegree( iNeighbor, iCurrentDegree );        
    }

    // reset degree
    RemoveFromVertexVector( iHighestDegreeVertex, (int) neighbors.size() ); 
    
    // remove edges to neighbors, and let the vertex linger and ...
    neighbors.clear( );
    
    return iHighestDegreeVertex;
}

int VertexVectorAdjacencyList::GetHighestDegreeVertex( )
{
    for(int i = m_lastHighestDegree; i >= 0; i--)
    {
        if( !m_vectorVertex[i].empty() )
        {
            m_lastHighestDegree = i;
            return *(m_vectorVertex[i].begin());
        }
    }
    
    return -1;
}

void VertexVectorAdjacencyList::updateData()
{
    for( int i = 0; i < m_nVertex; i++ )
    {
        // the vertex degree is its position in the vector
        m_vectorVertex[ m_arrAdjLists[i].size() ].insert( i );
    }
}
