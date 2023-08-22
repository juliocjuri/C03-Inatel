#include <iostream>
#include <string>

using namespace std;

struct aluno {
	int matricula;
	string nome; 
	int idade;
};

aluno cria_aluno(){
	aluno a;
	cout << "Insira a matricula, nome e idade" << endl;
	cin >> a.matricula;
	cin >> a.nome;
	cin >> a.idade;
	return a;
}

//Essa funcao nao enxerga os alunos da main, entao precisamos passar como param.
int busca_aluno_seq_mat(aluno alunos[], int n, int mat){
	for(int i = 0; i < n; i++){
		if(mat == alunos[i].matricula){
			cout << "Achou!" << endl;
			return i;
		}
	}
	return -1;
}

int busca_aluno_seq_nome(aluno alunos[], int n, string nome){
	for(int i = 0; i < n; i++){
		if(nome == alunos[i].nome){
			cout << "Achou!" << endl;
			return i;
		}
	}
	return -1;
}

int busca_aluno_seq_idade(aluno alunos[], int n, int idade_buscada){
	int contador = 0;
	for(int i = 0; i < n; i++){
		cout << alunos[i].idade << endl;
		if(idade_buscada >= alunos[i].idade){
			contador++;
		}
	}
	return -1;
}

int main(){
	int n;
	cin >> n;
	
	aluno alunos[n];
	
	for(int i = 0; i < n; i++){
		alunos[i] = cria_aluno();
	}
	
	int mat = 6;
	
	int resultado = busca_aluno_seq_mat(alunos, n, mat);
	
	if(resultado != -1){
		cout << alunos[resultado].nome << endl;
		cout << alunos[resultado].matricula << endl;
		cout << alunos[resultado].idade << endl;
	} else {
		cout << "Nada encontrado" << endl;
	}
	
	string nome = "Jonas";
	
	resultado = busca_aluno_seq_nome(alunos, n, nome);
	
		if(resultado != -1){
		cout << alunos[resultado].nome << endl;
		cout << alunos[resultado].matricula << endl;
		cout << alunos[resultado].idade << endl;
	} else {
		cout << "Nada encontrado" << endl;
	}
	
	int idade_buscada = 12;
	
	resultado = busca_aluno_seq_idade(alunos, n, idade_buscada);
	
	cout << "Existe(m) " << resultado << " aluno(a)(s) com idade menor ou igual a idade buscada" << endl;
	return 0;
}

//TODO: corrigir o erro da idade
