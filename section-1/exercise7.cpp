#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    string course;
    int registration;
};

int main()
{
    int NOfStudents;
    cin >> NOfStudents;

    Student students[10000]; // Supondo um limite máximo de 10000 students

    cin.ignore(); // Limpar a quebra de linha pendente
    for (int i = 0; i < NOfStudents; i++)
    {
        getline(cin, students[i].name);
        getline(cin, students[i].course);
        cin >> students[i].registration;
        cin.ignore();
    }

    string nameToBeFound;
    getline(cin, nameToBeFound);

    bool found = false;
    for (int i = 0; i < NOfStudents; i++)
    {
        if (students[i].name == nameToBeFound)
        {
            cout << students[i].name << endl;
            cout << students[i].course << endl;
            cout << students[i].registration << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Aluno nao localizado" << endl;
    }

    return 0;
}
