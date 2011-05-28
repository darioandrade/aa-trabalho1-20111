/*
 * AdjacencyList.cpp
 *
 *  Created on: May 28, 2011
 *      Author: darioandrade
 */

#include "AdjacencyList.h"

AdjacencyList::AdjacencyList ( int nVertex )
{
    m_nVertex = nVertex;

    m_arrAdjLists = new std::list<int>[nVertex];
}

AdjacencyList::~AdjacencyList ( )
{
    delete[] m_arrAdjLists;
}

void AdjacencyList::addEdge ( int iVertex, int jVertex )
{
    m_arrAdjLists[iVertex].push_back( jVertex );
    m_arrAdjLists[jVertex].push_back( iVertex );
}

// print edges, one vertex each line, to stdout
void AdjacencyList::write ( FILE* f )
{
    if ( f == NULL )
    {
        f = stdout;
    }

    // run all vertex
    for ( int i = 0; i < m_nVertex; i++ )
    {
        // iterate through edges
        for ( std::list<int>::iterator it = m_arrAdjLists[i].begin( ); it != m_arrAdjLists[i].end( ); it++ )
        {
            fprintf( f, "%d ", *it );
        }

        fputs( "\n", f );
    }
}

