test: mainTest.o TrajetSimple.o ElemTrajet.o ListeChainee.o

	g++ -o test TrajetSimple.o mainTest.o ElemTrajet.o ListeChainee.o

mainTest.o : mainTest.cpp

	g++ -c -ansi -pedantic -Wall -std=c++11 mainTest.cpp

TrajetSimple.o : TrajetSimple.cpp

	g++ -c -ansi -pedantic -Wall -std=c++11 TrajetSimple.cpp

ElemTrajet.o : ElemTrajet.cpp

	g++ -c -ansi -pedantic -Wall -std=c++11 ElemTrajet.cpp

ListeChainee.o : ListeChainee.cpp

	g++ -c -ansi -pedantic -Wall -std=c++11 ListeChainee.cpp
