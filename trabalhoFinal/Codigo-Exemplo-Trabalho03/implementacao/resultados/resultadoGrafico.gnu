reset
set style line 1 lw 2 pt 1 lc 1

set grid
set title 'Insertion Sort Iterativo'
set xlabel 'Tamanho do vetor'
set ylabel 'Microssegundos'

plot 'resultadoInsertionSort.txt' with linespoints title 'InsertionSort'