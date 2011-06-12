/*
 * AdjacencyList.h
 *
 *  Created on: May 28, 2011
 *      Author: darioandrade
 */

#ifndef ADJACENCYLIST_H_
#define ADJACENCYLIST_H_

#include <stdio.h>
#include <set>

class AdjacencyList {

public:

	AdjacencyList( int nVertex );
	virtual ~AdjacencyList( );

	virtual void addEdge( int iVertex, int jVertex, bool bUpdateNeighbor = true, bool bIncEdge = true );
	void write( FILE * f = NULL );
	void read( FILE * f = NULL, int debug = 0 );

	virtual bool HasEdge( ) const;
    virtual int RemoveHighestDegreeVertex( int debug ) { return -1; }

        int GetSize() const { return m_nVertex; }

		int GetDegree(int iVertex) { return (int)m_arrAdjLists[iVertex].size(); }


protected:
    AdjacencyList( );
	virtual void Allocate( int nVertex );
        virtual void updateData(){ }
        
	int						m_nVertex;
	std::set< int >		    * m_arrAdjLists;

	int                     m_nEdges;
};

#endif /* ADJACENCYLIST_H_ */
