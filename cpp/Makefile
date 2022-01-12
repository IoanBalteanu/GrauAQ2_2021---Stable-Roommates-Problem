Program: main Generator Irving
	g++ -o Program main.o Generator.o Irving.o
	
main: main.cpp
	g++ -c 	main.cpp
	
Generator: Generator.cpp Generator.hh
	g++ -c Generator.cpp

Irving: Irving.cpp Irving.hh
	g++ -c Irving.cpp	
    
distclean:
	rm -r Program main.o Generator.o Irving.o
