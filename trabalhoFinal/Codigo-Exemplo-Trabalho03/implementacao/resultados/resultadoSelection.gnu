reset
set style line 1 lw 2 pt 1 lc 1

set grid
set title 'Selection Sort'
set xlabel 'Tamanho do vetor'
set ylabel 'Microssegundos'

plot 'resultadoSelectionSort.txt' with linespoints title 'SelectionSort'