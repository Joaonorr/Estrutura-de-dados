//Faça um teste de performance dos algoritmos de ordenação vistos em sala de aula: Bouble-sort, Select-sort, Insert-sort, Merge-sort, Merge-sort V2 e Quick-sort./
//Para isso, gere 50000 vetores aleatoriamente de tamanhos {1.000, 5.000, 50000.000, 50.000, 50000.000, 200.000, 300.000, 500.000, 800.000, 1.000.000}./

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <functional>

// Recebe o intervalo e retorna um valor aleatório dentro do intervalo
int randValor(int valor1, int valor2){
    return (valor1 + (rand() % (valor2 - valor1 + 1)));
}

// Função que recebe o vetor e a função de ordenação e retorna o tempo de execução
double tempoExecucao(int vet[], int n, std::function<void(int vet[], int n)> func) {

    clock_t tempo_inicial = clock(); // Calcula o tempo inicial

    func(vet, n); // Chama a função de ordenação passada como parâmetro

    clock_t tempo_final = clock() - tempo_inicial; // Calcula o tempo final

    double tempo_em_milissegundos = (double) tempo_final / ((CLOCKS_PER_SEC/1000)); // Converte o tempo para milissegundos

    return tempo_em_milissegundos;
}

void restaurarVetor(int original[], int modificado[], int n){
    for (int i = 0; i < n; i++) {
        modificado[i] = original[i];
    }
}

// BubbleSort
// Escreva a função aqui

// SelectionSort
// Escreva a função aqui

// InsertionSort
// Escreva a função aqui

// MergeSort
// Escreva a função aqui

// MergeSort V2
// Escreva a função aqui

// QuickSort
// Escreva a função aqui



int main() {

    printf("Alocando vetores...\n");

    int tamanhos[] = {1000, 5000, 10000, 50000, 100000, 200000, 300000, 500000, 800000, 1000000};

    printf("Vetores alocaods!\n");
    printf("Iniciando testes...\n");

    printf("| Tamanho do vetor | Bubble Sort | Selection Sort | Insertion Sort | Merge Sort | Merge Sort V2 | Quick Sort |\n");
    printf("|------------------|-------------|----------------|----------------|------------|---------------|------------|\n");

    for (int tamanho : tamanhos) {

        int* vetor = (int*)malloc(tamanho*sizeof(int)); // aloca o vetor

        int* aux = (int*)malloc(tamanho*sizeof(int)); // aloca o vetor auxiliar

        for (int i = 0; i < tamanho; i++) {

            vetor[i] = randValor(0, tamanho); // gera valores aleatorios para o vetor
            aux[i] = vetor[i]; // copia os valores do vetor para o vetor auxiliar

        }

        printf("| %d |", tamanho);

        // Bubble Sort
        printf(" %.2f |", tempoExecucao(aux, tamanho, bubbleSort));
        restaurarVetor(vetor, aux, tamanho);

        // Selection Sort
        printf(" %.2f |", tempoExecucao(aux, tamanho, selectSort));
        restaurarVetor(vetor, aux, tamanho);

        // Insertion Sort
        printf(" %.2f |", tempoExecucao(aux, tamanho, InsertionSort));
        restaurarVetor(vetor, aux, tamanho);

        // Merge Sort
        printf(" %.2f |", tempoExecucao(aux, tamanho, MergeSort));
        restaurarVetor(vetor, aux, tamanho);

        // Merge Sort V2
        printf(" %.2f |", tempoExecucao(aux, tamanho, mergesortV2));
        restaurarVetor(vetor, aux, tamanho);

        // Quick Sort
        printf(" %.2f |", tempoExecucao(aux, tamanho, QuickSort));
        restaurarVetor(vetor, aux, tamanho);
        
        printf("\n");
    }
}