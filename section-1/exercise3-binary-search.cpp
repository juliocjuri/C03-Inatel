/*
 * 1) Create a function that receives a student's registration number and returns their information
 * using binary search. Is it possible to create a binary search function that receives a student's
 * registration number and returns their information? If not, what would be the alternatives?
 * Justify your answer.
 *
 * Yes, it is possible to create. The answer is in the code below. In it, we can perform this search,
 * but the registration numbers must be in ascending order.
 *
 * 2) Create a function that receives a student's name and returns their information.
 * Is it possible to create a binary search function that receives a student's name and
 * returns their information? Justify your answer. If not, what would be the alternatives?
 * Justify your answer.
 *
 * It is not possible because it is not feasible to sort names in ascending order.
 * Therefore, the search would result in failures.
 *
 * 3) Create a function that receives an integer value indicating an age and returns the
 * quantity of students who are that age or younger. Is it possible to create a binary
 * search function that receives a student's age and returns the requested sum? If not,
 * what would be the alternatives? Justify your answer.
 *
 * It's not possible because we cannot traverse all the students using binary search.
 */

#include <iostream>
#include <string>

using namespace std;

// Definition of the 'student' structure that stores information about a student
struct student
{
    int id;
    string name;
    int age;
};

// Function to create a new student with information entered by the user
student createStudent(int i)
{
    cout << "Creating student " << i << endl;
    student newStudent;
    cout << "Insert student's ID: " << endl;
    cin >> newStudent.id;
    cout << "Insert student's name: " << endl;
    cin >> newStudent.name;
    cout << "Insert student's age: " << endl;
    cin >> newStudent.age;
    return newStudent;
}

// Function to print student data
void printStudentData(student students[], int index)
{
    cout << "Id: " << students[index].id << endl;
    cout << "Name: " << students[index].name << endl;
    cout << "Age: " << students[index].age << endl;
}

// Binary search for students id
int binaryFindStudentById(student students[], int numberOfStudents, int id)
{
    int arrayBeginningIndex = 0;
    int arrayFinishingIndex = numberOfStudents - 1;
    int arrayMiddleIndex;
    int executions = 0;

    arrayMiddleIndex = (arrayBeginningIndex + arrayFinishingIndex) / 2;
    // Binary search loop

    do
    {
        arrayMiddleIndex = (arrayBeginningIndex + arrayFinishingIndex) / 2; // Update the middle index

        // Check if student's ID at the middle index is equal to the searched ID
        if (students[arrayMiddleIndex].id == id)
        {
            cout << "Search ended after " << executions << " executions" << endl;
            return arrayMiddleIndex; // Return the index where the student was found
        }
        else
        {
            // Update the indexes of the first and last elements in the search range
            if (students[arrayMiddleIndex].id < id)
                arrayBeginningIndex = arrayMiddleIndex + 1;
            else if (students[arrayMiddleIndex].id > id)
                arrayFinishingIndex = arrayMiddleIndex - 1;
        }
        executions++; // Increment the execution counter
    } while (arrayBeginningIndex <= arrayFinishingIndex);

    // Display the number of executions and return -1 to indicate that the student was not found
    cout << "Search ended after " << executions << " executions" << endl;
    return -1;
}

int main()
{
    int registrationToFindBinary = 5; // Student's ID to be searched using binary search

    int numberOfStudents;
    cout << "Enter the number of students: " << endl;
    cin >> numberOfStudents; // Enter the number of students

    student students[numberOfStudents]; // Creating an array of students

    // Loop to create and input information for each student
    for (int i = 0; i < numberOfStudents; i++)
        students[i] = createStudent(i);

    // Perform binary search for the student with the specified ID
    int queryResult = binaryFindStudentById(students, numberOfStudents, registrationToFindBinary);

    // Check if the search result was successful or not
    if (queryResult != -1)
        printStudentData(students, queryResult); // Print the data of the found student
    else
        cout << "Binary search for ID " << registrationToFindBinary << " failed" << endl;

    return 0;
}
