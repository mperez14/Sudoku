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
		Puzzle();	//def constructor
		Puzzle(string);	//non def. constructor
		void print();	//print board
		int add(int, int, T);	//add element to board
		//int check();
		int complete();	//check if board is completed
		void play();	//get user input. complete sudoku
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
Puzzle<T>::Puzzle(){	//create 9x9 board
	size = 9;
	vector<T> tempVec;
	for(int i=0; i<size;i++){
		for(int j=0; j<size; j++){
			tempVec.push_back(0);	//create tempVec full of 0's
		}
		puzzle.push_back(tempVec);	//add tempVec's to puzzle vector
	}
}

template <typename T>
void Puzzle<T>::print(){
	string d;
	string f;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(j%3 == 2 && j<6)	//print dividing lines (mini squares)
				d = "| ";
			else
				d = "";
			cout<<puzzle[i][j]<< " "<<d;	//iterate through, print entire board
		}
		if(i%3 ==2 && i<6)
			cout<<endl<<"-----------------------";	//dividing horizontal lines (mini squares)
		cout<<endl;
	}
	cout<<endl;
}
/*
template <typename T>
int Puzzle<T>::check(){
for(int value=0; value<size; value++){

for(int j = 0; j<size; j++){
	for(int i=0; i<size; i++){
		if(puzzle[j][i] == value){	//if already a value in the row
			cout<<"Error. Same values in row "<<j<<endl;
			cout<<"value error:"<<value<<endl;
			return -1;
		}
		if(puzzle[i][j] == value){	//if already a value in col
			cout<<"Error. Same values in column "<<j<<endl;
			return -1;
		}
	}
}
	//check mini squares
for(int check=0; check<9; check+=3){
	for(int i = (check/3)*3; i<(check/3)*3 + 3; i++){	//check row bin (1-3)
		for(int j = (check/3)*3; j<(check/3)*3 +3; j++){	//check col bin(1-3)
			if(puzzle[i][j] == value){	//check if input is same as any of squares in mini-square
				cout<<"Error. Same values in mini square"<<endl;	//if so error
				return -1;
			}
		}
	}
}
}

return 0;
}
*/
template <typename T>
int Puzzle<T>::add(int row, int col, T value){
	//check input is valid
	if(value>9|| value<1){
		cout<<"Error. limit number to 1-9"<<endl;
		return -1;
	}
	if(row>9 || row<1 || col>9 || col<1){
		cout<<"Error. position is out of bounds"<<endl;
		return -1;
	}
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

template <typename T>
int Puzzle<T>::complete(){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(puzzle[i][j] == 0){	//check if any elements in board are 0
				return -1;
			}
		}
	}
	cout<<"Sudoku completed!"<<endl;	//if no 0's. you win!!!
	return 0; 

}

template <typename T>
void Puzzle<T>::play(){
	int col, row;
	T num;
	while(complete() == -1){	//check if board is completed
		print();		//print board
		cout<<"Enter number: ";	//ask for user input
		cin>>num;
		cout<<"Enter row: ";
		cin>>row;
		cout<<"Enter column: ";
		cin>>col;
		add(row-1, col-1, num);	//check if valid & add piece
	}
}
