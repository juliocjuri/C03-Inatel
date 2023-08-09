#include <iostream>
#include <string>

using namespace std;

struct aluno {
	int matricula;
	string nome; 
};

aluno cria_aluno(){
	aluno a;
	cin >> a.matricula;
	cin >> a.nome;
	return a;
}

int main(){
	int n;
	cin >> n;
	
	aluno alunos[n];
	
	for(int i = 0; i < n; i++){
		alunos[i] = cria_aluno();
	}
	
	return 0;
}


