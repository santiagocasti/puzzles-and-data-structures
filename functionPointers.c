#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
	return a+b;
}

int multiply(int a, int b){
	return a*b;
}


/**
 * Performs the operation provided with all the operands provided iteratively.
 */
int accumulate(int (*op)(int,int), int* operands, int numOperands){

	printf("numOperands: %d\n", numOperands);

	if (numOperands == 0) //if zero
		return 0;
	else if (numOperands == 1) //if just one
		return operands[0];
	else{ //if more than one

		int i, result = op(operands[0], operands[1]);
		printf("0) result: %d\n", result);

		//execute the operand
		for (i=2; i<numOperands; i++){
			result = op(result, operands[i]);
			printf("%d) result: %d\n", i, result);
		}

		return result;
	}

}

int main(int argc, char* argv[]){
	printf("This is a very simple example of function pointers in C.\n");

	// Simple example
	int (*pFunction)(int,int);
	pFunction = &add;
	printf("Adding 3 + 4 is equal to %d\n", pFunction(3,4));


	// More complex example
	int (*op)(int,int);
	int operands[5] = { 1, 2, 3, 4, 5 };
	op = &add;
	printf("The result of operating addition with {1,2,3,4,5} is %d.\n", accumulate(op, operands, 5));
	op = &multiply;
	printf("The result of operating multiplication with {1,2,3,4,5} is %d.\n", accumulate(op, operands, 5));
}