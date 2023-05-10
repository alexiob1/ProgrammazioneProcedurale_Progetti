# Makefile #
congetture_ggl: congetture_ggl.c Makefile
	gcc -ansi -Wall -O congetture_ggl.c -o congetture_ggl -lm

pulisci:
	rm -f congetture_ggl.o

pulisci_tutto:
	rm -f congetture congetture_ggl.o

