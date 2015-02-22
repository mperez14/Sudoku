//Matthew Perez
//CSE 20212
//Lab 5
//main.cpp: main file for sudoku

#include <iostream>
//#include "puzzle.txt"
#include "sudoku.h"

using namespace std;

int main(){
	Puzzle<int> sudoku1("puzzle.txt");
	sudoku1.print();
}
