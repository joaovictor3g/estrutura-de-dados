#ifndef LIST_H
#define LIST_H

class List {
    private:
        int *vec = nullptr; 
        int size = 0;
        int capacity_vec = 0;

    public:
        List(int n);
        ~List();
        // 1-Pegar o valor Minimo da lista Sequencial
        int getMinValue();
        // 3. Escreva uma fun¸c˜ao que inclui um elemento em uma lista sequencial
        bool add(int x);
        // 2-Escreva uma fun¸c˜ao que remova de uma lista sequencial 
        // o elemento que tem o valor m´aximo
        void removeMaxValue();
        // Retorna o indice do maior elemento
        int getMaxValueIndex();
        // 4. Escreva uma fun¸c˜ao que remove um elemento de uma lista sequencial.
        void remove(int element);
        // Imprime os elementos da lista
        void print();
        // Retorna o indice do elemento passaado como parametro
        // 5. Escreva uma fun¸c˜ao que busca a primeira ocorrˆencia 
        // de um elemento x em uma lista sequencial e retorna a posi¸c˜ao 
        // do elemento na lista caso ele ocorra, ou retorne -1 caso contr´ario.
        int search(int element);
        //  6. Escreva algoritmos de inser¸c˜ao e remo¸c˜ao 
        // em uma lista sequencial cujos elementos est˜ao
        // ordenados em ordem crescente e devem permanecer 
        // ordenados ap´os estas opera¸c˜oes. Qual
        // a complexidade dos seus algoritmos? Justifique
        // O(n), pois no pior caso toda a lista será percorrida 
        bool isFull();

        bool isEmpty();
        // 7. Fa¸ca uma fun¸c˜ao para remover de uma lista sequencial 
        // todos os elementos com valor x, dado como entrada.
        void removeAt(int element);
        //  8. Escreva uma fun¸c˜ao que retorna a quantidade de 
        // vezes que o elemento x aparece na lista sequencial.
        int countElement(int element);
};

#endif