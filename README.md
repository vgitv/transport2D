# Méthode des volumes finis 2D

## Présentation du sujet
Résolution numérique d'une équation hyperbolique en deux dimensions : **l'équation de transport**.

$$ \partial_t u + \mathrm{div}_x f(u) = 0 $$

Condition initiale :
$$ u(x, t = 0) = u_0(x) $$

## Structure
Fichiers sources :

+ main.cpp
+ math.cpp/.h
+ Mesh.cpp/.h
+ Transport2D.cpp/.h
+ vf.cpp/.h
+ donnees.cpp/.h

Dossiers :

+ entrees/
+ sorties/

Un makefile.

## Utilisation
Modifier éventuellement le fichier **donnees.cpp** pour choisir le flux **f** et la condition initiale **u0**. Lancer **make** pour compilation. Les solutions sont enregistrées dans un fichier du dossier **sorties/**.

## Implémentation

### Classe Mesh
Maillage cartésien.

### Classe Transport2D
Contient un maillage cartésien, des solveurs par méthode des volumes finis. Stocke la solution approchée.