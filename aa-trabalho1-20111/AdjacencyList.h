/*
 * AdjacencyList.h
 *
 *  Created on: May 28, 2011
 *      Author: darioandrade
 */

#ifndef ADJACENCYLIST_H_
#define ADJACENCYLIST_H_

#include <stdio.h>
#include <list>

class AdjacencyList {

public:

	AdjacencyList( int nVertex );
	virtual ~AdjacencyList( );

	virtual void addEdge( int iVertex, int jVertex );
	void write( FILE * f = NULL );
	void read( FILE * f = NULL, int debug = 0 );

private:

	int						m_nVertex;
	std::list< int >		* m_arrAdjLists;
};

#endif /* ADJACENCYLIST_H_ */
