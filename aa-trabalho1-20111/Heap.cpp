#include <math.h>

#include "Heap.h"

Heap::Heap(int nVertex)
:
	m_nVertex(nVertex),
	m_heapVector(NULL),
	m_indexerHeap(NULL),
	m_nextAvailableSlot(0)
{
	allocate();
}

Heap::~Heap()
{
	delete m_heapVector;
	delete m_indexerHeap;
}

void Heap::allocate()
{
	m_heapVector = new std::pair<int, int>[ m_nVertex ];
	m_indexerHeap = new int[ m_nVertex ];
	for (int i = 0; i < m_nVertex; i++)
	{
	    m_indexerHeap[i] = -1;
	}
}

 bool Heap::removeFromHeap(std::pair<int, int> & root)
{
	if (m_nextAvailableSlot > 0) {
		root = m_heapVector[0];

		std::pair<int, int> lastInserted = m_heapVector[m_nextAvailableSlot - 1];

		m_heapVector[0] = lastInserted;

		// element ja esta alocado no heapvector, para zerar eh so setar zero
		m_heapVector[m_nextAvailableSlot - 1].first = 0;// = *(new std::pair<int, int>(0, 0));
        m_heapVector[m_nextAvailableSlot - 1].second = 0;
		m_nextAvailableSlot--;

		// remove vertex from heap's index
		m_indexerHeap[root.first] = -1;

		bubleDownElement(0);

	} else {
		fprintf( stderr, "Error removing from empty heap.\n" );
		return false;
	}

	return true;
}

bool Heap::HasVertex(int iVertex) const
{
    return m_indexerHeap[iVertex] != -1;
}

void Heap::insertOnHeap(int iVertex, int degree)
{	
    m_heapVector[m_nextAvailableSlot].first = iVertex;
    m_heapVector[m_nextAvailableSlot].second = degree;

	// Fill indexer vector
	m_indexerHeap[iVertex] =  m_nextAvailableSlot;

	// we may need to use our current status in bubbleUpElement,
	// so we need to increment before calling the method below
	// do not move position
	m_nextAvailableSlot++;

	bubleUpElement(m_nextAvailableSlot - 1);
}


void Heap::DecrementDegree( int iVertex )
{
	m_heapVector[ m_indexerHeap[iVertex] ].second--;
	bubleDownElement(m_indexerHeap[iVertex]);
}

void Heap::bubleUpElement(int iSlotIndex)
{
	// First element don't have father
	if (iSlotIndex <= 0) {
		return;
	}

	// swap element with father
	if (swapWithFather(iSlotIndex)) {
		// if we had an inversion, call recursively for the father
		bubleUpElement((iSlotIndex - 1) / 2);
	}
}

bool Heap::swapWithFather(int iSlotIndex)
{
	std::pair<int, int> element = m_heapVector[iSlotIndex];

	// Compare with parent
	if (element.second > m_heapVector[(iSlotIndex - 1) / 2].second) {

		// swap with father
		std::pair<int, int> father = m_heapVector[(iSlotIndex - 1) / 2];

		m_heapVector[(iSlotIndex - 1) / 2] = element;
		m_heapVector[iSlotIndex] = father;

		m_indexerHeap[ element.first ] = (iSlotIndex - 1) / 2;
		m_indexerHeap[ father.first ] = iSlotIndex;
		
		return true;
	}

	return false;
}

void Heap::bubleDownElement(int iSlotIndex)
{
	// Last Nodes already had passed
	if (iSlotIndex >= m_nextAvailableSlot) {
		return;
	}

	int swapIndex = swapWithChildren(iSlotIndex);

	if (swapIndex == 1) {
		bubleDownElement(2 * iSlotIndex + 1);
	} else if (swapIndex == 2) {
		bubleDownElement(2 * iSlotIndex + 2);
	}

}

int Heap::swapWithChildren(int iSlotIndex)
{
	int higher = -1;
	int result = -1;

	int leftChildIndex = 2 * iSlotIndex + 1;
	int rightChildIndex = 2 * iSlotIndex + 2;

	if((leftChildIndex < m_nextAvailableSlot)  && (rightChildIndex < m_nextAvailableSlot)) {
		if (m_heapVector[iSlotIndex].second < m_heapVector[leftChildIndex].second &&
			m_heapVector[iSlotIndex].second < m_heapVector[rightChildIndex].second) {
			if (m_heapVector[leftChildIndex].second > m_heapVector[rightChildIndex].second) {
				higher = 2 * iSlotIndex + 1;
				result = 1;

			} else if (m_heapVector[rightChildIndex].second > m_heapVector[leftChildIndex].second) {
				higher = 2 * iSlotIndex + 2;
				result = 2;
			}
		}

		if (higher != -1) {
			// swap with child
			std::pair<int, int> child = m_heapVector[higher];
			std::pair<int, int> element = m_heapVector[iSlotIndex];

			m_heapVector[higher] = m_heapVector[iSlotIndex];
			m_heapVector[iSlotIndex] = child;

			m_indexerHeap[ element.first ] = higher;
			m_indexerHeap[ child.first ] = iSlotIndex;

			// 1 indicates that we swapped with left child
			return result;
		}
	}

	if (leftChildIndex < m_nextAvailableSlot) {
		// Compare with left child
		if (m_heapVector[iSlotIndex].second < m_heapVector[leftChildIndex].second) {
			std::pair<int, int> element = m_heapVector[iSlotIndex];
			// swap with child
			std::pair<int, int> child = m_heapVector[leftChildIndex];

			m_heapVector[leftChildIndex] = m_heapVector[iSlotIndex];
			m_heapVector[iSlotIndex] = child;

			m_indexerHeap[ element.first ] = leftChildIndex;
			m_indexerHeap[ child.first ] = iSlotIndex;

			// 1 indicates that we swapped with left child
			return 1;
		}
	}

	if (rightChildIndex < m_nextAvailableSlot) {
		if(m_heapVector[iSlotIndex].second < m_heapVector[rightChildIndex].second) {
			std::pair<int, int> element = m_heapVector[iSlotIndex];
			// swap with child
			std::pair<int, int> child = m_heapVector[rightChildIndex];

			m_heapVector[rightChildIndex] = m_heapVector[iSlotIndex];
			m_heapVector[iSlotIndex] = child;

			m_indexerHeap[ element.first ] = rightChildIndex;
			m_indexerHeap[ child.first ] = iSlotIndex;

			// 1 indicates that we swapped with left child
			return 2;
		}
	}

	return 0;
}

void Heap::print()
{
	fprintf(stderr, "Vertex: \n");
	for(int i = 0; i < m_nVertex; i++) {
		fprintf(stderr, " %d ", m_heapVector[i].first);
	}

	fprintf(stderr, "\nDegrees: \n");
	for(int i = 0; i < m_nVertex; i++) {
		fprintf(stderr, " %d ", m_heapVector[i].second);
	}
    fprintf(stderr, "\n");
}
