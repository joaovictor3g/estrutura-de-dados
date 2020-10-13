#include <iostream>
#include "vetorOrdenado.h"

void iteractive_bubble_sort(int v[], int size) {
    bool ordenado = false; // flag que para a execução do while
    
    while(!ordenado) {
        ordenado = true; // Já recebe verdade
        for(int i = 0; i < size - 1; i++){
            if(v[i] > v[i+1]){ // Verifica uma posição com a sua subsequente
                ordenado = false; // Ainda há possíveis permutações
                std::swap(v[i], v[i+1]); // troca os valores contidos nas posições
                
            }
        }
    }
}

void recursive_bubble_sort(int* v, int size, int index) {
    if(size == 0 || size == 1) 
        return;

    if(v[size-1] < v[size-2]) // Comparando do ultimo com o seu anterior
        std::swap(v[size-1], v[size-2]); // Façõ a troca de valores

    if(!ascending_order(v, index) && size == 2) // Chamada da função q verifica se está ordenado em ordem crescente 
        recursive_bubble_sort(v, index, index); // chamo a recursão passando o tamanho original do vetor para size
            
    recursive_bubble_sort(v, size-1, index); // chamo a recursão
}

void iteractive_insertion_sort(int vet[], int size) {
    int i = 0, j = 0, key = 0, index = 0;
    
    for(i = 1; i < size; i++) {
        key = vet[i]; // Chave que guarda o valor que está sendo comparado
        index = i; // Guardando indice da chave inicial
        for(j = i - 1; j >= 0; j--) {  // For que começa de i e decrementa-o
            if(key < vet[j]) { // Comparo a chave com os valores a esquerda de key
                vet[j+1] = vet[j]; // Movo o valor de key para direita  
                index = j; // guardando os indices a esquerda se houver
            }
        }
        vet[index] = key; // ajusto a posição de key
    }
}

// a imlementar
// 3, 5, 1, 9, 0
void recursive_insertion_sort(int vet[], int size, int index, int key, int current) {
    while(index >= 0 && key < vet[index]) {
        vet[index+1] = vet[index]; // Valores maiores q a chave vão sendo deslocados a direita
        index--; // index decrementado
    }
    vet[index+1] = key; // valor atualizado com a chave
    if(current < size-1) {  
        // valor q key vai receber q é o próximo q estava a direita dele
        recursive_insertion_sort(vet, size, current, vet[current+1], current+1);
    }else return; // Caso base
}

void iteractive_selection_sort(int vet[], int size) {
    int menor = 0; // varivel q vai guardar o menor valor do vetor
    int index = 0; // variavel q vai guardar o indice do menro valor do vetor
    // 1, 5, 3, 4, 2
    for(int i = 0; i < size-1; i++) {
        index = i; // indice recebe o i da iteração atual
        menor = vet[i];
        for(int j = i; j < size; j++) {
            if(menor > vet[j]) {  
                menor = vet[j]; // Atribuo o valor do menor, se houver menor q a varivel menor
                index = j; // indice do menor é atualizado
            }
        }
        int tmp = vet[i]; // guardo o valor do vetor atual
        vet[i] = vet[index]; // troco
        vet[index] = tmp; // ajusto os valores
    } 
}

void recursive_selection_sort(int vet[], int size, int index, int min, int current_position) {
    int i = current_position; // Indice i recebe a posição atual
    for(; i < size; i++) { // loop da posição inicial até size-1
        if(min > vet[i]) { // Verifico qual o menor valor contido no vetor
            min = vet[i]; // atualizo min
            index = i; // atualizo o index
        }
    }
    int tmp = vet[current_position]; // variavel temporária que recebe o valor a ser trocado
    vet[current_position] = vet[index]; // recebe o menor valor, se o menor for ele mesmo, vai receber ele mesmo
    vet[index] = tmp; // vetor na posição doi index recebe o valor trocado

    if(current_position < size-1) { // Caso de parada
        // size permanece o mesmo
        // index recebe a posição atual mais 1
        // min recebe o proximo a sua direita
        // current_position recebe ele mesmo mais 1.
        recursive_selection_sort(vet, size, current_position+1, vet[current_position+1], current_position+1);
    
    }else return; // caso base
}


void merge(int vet[], int begin, int middle, int end) {
    int size = end-begin+1;
    int *vetAux = new int[size];
    int beginAux = begin, midAux = middle+1; 
    int current_position = 0;

    while(beginAux <= middle && midAux <= end) {
        if(vet[beginAux] < vet[midAux]) {
            vetAux[current_position++] = vet[beginAux++];
        }else{
            vetAux[current_position++] = vet[midAux++];
        }
    }
    while(beginAux <= middle) 
        vetAux[current_position++] = vet[beginAux++];
    
    while(midAux <= end)
        vetAux[current_position++] = vet[midAux++];
    
    for(int i = begin; i <= end; i++) 
        vet[i] = vetAux[i-begin];


    delete[] vetAux;
}

void recursive_merge_sort(int vet[], int begin, int end) {
    if (begin < end) {
        int middle = (end+begin)/2;

        recursive_merge_sort(vet, begin, middle);
        recursive_merge_sort(vet, middle+1, end);
        merge(vet, begin, middle, end);
    }
}

void iteractive_merge_sort(int vet[], int begin, int end) {
    int middle = (begin+end)/2; // meio do vetor
    // neste laço o vetor vai sendo passando
    // começando com uma única posição
    // logo após duas posições, três posições
    // até o vetor inteiro ser passado
    for(int i = begin; i < middle; i++) // Loop do inicio do vetor até o meio: primeira parte
        merge(vet, begin, i, i+1); // interacalando e ordenando a primeira parte
    for(int i = middle; i < end; i++)  // Loop do meio do vetor até o fim: segunda parte
        merge(vet, middle+1, i, i+1); // 
    merge(vet, begin, middle, end);
}


int partition(int vet[], int begin, int end) {
    int pivot = vet[begin]; // pivô
    int left = begin, right = end-1; 
    while(left < right) {
        while(vet[left] <= pivot) // verificando se os valores são menores que o pivô para qque estes sejam colocados a esquerda 
            left++; // incremento até achar um elemento maior que o pivô, ou o fim do vetor
        while(vet[right] > pivot) // valores maiores a direita
            right--; // Decremento até achar um valor menor que o pivõ, ou o começo do vetor
        if(left < right) // Se o left iterou e foi menor que o right uma troca é feita
            std::swap(vet[left], vet[right]); // troca
        
    }
    vet[begin] = vet[right]; // vetor na posição incial recebe o vetor na posição a direita
    vet[right] = pivot;  // vetor a direita recebe pivot
    return right; // retorno novo pivot, com todos os valores a esquerda menores e a direita maiores
}

void recursive_quick_sort(int vet[], int begin, int end) {
    int pivot;
    if(begin < end) {
        pivot = partition(vet, begin, end); // escolhendo o pivo
        recursive_quick_sort(vet, begin, pivot); // ordenando os valores até o pivot
        recursive_quick_sort(vet, pivot+1, end); // ordenando os valores a direita do pivot
    
    }
}

void iteractive_quick_sort(int vet[], int begin, int end) {
    int pivot = partition(vet, begin, end);

    for(int i = 0; i < pivot-1; i++) {
        int pivotAux = partition(vet, begin, i+1);
        
    }
}

// Verifica se o vetor está totalmente ordenado em ordem crescente
bool ascending_order(int vet[], int size) {
    int counter = 0;
    for(int i = 0; i < size - 1; i++) {
        if(vet[i] <= vet[i+1])
            counter++;
    }

    return (counter+1 == size);
}


void print(int vet[], int size) {
    std::cout << "Vetor ordenado : ";
    std::cout << "[";
    for(int i = 0; i < size; i++) {
        std::cout << vet[i];
        if(i != size-1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
