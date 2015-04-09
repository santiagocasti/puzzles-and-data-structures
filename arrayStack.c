#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define STACKSIZE 20;

/*
 * Fixed size stack struct implemented using an array
 */
typedef struct stack_a{
	int stack[20];
	int top;
} StackArray;


/* Initialize the stack */
void init(StackArray* stack){
	stack->top = -1;
}

/* Return the stack size */
int size(StackArray *stack){
	return stack->top+1;
}

/*
 * Add an element to the stack adding it to the top
 * Returns the position where it was added.
 */
int* push(StackArray *stack, int element){
	if (size(stack)<40){
		stack->top++;
		stack->stack[stack->top] = element;
		printf("%d, pushed\n", stack->stack[stack->top]);
		return &(stack->top);
	}else{
		return NULL;
	}
}

/**
 * Returns the element on the top of the stack
 */
int* pop(StackArray* stack){
	if (size(stack)>0){
		stack->top--;
		printf("%d, poped\n",stack->stack[stack->top+1]);
		return &(stack->stack[stack->top+1]);
	}

	return NULL;
}

/**
 * Print to stdout the given stack element by element
 */
void printStack(StackArray* stack){
	int i=0;
	printf("The stack has the following elements: \n");
	for(i=0; i<size(stack); i++){
		printf("stack[%d] = %d\n",i,stack->stack[i]);
	}
	printf("\n");
}


int main(int argc, char* argv[]){

	StackArray *myStack;
	int i = 0, randInt = 0;
	
	//create the stack structure and initialize it
	myStack = (StackArray*)malloc(sizeof(StackArray));
	init(myStack);

	//random number generator
	srand(time(NULL));
	
	//push and pop elements :)
	for (i=0; i<20; i++){
		randInt = rand()%10;

		if(randInt>4){
			push(myStack, randInt);
		}else{
			pop(myStack);
		}

		printStack(myStack);
	}
}






















