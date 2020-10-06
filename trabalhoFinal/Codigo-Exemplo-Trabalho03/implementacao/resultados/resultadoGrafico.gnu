reset
set style line 1 lw 2 pt 1 lc 1

set grid
set title 'Bubble Sort Iterativo'
set key above
set xlabel 'Tamanho do vetor'
set ylabel 'Microssegundos'

plot 'resultadoInsertionSort.txt' notitle with lines ls 10 smooth csplines, 'resultadoInsertionSort.txt' notitle with points ls 1