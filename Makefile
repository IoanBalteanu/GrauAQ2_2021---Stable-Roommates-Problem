Program: main Generator
	g++ -o Program main.o Generator.o
	
main: main.cpp
	g++ -c 	main.cpp
	
Generator: Generator.cpp Generator.hh
	g++ -c Generator.cpp
	
distclean:
	rm -r Program main.o Generator.o
