/*
* 1) Crie uma funcao que receba o nuemro de
* matricula de um aluno e retorne suas informacoes
* usando a busca binaria. E possivel criar uma funcao de
* busca binaria que receba a matricula de um aluno e retorne suas informacoes?
* Caso negativo, quais seriam as alternativas? Justifique sua resposta.
* 
* Sim é possivel criar. A resposta esta no codigo abaixo. Nele, conseguimos fazer essa busca
* Porem deve estar em ordem crescente as matriculas
*
* 2) Crie uma funcao que receba o nome de um aluno e retorne suas informacoes.
* E possivel criar uma funcao de busca binaria que receba o nome de um aluno e
* retorne suas informacoes? Justifique sua resposta. Caso negativo, quais seriam
* as alternativas? Justifique sua resposta.
*
* Não há como pois não é possível ordenar os nomes em ordem crescente
* Logo a busca resultara em falhas
* 
* 3) Crie uma funcao que receba um valor inteiro indicando uma idade e retorne a
* quantidade de alunos que tem essa idade ou menos. E possivel criar uma funcao de
* busca binaria que receba a idade de um aluno e retorne a  soma pedida? Caso negativo,
* quais seriam as alternativas? Justifique sua resposta.
*
* Nao e possivel pois nao conseguimos percorrer a todos os estudantes utilizando a busca binaria
*/

#include <iostream>
#include <string>

using namespace std;

// Definio da estrutura 'student' que armazena informacoes de um aluno
struct student
{
    int matricula;
    string nome;
    int idade;
};

// Funcao para criar um novo aluno com informacoes inseridas pelo usuario
student createStudent(int i)
{
    cout << "Criacao do aluno " << i << endl;
    student newStudent;
    cout << "Insira a Matricula do aluno: " << endl;
    cin >> newStudent.matricula;
    cout << "Insira o nome do aluno: " << endl;
    cin >> newStudent.nome;
    cout << "Insira a idade do aluno: " << endl;
    cin >> newStudent.idade;
    return newStudent;
}

// Funcao para imprimir os dados de um aluno
void printStudentData(student students[], int index)
{
    cout << "Matricula: " << students[index].matricula << endl;
    cout << "Nome: " << students[index].nome << endl;
    cout << "Idade: " << students[index].idade << endl;
}

// Funcao de busca binaria por Matricula de aluno
int binaryFindStudentByMatricula(student students[], int numberOfStudents, int matricula)
{
    int firstIndex = 0;
    int lastIndex = numberOfStudents - 1;
    int halfIndex;
    int executions = 0;

    halfIndex = (firstIndex + lastIndex) / 2;
    // Loop de busca binaria
    
    do {
        
        halfIndex = (firstIndex + lastIndex) / 2; // Atualiza o indice do meio

        // Verifica se a Matricula do aluno no indice do meio  igual aa Matricula procurado
        if (students[halfIndex].matricula == matricula)
        {
            cout << "Finalizada com " << executions << " execucoes" << endl;
            return halfIndex; // Retorna o indice onde o aluno foi encontrado
        }
        else
        {
            // Atualiza os  indices do primeiro e ultimo elementos da faixa de busca
            if (students[halfIndex].matricula < matricula)
            {
                firstIndex = halfIndex + 1;
            }
            else if (students[halfIndex].matricula > matricula)
            {
                lastIndex = halfIndex - 1;
            }
        }
        executions++; // Incrementa o contador de execucoes
    } while (firstIndex <= lastIndex);

    // Exibe o numero de execucoes e retorna -1 para indicar que o aluno no foi encontrado
    cout << "Finalizada com " << executions << " execucoes" << endl;
    return -1;
}

int main()
{
    int matriculaToFindBinary = 5; // Matricula do aluno a ser procurado usando busca binaria

    int numberOfStudents;
    cout << "Insira o numero de alunos: " << endl;
    cin >> numberOfStudents; // Insere o numero de alunos

    student students[numberOfStudents]; // Criacao de um array de alunos

    // Loop para criar e inserir informacoes de cada aluno
    for (int i = 0; i < numberOfStudents; i++)
        students[i] = createStudent(i);

    // Realiza a busca binaria pelo aluno com a Matricula especificado
    int queryResult = binaryFindStudentByMatricula(students, numberOfStudents, matriculaToFindBinary);

    // Verifica se o resultado da busca foi bem-sucedido ou no
    if (queryResult != -1)
    {
        printStudentData(students, queryResult); // Imprime os dados do aluno encontrado
    }
    else
    {
        cout << "Busca binaria pela Matricula " << matriculaToFindBinary << " falhou" << endl;
    }

    return 0;
}
