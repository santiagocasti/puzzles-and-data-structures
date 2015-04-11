#include <stdio.h>
#include <stdbool.h>



bool shouldContinue(int currentMonth, int maxMonth, float monthlyPayment, float currentDepreciation, float *carPrice, float *loanAmount){

for(; currentMonth<maxMonth; ++currentMonth){

	*carPrice -= (*carPrice)*currentDepreciation;

	if (*carPrice > *loanAmount){
		printf("%d %s\n", currentMonth, currentMonth == 1? "month" : "months");
		return true;
	}

	*loanAmount -= monthlyPayment;
}

return false;

}


int main(int argc, char *argv[]){

	bool inputLeft = true, haltLoop = false, initialLoop;
	float downPayment, monthlyPayment, loanAmount, carPrice, currentDepreciation, depreciation;
	int i, j, duration, records, month, currentMonth;

	while (inputLeft){

		scanf("%d %f %f %d\n", &duration, &downPayment, &loanAmount, &records);
		inputLeft = duration > 0 ? true : false;
		initialLoop = true;
		haltLoop = false;
		carPrice = loanAmount + downPayment;
		monthlyPayment = loanAmount / duration;

		for(i=0; i<records && inputLeft; ++i){
			scanf("%d %f\n", &month, &depreciation);
			if (!initialLoop){
				haltLoop = shouldContinue(currentMonth, month, monthlyPayment, currentDepreciation, &carPrice, &loanAmount);
			}else{
				initialLoop = false;
			}
			currentMonth = month;
			currentDepreciation = depreciation;

			if (i == (records-1) && !haltLoop){
				while (!haltLoop){
					haltLoop = shouldContinue(currentMonth, 101, monthlyPayment, currentDepreciation, &carPrice, &loanAmount);
				}
			}
		}
	}

	return(0);

}