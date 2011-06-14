# include <stdio.h>
#include "Heap.h"

int main(int argc, char * argv[])
{
	Heap heap(10);

	fprintf(stderr, "inserindo 0, 3\n");

	heap.insertOnHeap(0, 3);

	fprintf(stderr, "inserindo 1, 1\n");

	heap.insertOnHeap(1, 1);

	fprintf(stderr, "inserindo 2, 3\n");

	heap.insertOnHeap(2, 3);

	fprintf(stderr, "inserindo 3, 2\n");

	heap.insertOnHeap(3, 2);

	fprintf(stderr, "inserindo 4, 2\n");

	heap.insertOnHeap(4, 2);

	fprintf(stderr, "inserindo 5, 3\n");

	heap.insertOnHeap(5, 3);

	fprintf(stderr, "inserindo 6, 2\n");

	heap.insertOnHeap(6, 2);

	fprintf(stderr, "inserindo 7, 1\n");

	heap.insertOnHeap(7, 1);

	fprintf(stderr, "inserindo 8, 4\n");

	heap.insertOnHeap(8, 4);

	fprintf(stderr, "inserindo 9, 1\n");

	heap.insertOnHeap(9, 1);

	heap.print();
	fprintf(stderr, "\n");

	heap.DecrementDegree(2);

	heap.print();


	fprintf(stderr, "Removendo da heap:\n");


	for(int i = 0; i < 20; i++) {
		std::pair<int, int> element;
		heap.removeFromHeap(element);

		fprintf(stderr, "%d - vertex: %d - degree: %d\n", i, element.first, element.second);
	}

	return 0;
}
