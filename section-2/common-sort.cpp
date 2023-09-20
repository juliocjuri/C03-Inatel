
// Algoritmo de ordenação genérico (Percorrer todo o vetor e ir selecionando o menor valor)

#include <iostream>

using namespace std;


int main(){
	/*
	
    Atribuição: 3
    Total: 3

	*/
	int n = 9;
	int auxiliar = 0;
	int vetor[] = {3, 7, 9, 15, 1, 2, 8, 10, 11};
	
    /*
    
    Atribuição: 1
    Busca de vetor na posição 0: 1
    Total: 2

    */
	int menor_valor = vetor[0];
	
	/*
    
    Atribuição: 1

    Busca do valor j: 1
    Busca do valor n: 1
    Comparação: 1
    Busca do valor j, soma e atribuição: 3

    Total: 1 + 6N

    */
	for(int j = 0; j < n; j++){
		
        /*
        
        Atribuição: 1
        Busca do valor j: 1
        Busca do vetor na posição j: 1
        Total: 3

        */
		menor_valor = vetor[j];
		
        /*
        
        Atribuição: 1
        Busca do valor j: 1

        Busca do valor i: 1
        Busca do valor n: 1
        Comparação: 1
        Busca do valor i, soma e atribuição: 3

        Para j = 0, esse for irá executar n - 0 vezes, que é igual a n 
        Para j = 1, esse for irá executar n - 1 vezes, que é n - 1
        ...
        Seguindo a lógica, teremos, no final, j = n-1, de forma que a última execução do for se dará por n - (n-1) vezes, que é 1 vez
        Tirando a média de tais valores, teremos (n + 1)/2 

        Ou seja, de total, teremos 2 + [(n+1)/2]*6 = 3N + 5

        */
		for(int i = j; i < n; i++){
			
            /*
            
            Busca do valor i: 1
            Busca do vetor na posição i: 1
            Busca do menor_valor: 1
            Comparação

            Total: 3*(n+1)/2
            */
			if(vetor[i] < menor_valor){
				
                /*
                
                Busca do valor j: 1
                Busca do valor i: 1
                Busca do vetor nas posições i e j: 2
                Atribuições: 2

                Total: 6*(n+1)/2 = 3(N+1)
                */
				auxiliar = vetor[j];
				menor_valor = vetor[i];
				
                /*
                
                Busca dos valores j, i, menor_valor e auxiliar: 4
                Atribuições: 2

                Total: 3*(N+1)

                */
				vetor[j] = menor_valor;
				vetor[i] = auxiliar;
				
			}
		}
	}
    //Total: 3 + 2 + 1 + 6N + 3N + 2 + [(3N + 5)*N] + [3/2*(N+1)*N] + [3(N+1)*N] + [3(N+1)*N]
	//Total: (47/2)N + (15/2)N^2
    //Complexidade no modelo assintotico: O(N^2)
    
	return 0;
}