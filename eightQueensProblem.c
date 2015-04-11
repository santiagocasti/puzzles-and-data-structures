/**
 * Solution to a very well known problem.
 * http://en.wikipedia.org/wiki/Eight_queens_puzzle
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct position{
	int x;
	int y;
} position;

#define MAX_QUEENS 8

int totalSolutions = 0;

/**
 * Print a solution.
 */
void printSolution(position queens[MAX_QUEENS], int numQueens){
	printf("[%d] Positions", totalSolutions);
	int i;
	for(i = 0; i<numQueens; ++i){
		printf("[%d, %d]", queens[i].x+1, queens[i].y+1);
	}
	printf("\n");
}

/**
 * Function to check if putting a queen in position (x,y) does
 * violate any of the problem constrains.
 */
bool validPosition(position q[MAX_QUEENS], int x, int y){
	int i;
	//printf("%d) Checking if [%d, %d] is a valid position (", x, x, y);
	for (i=0; i<x; ++i){
		if ( q[i].y == y ||
			 abs(q[i].x - x) == abs(q[i].y - y)){

			int reason = 0;
			if (q[i].x == x) reason = 1;
			if (q[i].y == y) reason = 2;
			if (q[i].x - x == q[i].y - y){
				reason = 3;
				//printf("(q[i].x = %d) - (x = %d) = (%d)\n", q[i].x, x, q[i].x - x);	
				//printf("(q[i].y = %d) - (y = %d) = (%d)\n", q[i].y, y, q[i].y - y);
			} 

			//printf("FALSE[%d][%d]) - ", reason, i);
			//printSolution(q, x);
			return false;
		}
	}
	//printf("TRUE) - ");
	//printSolution(q, x);
	return true;
}

/**
 * Function to find the number of positions that 'MAX_QUEENS'
 * can be placed in a chess board of 'MAX_QUEENS' size.
 * The total count is tracked in a global variable called 'totalSolutions'.
 */
void findQueens(position q[MAX_QUEENS], int numQueens){

	if (numQueens >= MAX_QUEENS){
		totalSolutions++;
		printSolution(q, numQueens);
		return;
	}

	int i;
	for(i=0; i<MAX_QUEENS; ++i){

			if (validPosition(q, numQueens, i) == false){
				continue;
			}

			q[numQueens].x = numQueens;
			q[numQueens].y = i;

			findQueens(q, numQueens+1);
	}

}

int main(int argc, char **argv){

	position q[MAX_QUEENS];
	int i,j;
	for(i=0; i<MAX_QUEENS; i++){
		q[i].x = 0;
		q[i].y = 0;
	}

	findQueens(q, 0);

	printf("Num solutions: %d\n", totalSolutions);

}
