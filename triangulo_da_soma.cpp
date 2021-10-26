#include <iostream>
#include <string> 
#include <sstream>
#include <vector>


void soma(int **matriz,int linha,int coluna, int tamanho){
    if(matriz[linha+1][coluna] > 0 && matriz[linha+1][coluna+1] > 0){
        matriz[linha][coluna] = matriz[linha+1][coluna] + matriz[linha+1][coluna+1];
        
    }
    else {
        soma(matriz, linha+1, coluna, tamanho) , soma( matriz, linha+1, coluna+1, tamanho);
    }

    if( tamanho!= 0){
        soma(matriz,linha,coluna,tamanho-1);
    }
}


int main(){

    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::vector<int> vet;
    int value;
    while(ss >> value)
    vet.push_back(value);

    int tam{ (int) vet.size()};

    int **matriz = new int*[tam];

    for(int i{0}; i < tam; i++){
        matriz[i] = new int[tam];
    }

    int cont{0};

    for(int i{0}; i < tam; i++){
        for(int j{0}; j < tam; j++){
            matriz[i][j] = 0;
        }
    }

    for(int i{0}; i < tam; i++){
        matriz[tam-1][i] = vet[i];
    }
        

    soma(matriz, 0, 0, tam);

    for(int i{0}; i < tam; i++){
        std::cout << "[ ";
        for(int j{0}; j < tam; j++){
            if( matriz[i][j] != 0){
                std::cout << matriz[i][j] << " ";
            }
        }
        std::cout << "]";
        std::cout << '\n';
    }

}
