

#include <iostream>
#include <string>

using namespace std;

struct student
{
	int id;
	string name;
	int age;
};

student createStudent(int i)
{
	cout << "Creation of student " << i << endl;
	student newStudent;
	cout << "Insert student id " << i << endl;
	cin >> newStudent.id;
	cout << "Insert student name " << i << endl;
	cin >> newStudent.name;
	cout << "Insert student age " << i << endl;
	cin >> newStudent.age;
	return newStudent;
}

int binaryFindStudentById(student students[], int numberOfStudents, int id)
{
	int firstIndex = 0;
	int lastIndex = numberOfStudents;
	int halfIndex;
	int executions;

		halfIndex = (firstIndex + lastIndex) / 2;
		cout << "First half index: " << halfIndex << endl;
	while (students[halfIndex].id != id)
	{
		if(executions == numberOfStudents)
			return -1;
		halfIndex = (firstIndex + lastIndex) / 2;

		if (students[halfIndex].id == id)
		{
			cout << "Ended with " << executions << " executions" << endl;
			return halfIndex;
		}
		else
		{
			if (students[halfIndex].id < id)
			{
				firstIndex = halfIndex + 1;
				cout << "Ta na metade de cima" << endl;
			}
			else if(students[halfIndex].id > id)
			{
				lastIndex = halfIndex - 1;
				cout << "Ta na metade de baixo" << endl;
			}
		}
		executions++;
	}

	cout << "Ended with " << executions << " executions" << endl;
	return -1;
}



int findStudentById(student students[], int numberOfStudents, int id)
{
	for(int i = 0; i < numberOfStudents; i++){
		if(id == students[i].id){
			cout << "FOUND!" << endl;
			return i;
		}
	}
	return -1;
	
}

int findStudentByName(student students[], int numberOfStudents, string name)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		if (name == students[i].name)
		{
			return i;
		}
	}
	return -1;
}

int findStudentByAge(student students[], int numberOfStudents, int ageToFind)
{
	int counter = 0;
	for (int i = 0; i < numberOfStudents; i++)
	{
		if (ageToFind >= students[i].age)
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	// Entrar com a quantidade de estudantes
	int numberOfStudents;
	cout << "Insert number of students" << endl;
	cin >> numberOfStudents;

	student students[numberOfStudents];

	// Criar um array de tamanho N de structs de estudantes
	for (int i = 0; i < numberOfStudents; i++)
	{
		students[i] = createStudent(i);
	}

	// Declara uma matrícula para achar e busca através da função findStudentById
	int idToFind = 6;
	int queryResult = findStudentById(students, numberOfStudents, idToFind);

	// Se o find me retornou algo diferente de -1, printar
	if (queryResult != -1)
	{
		cout << students[queryResult].name << endl;
		cout << students[queryResult].id << endl;
		cout << students[queryResult].age << endl;
	}
	else
	{
		cout << "Couldn't find student :(" << endl;
	}

	// Declara um nome para achar e busca através da função findStudentByName
	string name = "Jonas";
	queryResult = findStudentByName(students, numberOfStudents, name);

	if (queryResult != -1)
	{
		cout << students[queryResult].name << endl;
		cout << students[queryResult].id << endl;
		cout << students[queryResult].age << endl;
	}
	else
	{
		cout << "Couldn't find student :(" << endl;
	}

	int ageToFind = 12;
	queryResult = findStudentByAge(students, numberOfStudents, ageToFind);

	cout << "There are " << queryResult << " student with less or equal age of this student" << endl;

	int idToFindBinary = 5;
	queryResult = binaryFindStudentById(students, numberOfStudents, idToFindBinary);

	if (queryResult != -1)
	{
		cout << students[queryResult].name << endl;
		cout << students[queryResult].id << endl;
		cout << students[queryResult].age << endl;
	}
	else
	{
		cout << "Binary search for id resulted in fail" << endl;
	}
	return 0;
}

// TODO: corrigir o erro da idade 
