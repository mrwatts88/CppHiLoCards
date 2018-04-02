
main.out : main.o Deck.o
	g++ -o main.out main.o Deck.o

main.o : main.cpp Deck.h
	g++ -c main.cpp

Deck.o : Deck.h Deck.cpp
	g++ -c Deck.cpp

clean:
	rm -rf *.o
	touch *
