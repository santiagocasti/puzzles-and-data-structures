#include <stdio.h>
#include <string.h>

/**
 * Given a string, reverse it in-place.
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


int main(int argc, char* argv[]){

	int args = argc;
	int i = 0;

	// reverse any string in args
	if (argc > 0){
		while (args > 0){
			printf("%s - ",argv[i]);
			reverseString(argv[i]);
			printf("%s\n",argv[i]);
			args--;
			i++;
		}
	}

}
