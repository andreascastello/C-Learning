all: main.c interfaceGraphique.o jeu.o
	gcc main.c interfaceGraphique.o jeu.o -o jeu -Wall -lX11 -lGL -lm

interfaceGraphique.o: interfaceGraphique.h interfaceGraphique.c
	gcc -c interfaceGraphique.c -o interfaceGraphique.o

jeu.o: jeu.h jeu.c
	gcc -c jeu.c -o jeu.o

clean:
	rm -f *.o jeu

install:
	sudo apt update && sudo apt -y upgrade && sudo apt -y dist-upgrade && sudo apt -y autoremove
	sudo apt install -y mesa-common-dev libglu1-mesa-dev
	sudo apt -y install libbluetooth-dev 
