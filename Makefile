all:
	gcc tt.c -o tt
clean:
	rm tt
install:
	cp tt ${HOME}/bin
strip:
	strip tt
