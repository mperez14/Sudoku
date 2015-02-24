//Matthew Perez
//CSE 20212
//Lab 5
//main.cpp: main file for sudoku

#include <iostream>
#include "sudoku.h"

using namespace std;

int main(){
	//int row, col, num;
	cout<<"**********predefined sudoku**********"<<endl;
	Puzzle<int> sudoku1("puzzle.txt");	//number text from class document
	sudoku1.print();

	cout<<"**********predefined wordoku**********"<<endl;
	Puzzle<char> sudoku2("puzzle2.txt");	//character text
	sudoku2.print();

	cout<<"**********almost finished sudoku**********"<<endl;
	Puzzle<int> sudoku3("puzzle3.txt");	//test complete() function. Add 1 to row 9, col 9
	sudoku3.play();

	cout<<"**********blank sudoku**********"<<endl;
	Puzzle<int> sudoku4;	//init blank sudoku board
	sudoku4.play();	


}
