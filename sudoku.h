// Matthew Perez
// CSE20212
// Lab 5
// sudoku.h: header file for sudoku class

#include <iostream>
#include <fstream>
//#include <cstring>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Puzzle{
	public:
		Puzzle(string);	//constructor
		void print();
	private:
		vector<vector <T> > puzzle;
		int size;	//size of board
};

template <typename T>
Puzzle<T>::Puzzle(string filename){
	ifstream infile;	//read in file
	infile.open(filename.c_str());
	vector<T> tempVec;	//temporary vector
	T tempVar;
	size = 9;
	while(!infile.eof()){
		for(int i=0; i<size; i++){
			infile >> tempVar;
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
			cout<<puzzle[i][j]<< " ";
		}
	cout<<endl;
	}
}
