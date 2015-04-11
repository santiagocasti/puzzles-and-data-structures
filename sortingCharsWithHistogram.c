#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(char* array, int length){
	int i;
	for (i=0; i<length; i++)
		printf("%c",array[i]);
		
	printf("\n");
}

/**
 * Sort an array of chars in time O(n+k) and extra space O(k)
 * being k the number of different chars in the array and n the
 * length of the array.
 */
void sortArrayHistogram(char** array){
	//Assuming 25 characters alphabet
	//A = 65, Z=90, a=97, z=122
	char* pAux = *array;
	
	int letters[50] = {}, i, j, n, length = strlen(pAux);

	//count the number of occurrences of each letter
	for (i=0; i<length; i++, pAux++){
		if (*pAux <= 90){//if the letter is uppercase
			letters[*pAux-40]++;
		}else{ //if the letter is lowercase
			letters[*pAux-97]++;
		}
	}
	
	//get back to starting position
	pAux = *array;
	
	//Assign the values of the corresponding letter
	for (i=0; i<50; i++)
		if (letters[i]>0)
			for(j=0; j<letters[i]; j++, pAux++)
				*pAux = i < 25 ? 97+i : 40+i;
}

/**
 * Print the index in the array of the letter provided
 * It is assumed that the letter occurs in the array
 */
void printIndexOfLetter(char* array, char letter){
	int i;
	
	printf("The letter %c appears at: ",letter);
	
	for (i=0; i<strlen(array); i++)
		if (array[i] == letter)
			printf("%d,",i);
	
	printf("\n");

}


int main(int argc, char* argv[]){

	char str[10] = "EDCBAeBaaa";
	char *pStr = str;
	char **ppStr = &pStr;

	printArray(str, 10);

	sortArrayHistogram(ppStr);

	printArray(str, 10);

	printIndexOfLetter(str, 'B');

	printArray(str, 10);
}