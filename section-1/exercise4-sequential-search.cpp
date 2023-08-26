#include <iostream>
#include <string>

using namespace std;

int findValueById(int values[], int arraySize, int valueToFind){
	for (int i = 0; i < arraySize; i++){
		if (values[i] == valueToFind)
			return i;
	}

	return -1;
}

int main(){
	//Declaring a standard array size
	int arraySize = 100;

	//This is a temporary input value (if its -1, don't add it to the array)
	int inputValue = 0;
	int values[arraySize];

	// Loop of the value's inputs
	for (int i = 0; i < arraySize; i++){
		cin >> inputValue;
		if (inputValue != -1)
			values[i] = inputValue;
		else
			break;
	}

	int valueToFind;
	cin >> valueToFind;

	int foundId = findValueById(values, arraySize, valueToFind);

	if (foundId != -1)
		cout << valueToFind << " found on position " << foundId << endl;
	else
		cout << valueToFind << " not found" << endl;

	return 0;
}