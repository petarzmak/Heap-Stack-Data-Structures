#include <stdio.h>
#include <stdlib.h>

/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

static int size = 0;
static int heap[100];

void printHeap(int i){
	
	printf("<node id = \"%d\">", heap[i]);
	if(2*i + 1 < size){
		printHeap(2*i + 1);
	} 
	if (2*i + 2 < size){
		printHeap(2*i + 2);
	}
	printf("</node>");
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
	int value = heap[0];
	for (int i = 1; i < size; i++){
		heap[i-1] = heap[i];
	}
	size--;
  return value;  //A dummy return statement
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
	size++;
	//heap[size] = 0;
	int i = 0;
	int temp;
	int temp2;
	for (i = 0; i <= size; i++){
		if (thing2add >= heap[i]){
			if(size != 1 || size != 0){
				temp = heap[i];
			}
			heap[i] = thing2add;
			
			break;
		}
	}

	if (size > 1 && i < size){
		int j;
		for (j = ++i; j <= size; j++){
			temp2 = heap[j];
			heap[j] = temp;
			temp = temp2;
		}
		heap[size] = '\0';
	}

}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;  
}
