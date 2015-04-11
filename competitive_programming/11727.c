#include <stdio.h>

int main(int argc, char *argv[]){

	int i, numLines=0, first, second, third;
	scanf("%d\n", &numLines);
	for(i=0; i<numLines; ++i){
		scanf("%d %d %d\n", &first, &second, &third);	
		if (first >= second){
			if(first >= third){
				if (second > third)
					printf("Case %d: %d\n", i+1, second);
				else
					printf("Case %d: %d\n", i+1, third);
			}else{
				printf("Case %d: %d\n", i+1, first);	
			}
		}else{
			if (second >= third){
				if (first >= third){
					printf("Case %d: %d\n", i+1, first);
				}else{
					printf("Case %d: %d\n", i+1, third);
				}
			}else{
				printf("Case %d: %d\n", i+1, second);
			}
		}	
	}	

	return(0);

}