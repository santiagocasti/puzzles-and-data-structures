#include <stdio.h>
#include <stdlib.h>

typedef struct linkedLists{
	int value;
	struct linkedLists *next;
} LinkedList;


typedef struct prioQueue{
	int numElems;
	LinkedList **lists;
} PriorityQueue;

int add(int a, int b){
	return a+b;
}


int main(int argc, char* argv[]){
	printf("This is a very simple example of function pointers in C.\n");
	
	int (*pFunction)(int,int);
	pFunction = &add;
	
	printf("Adding 3 + 4 is equal to %d\n", pFunction(3,4));
}