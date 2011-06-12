#include <stdio.h>

#include <utility>

#include "AdjacencyList.h"

class Heap 
{
public:
	Heap(int nVertex);
	~Heap();

	void insertOnHeap(int iVertex, int degree);
	bool removeFromHeap(std::pair<int, int> & highestPair);

	void print();
private:
	void allocate();
	void balanceHeap();
	bool swapWithFather(int iSlotIndex);
	void bubleUpElement(int iSlotIndex);
	void bubleDownElement(int iSlotIndex);
	int swapWithChildren(int iSlotIndex);

	
	int m_nVertex;

	// Vector of [vertex, degree] pairs
	std::pair<int, int> * m_heapVector;

	int m_nextAvailableSlot;

};
