#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]){

	//printf("argc = %d\n", argc);
	//for(int i=0; i<argc; i++){
		//printf("argv[%d] = %s\n", argc, argv[i]);
	//}

	char c;
	bool first=true;
  while (scanf("%c",&c)!=EOF && c!=EOF){
		if(c == 34){
			if (first)
				printf("%c%c",96,96);
			else
				printf("%c%c",39,39);
			first = !first;
		}else{
			printf("%c", c);
		}
	}	
	return(0);

}