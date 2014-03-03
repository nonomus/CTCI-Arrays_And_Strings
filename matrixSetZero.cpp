#include <iostream>
#include <vector>
//***********************NOTE***********************
//THIS MODULE NEEDS TO BE REWRITTEN USING VECTORS INSTEAD OF ARRAYS.
//Reason: could simplify a lot of things with c++ std library ones.
using namespace std;

//Sets a row of an nxm matrix to be all 0.
void setRowToZero(int matrix[][4], int row, int m){
	for(int i = 0; i < m; i++){
		matrix[row][i] = 0;
	}
}

//Sets a col of an nxm matrix to be all 0.
void setColToZero(int matrix[][4], int col, int n){
	for(int i = 0; i < n; i++){
		matrix[i][col] = 0;
	}
}

//Write an algorithm such that if an element in an MxN matrix is 0, its entire row
//and column are set to 0.
void setZeroes(int matrix[][4], int n, int m){
	vector<bool> rows(n, false);
	vector<bool> columns(m, false);
	//Fill the rows/columns with true whenever 
	//a 0 appears in a matrix.
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 0){
				rows[i] = true;
				columns[j] = true;
			}
		}
	}
	//Go through every element in rows and set the row to zero
	//if the previous loop indicated a 0 at that row.
	for(int i = 0; i < n; i++){
		if(rows[i]) setRowToZero(matrix, i, m);
	}
	//Same thing for columns..
	for(int i = 0; i < m; i++){
		if(columns[i]) setColToZero(matrix, i, n);
	}
}

void printMatrix(int matrix[][4], int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

int main(){
	cout << "matrixSetZero test cases:" << endl;
	int matrix[][4] = {{1,2,3,4},
					  {5,6,7,0},
					  {1,2,0,4},
					  {5,6,7,8}};
	printMatrix(matrix, 4,4);

	setZeroes(matrix, 4, 4);

	printMatrix(matrix, 4, 4);

	return 0;
}