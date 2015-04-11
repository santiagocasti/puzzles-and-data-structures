#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
* Check whether character is included in string
*/
int contains(char character, char** string){
	int i;
	
	//printf("Does '%s' contains '%c'? ", (*string), character);
	
	for (i=0; i<strlen((*string)); i++){
		if (character == (*string)[i]){
			//printf("YES\n");
			return 1;
		}
	}
	//printf("NO\n");
	return 0;
}

/**
 * Reverse a given string
 */
void reverseString(char* string){
	char tmp;
	int i;
	for (i=0; i<strlen(string)/2; i++){
		tmp = string[i];
		string[i] = string[strlen(string)-i-1];
		string[strlen(string)-i-1] = tmp;
	}
}


/**
 * Count the number of 1 in the representation of an integer
 */
int countOnes(int number){
	int numOnes = 0;
	
	while (number>0){
		if (number & 1){
			numOnes++;
		}
		number = number >> 1;
	}
	
	return numOnes;

}

/**
 * Eliminate from phrase the chars indicated
*/
void eliminateChars(char **phrase, char** charsToEliminate){
	
	int j, q = 0;
	char *result = (char*)malloc(255*sizeof(char));
	
	//printf("We have to eliminate '%s' from '%s'.\n",(*charsToEliminate), (*phrase));
	
	for (j=0; j<strlen((*phrase)); j++){
		if (contains((*phrase)[j], charsToEliminate) == 0){
			result[q] = (*phrase)[j];
			q++;
		}
	}
	
	(*phrase) = result;  
}

//fin patterns in a string, returns the length of the longest string
int findPatterns(char** string, char** result){
	int patternLength = 0, i=0, j=0, maxPatternLength = 0;
	char *patternA, *patternB;
	
	//for each character in the string
	for (i=0; i<strlen(*string); i++){
		patternA = (*string)+i;
		patternB = (*string)+i+1;

		//printf("Starting with patternA(%c) and patternB(%c)\n", *patternA, *patternB);
		
		for (j=i+1; j<strlen(*string); j++){
		
			//find the next character that is equal
			while (((*patternB) != '\0') && ((*patternB) != (*patternA))) {
				patternB += 1;
			}
			
			//move pointers as the characters are equal
			while (((*patternA) == (*patternB)) && ((*patternB) != '\0') && (patternA != patternB)){
				patternLength += 1;
				patternA++;
				patternB++;
			}
			
			//if the pattern is longer than any previous store it
			if (patternLength>maxPatternLength){
				maxPatternLength=patternLength;
				strncpy((*result), (char*)(patternA-patternLength), patternLength);
			}
			
			patternLength = 0;
			patternA = (*string)+i;
			patternB = (*string)+j;
		}
	}
	
	return maxPatternLength;
}

//given a phrase, reverse the order of the words in the phrase
int reverseWords(char **phrase){

	typedef struct wordStack{
		char* word;
		struct wordStack *next;
	} WordStack;
	
	WordStack *stack = NULL, *aux = NULL;
	char* word;
	int i=0, end=0, start=0, words=0;
	
	printf("We have to reverse: %s\n", (*phrase));
	
	//put all the words found in the phrase in a stack
	for (i=0; i<strlen((*phrase)); i++){
		start = i;
		while ((*phrase)[i] != ' ' && (*phrase)[i] != '\0') {
			i++;
		}
		end = i;
		printf("word[%d]:%d->%d\n",i,start,end);
		aux = (WordStack*)malloc(sizeof(WordStack));
		aux->word = (char*)malloc((end-start)*sizeof(char));
		memcpy(aux->word, ((*phrase)+start), end-start);
		aux->next = stack;
		stack = aux;
		//count the number of words to return
		words++;	
	}
	
	//get the elements from the stack and add them to the char*
	//(*phrase) = (char*)malloc(strlen(phrase)*sizeof(char));
	i=0;
	while (stack != NULL){
		memcpy((*phrase)+i, stack->word, strlen(stack->word));
		i += strlen(stack->word);
		
		aux = stack;
		stack = stack->next;
		free(aux);

		(*phrase)[i] = ' ';
		i++;
	}
	phrase[i] = '\0';
	
	return words;

}

//return the integer representation of the string provided
int strToInt(char* string){
	
	int num = 0, actual = 0;
	int isNeg = 0;
	int length = strlen(string);
	
	if (string[0] == '-'){
		isNeg = 1;
		actual = 1;
	}
	
	
	while (actual < length){
		num *= 10;
		num += string[actual] - '0';
		actual++;
	}
	
	if (isNeg == 1)
		num *= -1;
	
	return num;
}

//return the string representation of the int provided
char* intToStr(int number){
	char *value = (char*)malloc(255*sizeof(char));
	int i=0;
	
	while (number>0){
		value[i] = number%10 + '0';
		number /= 10;
		i++;
	}
	value[i] = '\0';
	
	reverseString(value);
	
	return value;
	
}

//show a menu :)
void showMenu(){
	printf("Options:\n");
	printf("\t1 - Eliminate characters from a string\n");
	printf("\t2 - Find patterns in the given string\n");
	printf("\t3 - Reverse the words in the string\n");
	printf("\t4 - Convert string to int\n");
	printf("\t5 - Convert int to string\n");
	printf("\t6 - Count the number of ones\n");
	printf("\tX - Exit\n");
	printf("\t\tIntroduce an option :)\n");
}


int main(int argc, char* argv[]){

	char* phrase = (char*)malloc(255*sizeof(char));
	char* charsToEliminate = (char*)malloc(255*sizeof(char));
	char* result;
	char option;
	int value;
	
	result = (char*)malloc(255*sizeof(char));

	while (option != 'X'){
		showMenu();
		fgets(&option, 255, stdin);
		
		switch(option){
			case '1':
				printf("Introduce the string to process:");
				fgets(phrase,255,stdin);
				charsToEliminate = "aeiou";
				//printf("Introduce the characters to delete:");
				//scanf("%s\n",charsToEliminate);
				eliminateChars(&phrase, &charsToEliminate);
				printf("The resulting phrase is: %s", phrase);
				break;
			case '2':
				printf("Introduce the string to process:");
				fgets(phrase,255,stdin);
				//printf("Let's find some patterns.\n");
				printf("The longest pattern has %d characters and is '%s'.\n",findPatterns(&phrase, &result), result);
				break;
			case '3':
				printf("Introduce the string to process:");
				fgets(phrase,255,stdin);
				phrase[strlen(phrase)-1] = '\0';
				printf("There were found %d words and the resulting string is: \n%s\n",reverseWords(&phrase),phrase);
				break;
			case '4':
				printf("Introduce the string to process:");
				fgets(phrase,255,stdin);
				phrase[strlen(phrase)-1] = '\0';
				printf("The string |%s| is equal to %d\n", phrase, strToInt(phrase));
				break;
			case '5':
				printf("Introduce the int to process:");
				fgets(phrase,255,stdin);
				phrase[strlen(phrase)-1] = '\0';
				value = strToInt(phrase);
				printf("The int |%d| is equal to %s\n", value, intToStr(value));
				break;
			case '6':
				printf("Introduce the int to process:");
				fgets(phrase,255,stdin);
				phrase[strlen(phrase)-1] = '\0';
				value = strToInt(phrase);
				printf("The int |%d| has %d ones in its binary representation.\n", value, countOnes(value));
				break;
			case 'X':
				printf("Good Bye :)\n");
				break;
		}
		
		phrase[0] = '\0';
	}
	
}