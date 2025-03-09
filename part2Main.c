#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "intHeap.c" //remove this when done done
#include "intStack.c"
extern int pop();
extern void push(int);

int main(int argc, char * argv[])
{
	int value = 0;
	while (scanf("%d\n", &value) != EOF) {
		fprintf(stderr, "READING INPUT: %d\n", value);
		//
		addHeap(value);
	}
	printf("Printing heap values\n");
	printHeap(0);
	
	printf("\n\n");
	printf("Deleting from heap and pushing to stack\n");
	int k = size;
	for (int i = 0; i < k; i++){
		value = heapDelete();
		printf("%d\n", value);
		push(value);
	}
	
	printf("\n\n");
	printf("Popping from stack\n");
	for (int i = 0; i < k; i++){
		value = pop();
		printf("%d\n", value);
	}
  
	exit(0);
}
