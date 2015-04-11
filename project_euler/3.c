#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPrime(long n){
	printf("Is %ld prime? ", n);
	for (int i=2; i<(n-1); ++i){
		if (n%i == 0){
			printf("NO!\n");
			return 0;
		}
	}
	
	printf("YES!\n");
	return 1;
}


long factorize(long *n){
long a = *n;
for (long i=2; i<=a; i++){
	//printf("%ld mod %ld == %ld\n",a,i,a%i);
	if (a%i == 0){
		*n = a/i;
		return i;
	}
}
return 0;
}





int main(int argc, char* argv[]){

long n = 148;
if (argc == 2){
	n = atol(argv[1]);
}

printf("Number is %ld\n", n);

while(n>1){
	printf("%ld - %ld\n", factorize(&n), n);	
}

}
