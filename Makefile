make all: transmissor.o receptor.o comunicacao.o main.o
	g++ transmissor.o receptor.o comunicacao.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp

transmissor.o: ./modulos/transmissor/transmissor.cpp ./modulos/transmissor/transmissor.hpp
	g++ -c ./modulos/transmissor/transmissor.cpp

receptor.o: ./modulos/receptor/receptor.cpp ./modulos/receptor/receptor.hpp
	g++ -c ./modulos/receptor/receptor.cpp

comunicacao.o: ./modulos/comunicacao/comunicacao.cpp ./modulos/comunicacao/comunicacao.hpp
	g++ -c ./modulos/comunicacao/comunicacao.cpp

clean:
	rm -rf *.o main