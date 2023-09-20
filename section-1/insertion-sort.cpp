#include <iostream>

using namespace std;

int main()
{
    /*

    Atribuicoes: 3
    Total: 3

    */

    int vetor[] = {2, 5, 6, 8, 4, 1};
    int tamanho = 6, tamanhoSegundoVetor;
    int elementoAtual;

    /*

    Atribuicao: 1
    Acesso ao valor de i e de tamanho: 2
    Acesso ao valor de i, soma e atribuicao: 3

    Total: 1 + 5N
    */
    for (int i = 1; i < tamanho; i++)
    {
        /*

        Atribuicao: 1
        Busca de i: 1
        Busca da posicao i do vetor: 1

        Total: 3N

        */
        elementoAtual = vetor[i];

        /*

        Busca do valor de i: 1
        Subtracao: 1
        Atribuicao: 1

        Total: 3N

        */
        tamanhoSegundoVetor = i - 1;

        /*

            No pior caso, vetor[tamanhoSegundotamanhoSegundoVetorVetor] sera sempre maior que o elemento atual
            (Os itens estarao em ordem decrescente). Dessa forma, como tamanhoSegundoVetor vai decrementando,
            ele irá passar por esse loop no mínimo duas vezes para tamanho = 1.
            Depois, passará três vezes para tamanho = 2,
            Até chegar em tamanho - 1, irá executar o while (a comparação) (tamanho - 1) + 1 vezes
            Assim, fazendo uma média, teremos (2 + tamanho -1 + 1)/2 = (tamanho + 2)/2

        */

        /*

        Busca do valor de tamanhoSegundoVetor: 1
        Comparacao: 1
        Comparacao (&&): 1
        Busca no valor de tamanhoSegundoVetor: 1
        Busca do vetor na posicao tamanhoSegundoVetor: 1
        Busca do elementoAtual: 1
        Busca da comparacao: 1

        Total: 7 * (N + 2)/2

        */

        while ((tamanhoSegundoVetor >= 0) && (vetor[tamanhoSegundoVetor] > elementoAtual))
        {

            /*

            Acesso de tamanhoSegundoVetor: 1
            Comparação: 1
            Comparação (&&): 1
            Acesso de tamanhoSegundoVetor: 1
            Acesso de vetor na posição tamanhoSegundoVetor: 1
            Comparação: 1
            Acesso de elementoAtual: 1


            Total:   7* ((N + 2)/2 - 1)

            Coloca-se o -1 no final para indicar que sera 1x menos do que as comparações do while (quando tamanhoSegundoVetor < 0)
            */
            vetor[tamanhoSegundoVetor + 1] = vetor[tamanhoSegundoVetor];
            /*

                    Busca do valor de tamanhoSegundoVetor: 1
                    Subtracao: 1
                    Atribuicao: 1

                    Total: 3* ((N + 2)/2 - 1)

                    */

            tamanhoSegundoVetor--;
        }
        /*
        
        Busca de tamanhoSegundoVetor: 1
        Soma: 1
        Busca de elementoAtual: 1
        Atribuição: 1

        Total: 4N
        */
        vetor[tamanhoSegundoVetor + 1] = elementoAtual;
    }

    //Total: 3 + 1 + 5N + 3N + 3N + (7 * ((N + 2)/2) * N) + ( 7* ((N + 2)/2 - 1) * N) + (3* ((N + 2)/2 - 1) * N) + 4N
    //Total: (17/2)N^2 + 18.5N + 4
    //Complexidade O(n^2)

    //Total do quicksort: (47/2)N + (15/2)N^2
    //Total bubble sort: 8N^2 + 13N + 10.
    
    //Conclusão: Mais complexo que bubble sort, e menos complexo do que o quicksort 
}