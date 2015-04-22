#include<iostream>
#include<unordered_map>

using namespace std;

// find the characters that appear at least once in all strings passed
string findCommonChars(char *charArrays[], int numStrings){

	int i,j;
	unordered_map<int, int> myMap;

	// fill the map with the chars from the first string
	for(i=0; i<strlen(charArrays[0]); ++i){
		myMap[charArrays[0][i]] = 1;
	}

	// increment the value in the map if any of the other strings
	// has that character
	for(i=1; i<numStrings; ++i){
		for(j=0; j<strlen(charArrays[i]); ++j){
			if (myMap.count(charArrays[i][j]) == 1 && myMap[charArrays[i][j]] == i){
				myMap[charArrays[i][j]] += 1;
			}
		}
	}

	unordered_map<int, int>::iterator it;
	string commonChars;
	int pos = 0;

	// print the elements in the map that have a count equal to the number of strings
	for(it = myMap.begin(); it != myMap.end(); ++it){
		//printf("[%c] => [%d]\n", it->first, it->second);
		if (it->second == numStrings){
			commonChars[pos] = it->first;
			++pos;
		}
	}

	return commonChars;
}




int main(int argc, char** argv){
	char a[] = "Hello!askjh2l34";
	char b[] = "Whats 2op!";
	char c[] = "Good morn23ing!";

	char *array[3];
	array[0] = a;
	array[1] = b;
	array[2] = c;

	printf("The strings \n[%s] \n[%s] \n[%s] \nhave [%s] chars in common.\n", a, b, c, (findCommonChars(array, 3)).c_str());

	return 0;
}


