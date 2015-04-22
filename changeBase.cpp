#include<iostream>
#include<string>

using namespace std;

/**
 * Simple function changes the base of a number.
 */
int changeBase(int number, int fromBase, int toBase, bool debug = false){

	int multiplier = 1;
	int posMultiplier = 1;
	int baseOfIntegerType = 10;
	int reminder = 0;
	int result = 0;

	if (fromBase > toBase){

		while (number>0){

			// reminder of division
			reminder = number % toBase;

			// number that we have still to convert
			number = (number - reminder) / toBase;

			// end result in new base
			result += reminder * multiplier;

			// adjustment for bit significance
			multiplier *= baseOfIntegerType;
		}

	}else{

		if (toBase != 10){
			// shortcut to avoid handling addition in different bases
			result = changeBase(number, fromBase, 10);
			result = changeBase(result, 10, toBase);
		}else{

			while(number>0){
				reminder = number % fromBase;

				// result in corresponding base
				result += (reminder * multiplier);

				// remaining number to convert
				number = (number - reminder) / baseOfIntegerType;

				//
				multiplier *= fromBase;
			}

		}
	}

	return result;
}


int main (int argc, char** argv){

	int i,j;

	printf("number\t\t");
	for (j = 1; j<10; ++j){
		printf(" %d\t", j);
	}
	printf("\n");


	for (j = 2; j<10; ++j){
		printf("base=%d\t\t", j);
		for (int i=1; i<10; ++i)
        	{
        		printf("[%d]\t", changeBase(i, 10, j));
		}
		printf("\n");
	}


}