# include <stdio.h>
#include "Heap.h"

int main(int argc, char * argv[])
{
	Heap heap(20);

	fprintf(stderr, "inserindo 0, 4\n");

	heap.insertOnHeap(0, 4);

	fprintf(stderr, "inserindo 1, 3\n");

	heap.insertOnHeap(1, 3);

	fprintf(stderr, "inserindo 2, 4\n");

	heap.insertOnHeap(2, 4);

	fprintf(stderr, "inserindo 3, 3\n");

	heap.insertOnHeap(3, 3);

	fprintf(stderr, "inserindo 4, 2\n");

	heap.insertOnHeap(4, 2);

	fprintf(stderr, "inserindo 5, 5\n");

	heap.insertOnHeap(5, 5);

	fprintf(stderr, "inserindo 6, 8\n");

	heap.insertOnHeap(6, 8);

	fprintf(stderr, "inserindo 7, 3\n");

	heap.insertOnHeap(7, 3);

	fprintf(stderr, "inserindo 8, 6\n");

	heap.insertOnHeap(8, 6);

	fprintf(stderr, "inserindo 9, 3\n");

	heap.insertOnHeap(9, 3);

	fprintf(stderr, "inserindo 10, 4\n");

	heap.insertOnHeap(10, 4);

	fprintf(stderr, "inserindo 11, 1\n");

	heap.insertOnHeap(11, 1);

	fprintf(stderr, "inserindo 12, 3\n");

	heap.insertOnHeap(12, 3);

	fprintf(stderr, "inserindo 13, 4\n");

	heap.insertOnHeap(13, 4);

	fprintf(stderr, "inserindo 14, 4\n");

	heap.insertOnHeap(14, 4);

	fprintf(stderr, "inserindo 15, 3\n");

	heap.insertOnHeap(15, 3);

	fprintf(stderr, "inserindo 16, 7\n");

	heap.insertOnHeap(16, 7);

	fprintf(stderr, "inserindo 17, 5\n");

	heap.insertOnHeap(17, 5);

	fprintf(stderr, "inserindo 18, 0\n");

	heap.insertOnHeap(18, 0);

	fprintf(stderr, "inserindo 19, 6\n");

	heap.insertOnHeap(19, 6);

	fprintf(stderr, "Removendo da heap:\n");


	for(int i = 0; i < 20; i++) {
		std::pair<int, int> element;
		heap.removeFromHeap(element);
		
		fprintf(stderr, "%d - vertex: %d - degree: %d\n", i, element.first, element.second);
	}
	return 0;
}
