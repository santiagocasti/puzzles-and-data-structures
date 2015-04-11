#include <stdio.h>
#include <math.h>

int calcSumOfMultiples(int multiplier, int max, int divisible){
	int result = 0;
	int loopEnd = floor((max-1)/multiplier);
	printf("Loop end is: %i\n",loopEnd);
	for(int i=1; i <= loopEnd; ++i){
		if (divisible != 0 && i%divisible == 0){
			printf("Excluding: %i*%i=%i\n",i, multiplier, i*multiplier);
			continue;
		}
		printf("%i*%i = %i\n", multiplier, i, multiplier*i);
        	result += multiplier*i;
	}
	printf("\n");
	return result;
}

int main(int argc, char* argv[]){

	int totalSum = 0;

	totalSum += calcSumOfMultiples(5, 1000, 0) + calcSumOfMultiples(3, 1000, 5);

	printf("The total sum is %i\n", totalSum);
}
