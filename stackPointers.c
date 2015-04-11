#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 40

typedef struct stack_e{
	int value;
	struct stack_e *next;
} StackElem;

typedef struct stack_p{
	StackElem *top;
	int numElems;
} StackPointer;

/*Init the stack*/
void init(StackPointer* stack){
	stack->numElems = 0;
	stack->top = NULL;
}

/*Create a new Stack*/
StackPointer* newStack(){
	StackPointer *stack;
	//init the stack structure
	stack = (StackPointer*)malloc(sizeof(StackPointer));
	// initialize the structure
    init(stack);

    return stack;
}

/*Return the stack size*/
int size(StackPointer *stack){
	return stack->numElems;
}

/*Add an element to the stack adding it to the top
  Returns the position where it was added.*/
int push(StackPointer *stack, int element){
	if ( size(stack) < STACK_SIZE ){
		//create the new element
		StackElem *newElement;
		newElement = (StackElem*)malloc(sizeof(StackElem));
		newElement->value = element;
		newElement->next = stack->top;
		
		//add it to the top of the stack
		stack->top = newElement;
		
		//increment the # of elements
		stack->numElems++;

		printf("%d, pushed\n", stack->top->value);
		return stack->top->value;
	}else{
		return -1;
	}
}

/*Returns the element on the top of the stack*/
int pop(StackPointer* stack){
	if (size(stack)>0){
		//recover the element
		int element = stack->top->value;
		
		//free the element
		StackElem *aux = stack->top;
		stack->top = stack->top->next;
		free(aux);
		
		stack->numElems--;
		
		printf("%d, poped\n",element);
		return element;
	}else{
		return -1;
	}
}

void printStack(StackPointer* stack){
	int i=0;
	printf("The stack has the following elements: \n");

	StackElem *aux = stack->top;

	// print following the numElems indicator in the StackPointer object
//	for (int i = 0; i<stack->numElems; ++i){
//		printf("\t\tstack[%d] = %d\n",i,aux->value);
//		aux = aux->next;
//	}

	// print following the pointers and ending when NULL found
	while(aux != NULL){
		printf("\t\tstack[%d] = %d\n",i,aux->value);
		aux = aux->next;
		i++;
	}
	printf("\n");
}


int main(int argc, char* argv[]){
	StackPointer *myStack;
	int i = 0, randInt = 0;

	//random number generator
	srand(time(NULL));

	myStack = newStack();
	
	//push and pop elements randomly
	for (i=0; i<20; i++){
		randInt = rand()%10;

		if (randInt > 5){
			push(myStack, randInt);
		}else{
			pop(myStack);
		}

		printStack(myStack);
	}
}






















