#include <stdio.h>

int main(int argc, char *argv[]){

	struct Point {
   int x;
   int y;
	};
	
	int i, numLines=0, first, second;
	struct Point division;
	while( scanf("%d\n", &numLines)!=EOF && numLines!=0){
		scanf("%d %d\n", &division.x, &division.y);
		for(i=0; i<numLines; ++i){
			scanf("%d %d\n", &first, &second);	
			if (first == division.x || second == division.y)
				printf("divisa\n");
			else if (first > division.x && second > division.y)
				printf("NE\n");
			else if (first > division.x && second < division.y)
				printf("SE\n");
			else if (first < division.x && second > division.y)
				printf("NO\n");
			else if (first < division.x && second < division.y)
				printf("SO\n");
		}	
	}	

	return(0);

}