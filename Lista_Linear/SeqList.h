#ifndef SeqList_H
#define SeqList_H

class SeqList {
    private:
        int *vec = nullptr;
        int size_vec = 0;
        int capacity_vec = 0;
    public: 
        // Construtor: Recebe capacidade
        SeqList(int n); 
        // Destrutor: libera memória alocada
        ~SeqList();
        // Adiciona x ao final da lista
        bool add(int x);
        // Remove o primeiro x da lista
        void remove(int x);
        // Busca x e retorna o índice
        int search(int x);
        // Retorna o k-ésimo elemento da lista
        int at(int k);
        // Retorna o tamanho de SeqList
        int size();
        // Retorna se lista cheia
        bool isFull();
        // Deixa lista vazia
        void clear();
        // Imprime o vetor
        void print();
        // Troca o elemento na posicao k pelo elemento x (somente se 0 ≤ k ≤ size vec − 1)
        bool replaceAt(int x, int k);
        //  Remove o elemento com índice k na lista.
        // Deve-se ter 0 ≤ k ≤ size vex-1; caso contrario, a remoção não é realizada.
        void removeAt(int k);
        // Adiciona o elemento x na posicao k
        // (somente se 0 ≤ k ≤ size vec e size vec < max vec). Antes de fazer a
        // inserc¸˜ao, todos os elementos da posic¸˜ao k em diante s˜ao deslocados uma
        // posic¸˜ao para a direita.
        bool insertAt(int x, int k);
        // Remove todas as ocorrˆencias do elemento x
        // na lista.
        void removeAll(int x);
};  

#endif 