all: main

main: main.o parcel.o
	g++ main.o parcel.o -o a

main.o: main.cpp
	g++ -c main.cpp

parcel.o: parcel.cpp
	g++ -c parcel.cpp
