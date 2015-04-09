/**
 * The problem goes more or less as follows:
 * 		Implement a function that returns 1 with probability 1/2^n
 *		Bellow you can see my implementation and the implementation
 *		suggested by the interviewer. Both are correct.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
 * This was my implementation in 30 minutes
 */
int calculateProbSantiago(int n){
	int random;
	float prob;
	
	if (n==0){
		return 0;
	}else{
		prob = (1/pow(2,n))*RAND_MAX;
		random = rand()%RAND_MAX;
		
		if (random<=prob)
			return 1;
		else
			return 0;
	}
}

/**
 * This was the interviewer suggestion at the end of the interview.
 * I implemented it to try it out and see how it compares to mine.
 */
int calculateProbInterviewer(int n){
	int random;
	float prob;
	
	if (n==0){
		return 0;
	}else{
		
		while(n>0){
			random = rand()%2;
			if (random == 0)
				return 0;
			n--;
		}
		
		return 1;
	}
}



int main(int argc, char* argv[]){
	int i = 0, iterations = 10000000;
	int zeros=0, ones=0, prob = 1;
	time_t before, after;
	
	srand(time(NULL));
	
	
	while (i<iterations){
		if (calculateProbSantiago(prob))
			ones++;
		else
			zeros++;
		++i;
	}
	
	printf("For calculateProbSantiago(%i) after %i iterations, we counted %i ones and %i zeros\n", prob, iterations, ones, zeros);


	ones = zeros = i = 0;

	while (i<iterations){
		if (calculateProbInterviewer(prob))
			ones++;
		else
			zeros++;
		++i;
	}
	
	printf("For calculateProbInterviewer(%i) after %i iterations, we counted %i ones and %i zeros\n", prob, iterations, ones, zeros);

	
	
}