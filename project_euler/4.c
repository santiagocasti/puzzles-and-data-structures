#include <stdio.h>
#include <math.h>
#include <string.h>

int isPalindrome(int n){

char foo[30];
sprintf(foo, "%i", n);
int len = strlen(foo);
for(int i=0; i< (floor(len/2)); i++){
	if (foo[i] != foo[len-(i+1)]){
		return 0;
	}
}

return 1;
}


int main(int argc, char *argv[]){

int a = 999, b = 999, res = 0;
int found = 0;

while(found == 0){
	res = a * b;
	if (isPalindrome(res) == 1){
		found = 1;
		continue;
	}
	
	//if (a == b){
		--a;
	//}else{
	//	--b;
	//}

}

printf("The number is %i * %i = %i\n", a, b, res);


a = 999; b = 0;
found = 0;
int largest = 0;
for (a=999; a>0; a--){
	for(b=999; b>0; b--){	
	res = a * b;
	if (isPalindrome(res) == 1){
		if (res > largest){
		 	largest = res;
			printf("Found %i * %i = %i\n", a, b, res);	
		}
	}

	}
}


printf("The number is %i\n", largest);




}