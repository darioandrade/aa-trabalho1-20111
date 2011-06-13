#include "Heap.h"

Heap::Heap(int nVertex)
:
	m_nVertex(nVertex),
	m_heapVector(NULL),
	m_nextAvailableSlot(0)
{
	allocate();
}

Heap::~Heap()
{
	// Does nothing
}

void Heap::allocate()
{
	m_heapVector = new std::pair<int, int>[ m_nVertex ];
}

 bool Heap::removeFromHeap(std::pair<int, int> & root)
{
	if (m_nextAvailableSlot > 0) {
		root = m_heapVector[0];

		std::pair<int, int> lastInserted = m_heapVector[m_nextAvailableSlot - 1];

		m_heapVector[0] = lastInserted;

		m_heapVector[m_nextAvailableSlot - 1] = *(new std::pair<int, int>(0, 0));
		m_nextAvailableSlot--;

		bubleDownElement(0);

	} else {
		fprintf( stderr, "Error removing from empty heap.\n" );
		return false;
	}

	return true;
}

void Heap::insertOnHeap(int iVertex, int degree)
{
	std::pair<int, int> * element = new std::pair<int, int>(iVertex, degree);

	m_heapVector[m_nextAvailableSlot] = *element;
	m_nextAvailableSlot++;

	bubleUpElement(m_nextAvailableSlot - 1);
}


void Heap::DecrementDegree( int iVertex )
{
	int i = 0;

	for(; i < m_nVertex; i++) {
		// Search iVertex
		if (m_heapVector[i].first == iVertex) {
			// Decrement degree
			m_heapVector[i].second--;
			break;
		}
	}

	bubleDownElement(i);
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
	// Compare with parent
	if (m_heapVector[iSlotIndex].second > m_heapVector[(iSlotIndex - 1) / 2].second) {

		// swap with father
		std::pair<int, int> father = m_heapVector[(iSlotIndex - 1) / 2];

		m_heapVector[(iSlotIndex - 1) / 2] = m_heapVector[iSlotIndex];
		m_heapVector[iSlotIndex] = father;

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

	if (m_heapVector[iSlotIndex].second < m_heapVector[(2 * iSlotIndex + 1)].second &&
		m_heapVector[iSlotIndex].second < m_heapVector[(2 * iSlotIndex + 2)].second) {
		if (m_heapVector[(2 * iSlotIndex + 1)].second > m_heapVector[(2 * iSlotIndex + 2)].second) {
			higher = 2 * iSlotIndex + 1;
			result = 1;

		} else if (m_heapVector[(2 * iSlotIndex + 2)].second > m_heapVector[(2 * iSlotIndex + 1)].second) {
			higher = 2 * iSlotIndex + 2;
			result = 2;
		}
	}

	if (higher != -1) {
		// swap with child
		std::pair<int, int> child = m_heapVector[higher];

		m_heapVector[higher] = m_heapVector[iSlotIndex];
		m_heapVector[iSlotIndex] = child;

		// 1 indicates that we swapped with left child
		return result;
	}

	// Compare with left child
	if (m_heapVector[iSlotIndex].second < m_heapVector[(2 * iSlotIndex + 1)].second) {

		// swap with child
		std::pair<int, int> child = m_heapVector[(2 * iSlotIndex + 1)];

		m_heapVector[(2 * iSlotIndex + 1)] = m_heapVector[iSlotIndex];
		m_heapVector[iSlotIndex] = child;

		// 1 indicates that we swapped with left child
		return 1;
	} else if(m_heapVector[iSlotIndex].second < m_heapVector[(2 * iSlotIndex + 2)].second) {
		// swap with child
		std::pair<int, int> child = m_heapVector[(2 * iSlotIndex + 2)];

		m_heapVector[(2 * iSlotIndex + 2)] = m_heapVector[iSlotIndex];
		m_heapVector[iSlotIndex] = child;

		// 1 indicates that we swapped with left child
		return 2;
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