#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int numTestCases, i, iNumStudents, fastestStudent, j, iSpeedStudent;
	char sNumStudents[3], sSpeedStudent[5];
	
	while( scanf("%d\n", &numTestCases)!=EOF){

		for (i=0; i<numTestCases; ++i){
			
			scanf("%s", &sNumStudents);
			iNumStudents = atoi(sNumStudents);
			
			fastestStudent = 0;	
			for (j=0; j<iNumStudents; ++j){
				scanf("%s", &sSpeedStudent);
				iSpeedStudent = atoi(sSpeedStudent);
				if (iSpeedStudent >= fastestStudent){
					fastestStudent = iSpeedStudent;
				}	
			}
			scanf("\n");
			printf("Case %d: %d\n", (i+1), fastestStudent);
		}
	}	

	return(0);

}
