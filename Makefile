# -----------------------------------------------------------------------------------------------------------
#  variables
# -----------------------------------------------------------------------------------------------------------
# nom du projet
PROJECT = transport2D

# code
SOURCES = main.cpp math.cpp Mesh.cpp vf.cpp donnees.cpp
HEADERS =          math.h   Mesh.h   vf.h   donnees.h
OBJECTS = main.o   math.o   Mesh.o   vf.o   donnees.o

# compilateur et exécutable
CC      = g++ -std=c++11
EXEC    = truc

# autre fichier brut à ouvrir
OTHER   = entrees/constantes

# pdf énoncé de TP
PDF     =



# -----------------------------------------------------------------------------------------------------------
#  compilation rules
# -----------------------------------------------------------------------------------------------------------
# exécutable
$(EXEC) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# programme principal
main.o : main.cpp $(HEADERS)
	$(CC) -c main.cpp -o main.o

# modules
math.o : math.cpp math.h
	$(CC) -c math.cpp -o math.o

Mesh.o : Mesh.cpp Mesh.h
	$(CC) -c Mesh.cpp -o Mesh.o

vf.o : vf.cpp vf.h
	$(CC) -c vf.cpp -o vf.o

donnees.o : donnees.cpp donnees.h
	$(CC) -c donnees.cpp -o donnees.o



# -----------------------------------------------------------------------------------------------------------
# phony targets
# -----------------------------------------------------------------------------------------------------------
# exécuter l'exécutable (utile pour utiliser F5 dans vim)
.PHONY : make
make :
	./$(EXEC)

# supprimer les fichiers objet et l'exécutable s'ils existent
.PHONY : clean
clean :
	rm -f $(EXEC) $(OBJECTS)

# effacer le contenu des dossiers d'entrees et de sorties
.PHONY : del
del :
	rm -f sorties/* graphes/*

# ouvrir les fichiers du projet dans des onglets de vim
.PHONY : open
open :
	vim -p $(SOURCES) Makefile Plot.gnu $(OTHER)

# tout compiler et lancer gdb (segmentation fault)
.PHONY : gdb
gdb :
	$(CC) -g $(SOURCES) -o $(EXEC) -lm && gdb ./$(EXEC)

# clean et tarer le dossier
.PHONY : tar
tar :
	make clean
	rm -f .*.swp
	tar -zcvf ../$(PROJECT).tar.gz ../$(PROJECT)

# sauvegarder ancienne version
.PHONY : save
save :
	make clean
	rm -rf ../old_$(PROJECT)
	cp -r ../$(PROJECT) ../old_$(PROJECT)

.PHONY : pdf
pdf :
	xdg-open $(PDF)

#
.PHONY : clean
coffe :
	@echo "  (\n   )\n c[]"
