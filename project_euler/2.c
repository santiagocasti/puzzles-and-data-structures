#include <stdio.h>
#include <math.h>



int main(int argc, char* argv[]){

int max = 4000000;
int n1 = 1; int n2 = 2;
int sum = 2;

while (n2 < max && n1 < max){
	n2 = n1 + n2;
	if (n2%2 == 0){
		sum += n2;
		printf("adding[%i]\n", n2);
	}
	printf("%i+%i = %i\n", n1, n2-n1, n2);
	n1 = n2-n1;
}

printf("Total = %i\n", sum);

}
