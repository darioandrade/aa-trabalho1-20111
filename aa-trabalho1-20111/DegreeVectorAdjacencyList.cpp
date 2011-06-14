/*
 * DegreeVectorAdjacencyList.cpp
 *
 *  Created on: Jun 11, 2011
 *      Author: darioandrade
 */

#include "DegreeVectorAdjacencyList.h"
#include "Heap.h"

DegreeVectorAdjacencyList::DegreeVectorAdjacencyList (  )
{
}

DegreeVectorAdjacencyList::~DegreeVectorAdjacencyList ( )
{
    delete [ ] m_vectorDegrees;
}

void DegreeVectorAdjacencyList::Allocate( int nVertex )
{
    AdjacencyList::Allocate( nVertex );

    m_vectorDegrees = new int [ nVertex ];

    for ( int i = 0; i < nVertex; i++ )
    {
        m_vectorDegrees[ i ] = 0;
    }
}

void DegreeVectorAdjacencyList::addEdge ( int iVertex, int jVertex, bool bUpdateNeighbor, bool bIncEdge )
{
    AdjacencyList::addEdge( iVertex, jVertex, bUpdateNeighbor, bIncEdge );

    m_vectorDegrees[ iVertex ] ++;

    if ( bUpdateNeighbor )
    {
        m_vectorDegrees[ jVertex ] ++;
    }
}

void DegreeVectorAdjacencyList::DecrementDegree( int iVertex )
{
    m_vectorDegrees[ iVertex ] --;
}

void DegreeVectorAdjacencyList::SetDegree( int iVertex, int degree )
{
    m_vectorDegrees[ iVertex ] = degree;
}

int DegreeVectorAdjacencyList::GetDegree( int iVertex ) const
{
    return m_vectorDegrees[ iVertex ];
}

int DegreeVectorAdjacencyList::GetHighestDegreeVertex( ) const
{
    int highestDegree = 0;
    int iHighestDegreeVertex = -1;

    // iterate over the degree vector and find highest degree vector
    for ( int i = 0; i < GetSize( ); i++ )
    {
        // swap if higher
        if ( m_vectorDegrees[ i ] > highestDegree )
        {
            highestDegree = m_vectorDegrees[ i ];
            iHighestDegreeVertex = i;
        }
    }

    // if no degree > 0, vertex returned will be -1 (no vertex)
    return iHighestDegreeVertex;
}


int DegreeVectorAdjacencyList::RemoveHighestDegreeVertex( int debug )
{
    int iHighestDegreeVertex = GetHighestDegreeVertex( );

    // find neighbors of this vertex
    List * neighbors = m_arrAdjLists[ iHighestDegreeVertex ];

    if ( debug >= 2 )
    {
        fprintf( stderr, "  vertice %d tem %d vizinhos e grau: %d\n",
                 iHighestDegreeVertex,
                 neighbors->size( ),
                 GetDegree( iHighestDegreeVertex ) );
    }

    for ( ListNode * node = neighbors->getFirst();
		node != NULL;
		node = node->next())
    {
        int iNeighbor = node->getContent();

        // update this vertex's neighbor's list that this vertex is being removed
        // DATS: Nao eh mais necessario tirar o vizinho da listsa
        // de adjacencias do vertice que estamos tirando
        //m_arrAdjLists[ iNeighbor ]->erase( iHighestDegreeVertex );

        // remove edge from this vertex
        m_nEdges --;

        // decrement degree from neighbor
        DecrementDegree( iNeighbor );        
    }

    // remove edges to neighbors, and let the vertex linger and ...
    //neighbors.clear( );
    // reset degree
    SetDegree( iHighestDegreeVertex, 0 );

    return iHighestDegreeVertex;
}
