reset
set style line 1 lw 2 pt 1 lc 1

set grid
set title 'Selection Sort Recursivo'
set xlabel 'Tamanho do vetor'
set ylabel 'Microssegundos'

plot 'resultadoSelectionSortRec.txt' with linespoints title 'SelectionSort'