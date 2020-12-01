test: mainTest.o TrajetSimple.o ElemTrajet.o ListeChainee.o TrajetCompose.o

	g++ -o test TrajetSimple.o mainTest.o ElemTrajet.o ListeChainee.o TrajetCompose.o

mainTest.o : mainTest.cpp

	g++ -c -ansi -pedantic -Wall -std=c++11 mainTest.cpp

TrajetSimple.o : TrajetSimple.cpp

	g++ -c -ansi -pedantic -Wall -std=c++11 TrajetSimple.cpp

ElemTrajet.o : ElemTrajet.cpp

	g++ -c -ansi -pedantic -Wall -std=c++11 ElemTrajet.cpp

ListeChainee.o : ListeChainee.cpp

	g++ -c -ansi -pedantic -Wall -std=c++11 ListeChainee.cpp

TrajetCompose.o : TrajetCompose.cpp

	g++ -c -ansi -pedantic -Wall -std=c++11 TrajetCompose.cpp

debug :

	g++ -std=c++11 -g3 -o debug mainTest.cpp TrajetSimple.cpp ElemTrajet.cpp ListeChainee.cpp TrajetCompose.cpp

clean : 

	rm *.o

