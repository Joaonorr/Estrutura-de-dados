#include <iostream>
#include <sstream> 
#include <string>
#include <vector>

void imprimeVetor(std::vector<int> vet) {
    int tamanho { (int) vet.size() };

    if( tamanho > 0 ) {
        std::cout << " " << vet[0];
        vet.erase(vet.begin());
        imprimeVetor(vet);
    }
}

void imprimeVetorInvertido(std::vector<int> vet) {
    int tamanho { (int) vet.size() };

    if( tamanho > 0 ) {
        std::cout << " " << vet[tamanho-1];
        vet.erase(vet.begin()+tamanho-1);
        imprimeVetorInvertido(vet);
    }
}

void somaVetor(std::vector<int> vet) {
    int tamanho { (int) vet.size()-1 };
    if(tamanho > 0) {
        vet[tamanho] += vet[0];
        vet.erase(vet.begin());
        somaVetor(vet);
    }
    if(tamanho == 0){
    std::cout<< vet[0] << "\n";  
    }     
}

void multiplicarVetor(std::vector<int> vet) {
    int tamanho { (int) vet.size()-1 };
    if(tamanho > 0) {
        vet[tamanho] *= vet[0];
        vet.erase(vet.begin());
        multiplicarVetor(vet);
    }
    if(tamanho == 0){
    std::cout << vet[0] << "\n";  
    }     
}

void menorVetor(std::vector<int> vet) {

    int tamanho { (int) vet.size()-1 };
    
    if( vet.size() == 1){
    std::cout << vet[0] << "\n";
    }
    else if(vet [0] <= vet[1]) {
        vet.erase(vet.begin()+1);
        menorVetor(vet);
    }
    else {
        vet.erase(vet.begin());
        menorVetor(vet);
    }
}

void inverterVetorOriginal(std::vector<int>& vet, auto cont) {
    if(cont > 0) {
        vet.push_back(vet[cont-1]);
        vet.erase(vet.begin()+cont-1);
        inverterVetorOriginal(vet, cont-1);
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

    std::cout << "vet : ";
    std::cout << "["; 
    imprimeVetor(vet); 
    std::cout << " ]" << '\n';

    std::cout << "rvet: ";
    std::cout << "["; 
    imprimeVetorInvertido(vet); 
    std::cout << " ]" << '\n';

    std::cout << "sum : ";
    somaVetor(vet);

    std::cout << "mult: ";
    multiplicarVetor(vet);

    std::cout << "min : ";
    menorVetor(vet);

    inverterVetorOriginal(vet,vet.size());

    std::cout << "inv : ";
    std::cout << "[";
    imprimeVetor(vet);
    std::cout << " ]" << '\n';
}