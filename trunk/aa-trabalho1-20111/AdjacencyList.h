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
    int RemoveHighestDegreeVertex( int debug );

    int GetSize() const { return m_nVertex; }


protected:
    AdjacencyList( );
	virtual void Allocate( int nVertex );

    virtual void DecrementDegree( int iVertex ) { }
    virtual void SetDegree( int iVertex, int degree ) { }
    virtual int GetDegree( int iVertex ) const { return 0; }
    virtual int GetHighestDegreeVertex( ) const { return -1; }

private:

	int						m_nVertex;
	std::set< int >		    * m_arrAdjLists;

	int                     m_nEdges;
};

#endif /* ADJACENCYLIST_H_ */
