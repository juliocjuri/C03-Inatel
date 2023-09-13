/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int vetor[] = {7,8,6,4,5,3,1,2,9};
    int n = 9, temp, pos_min, min;
    
    for(int j = 0; j < n; j++){
        
    // Selection sort
    // Menor elemento do vetor a partir de j
    min = vetor[j];
    pos_min = j;
    for(int i = 1+j; i < n; i++){
        if(vetor[i] <  min){
            min = vetor[i];
            pos_min = i;
        }
    }
    // Trocar ele pelo elemento na j-ésima posição
    temp = vetor[j];
    vetor[j] = min;
    vetor[pos_min] = temp;
    }
    
    for(int k = 0; k < n; k++){
        cout << vetor[k] << endl;
    }
    return 0;
}
