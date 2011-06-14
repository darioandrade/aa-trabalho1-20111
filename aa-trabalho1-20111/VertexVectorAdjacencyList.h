#ifndef VERTEXVECTORADJACENCYLIST_H_
#define VERTEXVECTORADJACENCYLIST_H_

#include "AdjacencyList.h"

class VertexVectorAdjacencyList : public AdjacencyList
{
public:
    VertexVectorAdjacencyList();
    virtual ~VertexVectorAdjacencyList();

    int RemoveHighestDegreeVertex( int debug );

protected:
    void Allocate( int nVertex );
    void DecrementDegree( int iVertex );
    void RemoveFromVertexVector( int iVertex, int iDegree );
    ListNode* GetHighestDegreeVertex( );
    void updateData( );

private:
    
    int m_lastHighestDegree;
    List ** m_vectorVertex;
	ListNode ** m_elementList;
};

#endif /* DEGREEVECTORADJACENCYLIST_H_ */
