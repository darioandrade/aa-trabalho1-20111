/*
 * DegreeVectorAdjacencyList.h
 *
 *  Created on: Jun 11, 2011
 *      Author: darioandrade
 */

#ifndef DEGREEVECTORADJACENCYLIST_H_
#define DEGREEVECTORADJACENCYLIST_H_

#include "AdjacencyList.h"

class DegreeVectorAdjacencyList : public virtual AdjacencyList
{
public:
    DegreeVectorAdjacencyList ( int nVertex );
    virtual ~DegreeVectorAdjacencyList ( );

    void addEdge( int iVertex, int jVertex );

private:
    int         * m_vectorDegrees;
};

#endif /* DEGREEVECTORADJACENCYLIST_H_ */
