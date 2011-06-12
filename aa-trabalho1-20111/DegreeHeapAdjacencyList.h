#ifndef DEGREEHEAPADJACENCYLIST_H_
#define DEGREEHEAPADJACENCYLIST_H_

#include "AdjacencyList.h"
#include "Heap.h"

class DegreeHeapAdjacencyList : public AdjacencyList
{
public:
    DegreeHeapAdjacencyList ( );
    
    virtual ~DegreeHeapAdjacencyList ( );

    int RemoveHighestDegreeVertex( int debug );

protected:

    void updateData( );

private:
    Heap* m_heap;
};

#endif /* DEGREEHEAPADJACENCYLIST_H_ */
