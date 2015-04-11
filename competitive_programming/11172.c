#include <stdio.h>

int main(int argc, char *argv[]){
	
	int i, numLines=0, first, second;
	scanf("%d\n", &numLines);

	for(i=0; i<numLines; ++i){
		scanf("%d %d\n", &first, &second);	
		if (first < second)
			printf("<\n");
		else if (first > second)
			printf(">\n");
		else
			printf("=\n");
	}	
	return(0);

}