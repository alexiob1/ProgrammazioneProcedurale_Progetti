# Makefile #
congetture_ggl: congetture_ggl.c Makefile
	gcc -ansi -Wall -O congetture.c -o congetture -lm

pulisci:
	rm -f congetture.o

pulisci_tutto:
	rm -f congetture congetture.o

