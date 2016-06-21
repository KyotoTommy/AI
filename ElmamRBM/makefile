#Makefile for ElmanRBM
ElmanRBM.exe:ElmanRBMFunc.o ElmanRBM.cc RBMFunc.o
	g++ ElmanRBM.cc -o ElmanRBM.exe ElmanRBMFunc.o RBMFunc.o -std=c++0x

ElmanRBMFunc.o:ElmanRBMFunc.cc ElmanRBMFunc.h
	g++ -c ElmanRBMFunc.cc -std=c++0x

