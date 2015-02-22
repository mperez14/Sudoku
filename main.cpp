//Matthew Perez
//CSE 20212
//Lab 5
//main.cpp: main file for sudoku

#include <iostream>
//#include "puzzle.txt"
#include "sudoku.h"

using namespace std;

int main(){
	int row, col, num;
	Puzzle<int> sudoku1("puzzle.txt");	//number text
	sudoku1.print();

	Puzzle<char> sudoku2("puzzle2.txt");	//character text
	sudoku2.print();

	cout<<"Enter number: ";
	cin>>num;
	cout<<"Enter row: ";
	cin>>row;
	cout<<"Enter column: ";
	cin>>col;
	sudoku1.add(row-1, col-1, num);

	sudoku1.print();

}
