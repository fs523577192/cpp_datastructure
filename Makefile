
SHELL := /bin/bash

all: MutableList.o MutableSet.o

MutableList.o: src/list/MutableList.hpp src/list/List.hpp Collection.o
	[[ -d target/list ]] || mkdir target/list -p
	g++ -c src/list/MutableList.hpp -o target/list/MutableList.o

MutableSet.o: src/set/MutableSet.hpp src/set/Set.hpp Collection.o
	[[ -d target/set ]] || mkdir target/set -p
	g++ -c src/set/MutableSet.hpp -o target/set/MutableSet.o

Collection.o: src/Collection.hpp src/Iterable.hpp src/Iterator.hpp src/common.hpp src/interface.hpp src/typeAlias.hpp
	[[ -d target ]] || mkdir target
	g++ -c src/Collection.hpp -o target/Collection.o
