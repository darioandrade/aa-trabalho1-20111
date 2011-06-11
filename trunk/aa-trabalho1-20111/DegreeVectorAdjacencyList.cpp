/*
 * DegreeVectorAdjacencyList.cpp
 *
 *  Created on: Jun 11, 2011
 *      Author: darioandrade
 */

#include "DegreeVectorAdjacencyList.h"

DegreeVectorAdjacencyList::DegreeVectorAdjacencyList ( int nVertex )
    : AdjacencyList( nVertex )
{
    m_vectorDegrees = new int [ nVertex ];

    for ( int i = 0; i < nVertex; i++ )
    {
        m_vectorDegrees[ i ] = 0;
    }
}

DegreeVectorAdjacencyList::~DegreeVectorAdjacencyList ( )
{
    delete [ ] m_vectorDegrees;
}

void DegreeVectorAdjacencyList::addEdge ( int iVertex, int jVertex )
{
    AdjacencyList::addEdge( iVertex, jVertex );

    m_vectorDegrees[ iVertex ] ++;
    m_vectorDegrees[ jVertex ] ++;
}

