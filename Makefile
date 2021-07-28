make all: utils.o transmissor.o receptor.o comunicacao.o main.o
	g++ utils.o transmissor.o receptor.o comunicacao.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp

transmissor.o: ./modulos/transmissor/transmissor.cpp ./modulos/transmissor/transmissor.hpp
	g++ -c ./modulos/transmissor/transmissor.cpp

receptor.o: ./modulos/receptor/receptor.cpp ./modulos/receptor/receptor.hpp
	g++ -c ./modulos/receptor/receptor.cpp

comunicacao.o: ./modulos/comunicacao/comunicacao.cpp ./modulos/comunicacao/comunicacao.hpp
	g++ -c ./modulos/comunicacao/comunicacao.cpp

utils.o: ./modulos/utils/utils.cpp ./modulos/utils/utils.hpp
	g++ -c ./modulos/utils/utils.cpp

clean:
	rm -rf *.o main