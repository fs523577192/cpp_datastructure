
SHELL := /bin/bash

all: MutableList.o MutableSet.o BinaryTree.o

MutableList.o: src/main/list/MutableList.hpp src/main/list/List.hpp Collection.o
	[[ -d target/list ]] || mkdir target/list -p
	g++ -Wall -std=c++11 -c src/main/list/MutableList.hpp -o target/list/MutableList.o

MutableSet.o: src/main/set/MutableSet.hpp src/main/set/Set.hpp Collection.o
	[[ -d target/set ]] || mkdir target/set -p
	g++ -Wall -std=c++11 -c src/main/set/MutableSet.hpp -o target/set/MutableSet.o

BinaryTree.o: src/main/tree/BinaryTree.hpp src/main/tree/Tree.hpp Collection.o
	[[ -d target/tree ]] || mkdir target/tree -p
	g++ -Wall -std=c++11 -c src/main/tree/BinaryTree.hpp -o target/tree/BinaryTree.o

Collection.o: src/main/Collection.hpp src/main/Iterable.hpp src/main/Iterator.hpp src/main/common.hpp src/main/interface.hpp src/main/typeAlias.hpp
	[[ -d target ]] || mkdir target
	g++ -Wall -std=c++11 -c src/main/Collection.hpp -o target/Collection.o

Exception.o: src/main/Exception.cpp src/main/common.hpp src/main/interface.hpp src/main/typeAlias.hpp
	[[ -d target ]] || mkdir target
	g++ -Wall -std=c++11 -c src/main/Exception.cpp -o target/Exception.o

ExceptionTests.exe: src/test/ExceptionTests.cpp Exception.o
	[[ -d target ]] || mkdir target
	g++ -Wall -std=c++11 src/test/ExceptionTests.cpp -o target/ExceptionTests.exe

clean:
	rm -rf target
