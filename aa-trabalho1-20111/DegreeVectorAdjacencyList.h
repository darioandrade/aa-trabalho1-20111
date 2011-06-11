/*
 * DegreeVectorAdjacencyList.h
 *
 *  Created on: Jun 11, 2011
 *      Author: darioandrade
 */

#ifndef DEGREEVECTORADJACENCYLIST_H_
#define DEGREEVECTORADJACENCYLIST_H_

#include "AdjacencyList.h"

class DegreeVectorAdjacencyList : public AdjacencyList
{
public:
    DegreeVectorAdjacencyList ( );
    virtual ~DegreeVectorAdjacencyList ( );

    void addEdge( int iVertex, int jVertex, bool bUpdateNeighbor = true );

protected:
    void Allocate( int nVertex );

private:
    int         * m_vectorDegrees;
};

#endif /* DEGREEVECTORADJACENCYLIST_H_ */
