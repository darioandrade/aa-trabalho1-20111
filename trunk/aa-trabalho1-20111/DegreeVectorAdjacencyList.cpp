/*
 * DegreeVectorAdjacencyList.cpp
 *
 *  Created on: Jun 11, 2011
 *      Author: darioandrade
 */

#include "DegreeVectorAdjacencyList.h"

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

void DegreeVectorAdjacencyList::addEdge ( int iVertex, int jVertex, bool bUpdateNeighbor )
{
    AdjacencyList::addEdge( iVertex, jVertex, bUpdateNeighbor );

    m_vectorDegrees[ iVertex ] ++;

    if ( bUpdateNeighbor )
    {
        m_vectorDegrees[ jVertex ] ++;
    }
}

