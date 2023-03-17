# réinitialisation des paramètres
reset

# fichier de sortie
set term postscript eps size 3.5,2.62 enhanced color font 'Helvetica,12'
set output "graphes/sol.eps"
set encoding utf8

# paramètres
set title "solution éq transport 2D"
set grid
set xlabel "x"
set ylabel "y"
set size ratio -1 # repère orthonormé
set xrange[0:2]
set yrange[0:1]

# tracé
splot "sorties/u.dat"    u 1:2:3 lc rgb "#FF4500" lw 1 title "approximation",\

# affichage écran
set term wxt enhanced
replot
