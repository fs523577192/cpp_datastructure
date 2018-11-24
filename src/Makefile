
MutableList.o: list/MutableList.hpp list/List.hpp Collection.o
	g++ -c list/MutableList.hpp -o list/MutableList.o

MutableSet.o: set/MutableSet.hpp set/Set.hpp Collection.o
	g++ -c set/MutableSet.hpp -o set/MutableSet.o

Collection.o: Collection.hpp Iterable.hpp Iterator.hpp common.hpp interface.hpp typeAlias.hpp
	g++ -c Collection.hpp -o Collection.o
