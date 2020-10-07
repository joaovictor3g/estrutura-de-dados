reset
set style line 1 lw 2 pt 1 lc 1

set grid
set title 'Selection Sort'
set key above
set xlabel 'Tamanho do vetor'
set ylabel 'Microssegundos'

plot 'resultadoSelectionSort.txt' notitle with lines ls 10 smooth csplines, 'resultadoSelectionSort.txt' notitle with points ls 1