__Bubble Sort:__ Verifica-se os valores em posições subsequentes, ou seja: 
```C++
if(vetor[0] > vetor[1])
    swap(vetor[0], vetor[1]);
```
claro que isto é considerando que a ordenação é em ordem crescente.

__Insertion Sort:__ Assim como no bubble verifica-se posições subsequentes, mas neste algoritmo
os valores maiores vão sendo colocados a direita do valor que foi comparado. Ou seja, todos os valores 
à esquerda do valor comparado que no caso pode ser chamado de chave vão estar devidamente ordenados,
quando este for colocado.

__Selection Sort:__ Neste algoritmo procura-se o menor valor contido no vetor, e vai colocando na primeira 
posição, segunda... e assim sucessivamente até que o vetor esteja devidamente ordenado.
