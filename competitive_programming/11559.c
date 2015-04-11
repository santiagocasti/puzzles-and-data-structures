#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int i, numParticipants, budget, numHotels, numWeeks, pricePerWeekendPerPerson, bestPrice;
	int iNumFreeRooms, j;
	char sNumFreeRooms[4];
	
	while( scanf("%d %d %d %d\n", &numParticipants, &budget, &numHotels, &numWeeks)!=EOF){
		
		bestPrice = 1+(200 * 10000);

		for (i=0; i<numHotels; ++i){
			scanf("%d\n", &pricePerWeekendPerPerson);
			for (j=0; j< numWeeks; ++j){
				scanf("%s", &sNumFreeRooms);
				iNumFreeRooms = atoi(sNumFreeRooms);
				if (iNumFreeRooms >= numParticipants){
					if (bestPrice > (numParticipants * pricePerWeekendPerPerson) &&
					    budget >= (numParticipants * pricePerWeekendPerPerson)){
						bestPrice = (numParticipants * pricePerWeekendPerPerson);
					}
				}	
			}
			scanf("\n");
		}
		
		if (bestPrice == 1+(200*10000)){
                printf("stay home\n");
        }else{
                printf("%d\n", bestPrice);
        }	
	}	

	return(0);

}
