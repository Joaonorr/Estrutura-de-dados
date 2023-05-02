# Calculando o tempo que cada ordenação leva para ordenar um vetor de _n_ elementos

- [Introdução](#introdução)
- [Bibliotecas necessárias](#bibliotecas-necessárias)
- [Funções utilizadas](#funções-utilizadas)
- [Explicação](#explicação)
- [Código base](#código-base)
- [Como executar](#como-executar)
- [Possíveis dificuldades](#possíveis-dificuldades)
- [Mão na massa](#chegou-a-hora-de-colocar-a-mão-na-massa)


## Introdução

O objetivo desse guia é mostrar como calcular o tempo que cada algoritmo de ordenação leva para ordenar um vetor de _n_ elementos. Para isso, vamos usar 10 vetores de tamanhos diferentes e colocar o tempo de cada ordenação em uma tabela.

## Bibliotecas necessárias

- `<stdio.h>`
- `<stdlib.h>` 
- `<time.h>`
- `<functional>`

## Funções utilizadas

```c
int randValor(int valor1, int valor2)
```
- Essa função gera um número aleatório entre `valor1` e `valor2`.

---

```c
double tempoExecucao(int vet[], int n, std::function<void(int vet[], int n)> func)
```
- Recebe um vetor de inteiros, o tamanho do vetor e uma função que recebe um vetor de inteiros e o tamanho do vetor. Essa função retorna o tempo que a função `func` leva para ordenar o vetor `vet` de tamanho `n`.

---

```c
void restaurarVetor(int original[], int modificado[], int n)
```
- Recebe um vetor original, um vetor modificado e o tamanho do vetor. Essa função copia os valores do vetor original para o vetor modificado.


## Explicação

O fluxo do programa pode ser resumido nos seguintes passos:

1. Criar um vetor de tamanho `n` e preencher com valores aleatórios.
2. Ordenar o vetor usando a função `tempoExecucao`.
3. Imprimir o tempo que a função `tempoExecucao` levou para ordenar o vetor.
4. Restaurar o vetor para o estado original.
5. Repetir os passos 2, 3 e 4 para cada algoritmo de ordenação.

Exemplo da utilização da função `tempoExecucao`:

```c
void selectSort(int vet[], int n){

    int aux, min;

    for (int i = 0; i < n-1; i++) {

        min = i;

        for (int j = i+1; j < n; j++) {
            if (vet[j] < vet[min]) {
                min = j;
            }
        }

        aux = vet[i];

        vet[i] = vet[min];

        vet[min] = aux;
    }
}

int main() {

    int vetor[] = {5, 4, 3, 2, 1};

    int n = 5;

    double tempo = tempoExecucao(vetor, n, selectSort);

    printf("Tempo: %.2f ms\n", tempo);

    return 0;
}
```

Para uma melhor visualização da tabela gerada, vamos formatar a saída para gerar uma tabela em Markdown do seguinte formato:

| Tamanho do vetor | Bubble Sort | Selection Sort | Insertion Sort | Merge Sort | Merge Sort V2 | Quick Sort |
|------------------|-------------|----------------|----------------|------------|---------------|------------|
| 1000 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |
| 5000 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |
| 10000 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |
| 50000 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |
| 100000 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |
| 200000 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |
| 300000 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |
| 500000 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |
| 800000 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |
| 1000000 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 | 0.00 |


## Código base

```c
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

int main() {

    int tamanhos[] = {1000, 5000, 10000, 50000, 100000, 200000, 300000, 500000, 800000, 1000000};

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
        printf(" %.2f |", tempoExecucao(aux, tamanho, selectSort));
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
```

## Como executar

Para executar o código, basta compilar o arquivo `solver.cpp` e executar o arquivo gerado:

```bash
g++ solver.cpp -o solver && 
./solver
```

## Possíveis dificuldades
1. A função `tempoExecucao` apresenta um erro quando a função de ordenação recebe mais parâmetros além do vetor, tamanho e função de ordenação. 

    - Para resolver esse problema, basta criar uma função que recebe apenas o vetor e o tamanho e chama a função de ordenação passada como parâmetro.

2. Erro de referência indefinida

    - Para resolver esse problema, basta compilar o arquivo com a flag `-std=c++11`:

        ```bash
        g++ solver.cpp -o solver -std=c++11 && 
        ./solver
        ```
        a flag `-std=c++11` é necessária para que o compilador reconheça a função `std::function` que é utilizadas no código.

3. O programa trava quando chega em tamanho de vetor muito grande

    - Calma, o programa não travou, ele apenas está demorando para executar. O tempo de execução aumenta muito quando o tamanho do vetor aumenta, por isso, é recomendado que você execute o programa com vetores de tamanho pequeno para testar se o programa está funcionando corretamente.

## Chegou a hora de colocar a mão na massa

Agora que você já sabe como executar o código, chegou a hora de colocar a mão na massa, bastar abrir o arquivo `solver.cpp` e implementar as funções de ordenação. no espaço reservado para isso.

