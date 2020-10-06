# gnuplot file
# generates the graph for cocktail sort and Bubblesort

set term png                        # will produce .png output
set output "graficoComparacao.png"  # output to any filename.png you want
set grid                            # grid background
set title 'Cocktail x Bubble'       # plot title
set xlabel 'Tamanho do Vetor'       # x-axis label
set ylabel 'Microssegundos'          # y-axis label
set multiplot                       # multiplot mode (prompt changes to 'multiplot')

# plot the graphic
plot 'resultadoCocktail.txt' with linespoints title 'Cocktail', 'resultadoBubble.txt' with linespoints title 'Bubble'

unset multiplot                     # exit multiplot mode (prompt changes back to 'gnuplot')
