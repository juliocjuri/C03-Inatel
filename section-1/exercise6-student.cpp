#include <iostream>
#include <string>

using namespace std;

//O(logn)
int searchStudentCorridorByRegistration(int registration, int studentsRegistrtion[], int totalStudentRegistrations){
    int firstIndex = 0;
    int lastIndex = totalStudentRegistrations;
    int halfIndex = (firstIndex + lastIndex) / 2;

    while(firstIndex <= lastIndex){
        if(studentsRegistrtion[halfIndex] == registration){
            return halfIndex;
        }
        else {
		if(registration > studentsRegistrtion[halfIndex]){
                firstIndex = halfIndex + 1;
                halfIndex = (firstIndex + lastIndex) / 2;
            }else{
                lastIndex = halfIndex - 1;
                halfIndex = (firstIndex + lastIndex) / 2;
            }
        }
    }

    return -1;
}

int main(){
    int totalStudentRegistrations;
    cin >> totalStudentRegistrations;

    int studentsRegistration[totalStudentRegistrations];

    for(int i = 0; i < totalStudentRegistrations; i++){
        cin >> studentsRegistration[i];
    }
    

    int studentRegistrationToBeFound;
    cin >> studentRegistrationToBeFound;
	int registrationIndex = searchStudentCorridorByRegistration(studentRegistrationToBeFound, studentsRegistration, totalStudentRegistrations);

	if(registrationIndex != -1)
		cout << "Corredor " << registrationIndex << endl;
	else
		cout << "Nao localizado" << endl;
}