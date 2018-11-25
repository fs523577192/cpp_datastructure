
SHELL := /bin/bash

all: MutableList.o MutableSet.o BinaryTree.o

MutableList.o: src/list/MutableList.hpp src/list/List.hpp Collection.o
	[[ -d target/list ]] || mkdir target/list -p
	g++ -Wall -std=c++11 -c src/list/MutableList.hpp -o target/list/MutableList.o

MutableSet.o: src/set/MutableSet.hpp src/set/Set.hpp Collection.o
	[[ -d target/set ]] || mkdir target/set -p
	g++ -Wall -std=c++11 -c src/set/MutableSet.hpp -o target/set/MutableSet.o

BinaryTree.o: src/tree/BinaryTree.hpp src/tree/Tree.hpp Collection.o
	[[ -d target/tree ]] || mkdir target/tree -p
	g++ -Wall -std=c++11 -c src/tree/BinaryTree.hpp -o target/tree/BinaryTree.o

Collection.o: src/Collection.hpp src/Iterable.hpp src/Iterator.hpp src/common.hpp src/interface.hpp src/typeAlias.hpp
	[[ -d target ]] || mkdir target
	g++ -Wall -std=c++11 -c src/Collection.hpp -o target/Collection.o

Optional.o: src/Optional.cpp src/common.hpp src/interface.hpp src/typeAlias.hpp
	[[ -d target ]] || mkdir target
	g++ -Wall -std=c++11 -c src/Optional.hpp -o target/Optional.o

clean:
	rm -rf target
