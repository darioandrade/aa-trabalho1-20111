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

    void addEdge( int iVertex, int jVertex, bool bUpdateNeighbor = true, bool bIncEdge = true );

protected:
    void Allocate( int nVertex );

    void DecrementDegree( int iVertex );
    void SetDegree( int iVertex, int degree );
    int GetDegree( int iVertex ) const;

    int GetHighestDegreeVertex( ) const;

private:
    int         * m_vectorDegrees;
};

#endif /* DEGREEVECTORADJACENCYLIST_H_ */
