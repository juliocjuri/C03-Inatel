#include <iostream>

using namespace std;

int main()
{

    /*

    Atribuições: 2

    */
    int vetor[] = {3, 5, 2, 4, 1, 6, 9, 7, 8};
    int n = 9;

    /*

    Atribuição: 1
    Acesso do vetor na posição 0: 1

    Total: 2
    */
    int auxiliar = vetor[0];

    /*

    Atribuição: 1
    Acesso da variavel n: 1

    Acesso da variavel j: 1
    Comparação: 1
    Acesso da variavel j: 1
    Atribuição 1:
    Subtração: 1

    Total: 2 + 5N

    */
    for (int j = n; j > 0; j--)
    {

        /*
        
        j começa com o valor de n, e vai até 1. Dessa forma, teremos que no for loop abaixo:

        Com j = n, i irá executar até n (n vezes)
        Com j = n - 1, i irá executar até n - 1
        ...
        Com j = 1, i irá executar até 1 (1 vez)

        Ou seja, tirando a média, a quantidade de execuções será (n+1)/2

        Atribuição: 1

        Busca do valor de i e de j: 2
        Comparação: 1
        Busca do valor de i, soma e atribuição: 3

        Total: 1 + 6 * (n+1)/2 = 1+3*(n+1)
        */
        for (int i = 0; i < j; i++)
        {

            /*
            
            Busca do valor i: 1
            Busca da posição i de vetor: 1
            Comparação: 1
            Busca de i: 1
            Soma: 1
            Busca da posição i+1 no vetor: 1

            Total: 3*(n+1)
            */
            if (vetor[i] > vetor[i + 1])
            {
                /*
                
                Atribuição: 1
                Busca do valor i: 1
                Buscao do vetor na posição i: 1

                Busca do vetor na posição i + 1: 1
                Soma: 1
                Busca do valor i: 1

                Busca do valor i: 1
                Soma: 1
                Atribuição: 1
                Busca do valor auxiliar: 1

                Total: 10*(n+1)/2
                */
                auxiliar = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = auxiliar;
            }
        }
    }
    //Total: 2 + 2 + 2 + 5N + (1+3*(N+1))*N + (3*(N+1))*N + (10*(N+1)/2)*N
    //Total: 8N^2 + 13N + 10.
    //Complexidade: O(N^2)
    return 0;
}
