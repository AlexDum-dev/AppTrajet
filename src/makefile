main: main.o TrajetSimple.o ElemTrajet.o ListeChainee.o TrajetCompose.o Catalogue.o

	g++ -o main TrajetSimple.o main.o ElemTrajet.o ListeChainee.o TrajetCompose.o Catalogue.o

main.o : main.cpp

	g++ -c -ansi -pedantic -Wall -std=c++11 main.cpp

TrajetSimple.o : TrajetSimple.cpp

	g++ -c -DMAP -ansi -pedantic -Wall -std=c++11 TrajetSimple.cpp

ElemTrajet.o : ElemTrajet.cpp

	g++ -c -DMAP -ansi -pedantic -Wall -std=c++11 ElemTrajet.cpp

ListeChainee.o : ListeChainee.cpp

	g++ -c -DMAP -ansi -pedantic -Wall -std=c++11 ListeChainee.cpp

TrajetCompose.o : TrajetCompose.cpp

	g++ -c -DMAP -ansi -pedantic -Wall -std=c++11 TrajetCompose.cpp

Catalogue.o : Catalogue.cpp

	g++ -c -DMAP -ansi -pedantic -Wall -std=c++11 Catalogue.cpp


debug :

	g++ -std=c++11 -g3 -o debug main.cpp TrajetSimple.cpp ElemTrajet.cpp ListeChainee.cpp TrajetCompose.cpp Catalogue.cpp

clean : 

	rm *.o main debug 

