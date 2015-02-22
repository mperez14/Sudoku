// Matthew Perez
// CSE20212
// Lab 5
// sudoku.h: header file for sudoku class

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Puzzle{
	public:
		Puzzle(string);	//non def. constructor
		void print();	//print board
		int add(int, int, T);	//add element to board
	private:
		vector<vector <T> > puzzle;	//board
		int size;	//size of board
};

template <typename T>
Puzzle<T>::Puzzle(string filename){	//non-default constructor
	size = 9;	//size of board is 9x9
	ifstream infile;	//read in file
	infile.open(filename.c_str());
	vector<T> tempVec;	//temporary vector to store read in values
	T tempVar;	//temp var to read in values
	while(!infile.eof()){
		for(int i=0; i<size; i++){
			infile >> tempVar;	//read in vlaues to tempVar
			tempVec.push_back(tempVar);	//fill temp vector with values read
		}
		puzzle.push_back(tempVec);	//use temp vec to fill puzzle
		tempVec.clear();	//clear temp vector
	}
}

template <typename T>
void Puzzle<T>::print(){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout<<puzzle[i][j]<< " ";	//iterate through, print entire board
		}
	cout<<endl;
	}
	cout<<endl;
}

template <typename T>
int Puzzle<T>::add(int row, int col, T value){
	//check function
	//check rows and columns
	for(int i=0; i<size; i++){
		if(puzzle[row][i] == value){	//if already a value in the row
			cout<<"Error already a value in row"<<endl;
			return -1;
		}
		if(puzzle[i][col] == value){	//if already a value in col
			cout<<"Error already a value in column"<<endl;
			return -1;
		}
	}
	//check mini squares
	for(int i = (row/3)*3; i<(row/3)*3 + 3; i++){	//check row bin (1-3)
		for(int j = (col/3)*3; j<(col/3)*3 +3; j++){	//check col bin(1-3)
			if(puzzle[i][j] == value){	//check if input is same as any of squares in mini-square
				cout<<"Error already a number in mini square"<<endl;	//if so error
				return -1;
			}
		}
	}

	puzzle[row][col] = value; //no errors, add element to position
	return 0;
}
