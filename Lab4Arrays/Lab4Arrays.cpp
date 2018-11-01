// Sarah Withee
// February 9, 2013
// Lab #4 (2D arrays)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// Create input and output file streams
	ifstream fin;
	ofstream fout;

	// Create variables to store matrix information in
	int rows, cols;
	int matrix[20][20];     // I'm doing it with one, but most will probably use 2-3

	// Open up file streams
	fin.open("input.txt");
	fout.open("output.txt");

	// Start loop for reading in files
	// Loop reads in rows/cols, if fail quits loop
	while (fin >> rows >> cols) {
		
		// Output rows and cols
		fout << rows << " " << cols<< endl;

		// Loop for reading in first matrix
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				int val;
				fin >> val;
				// Store first value in matrix
				matrix[i][j] = val;
			}
		}
		// Loop for reading in 2nd matrix, summing, and outputing answer
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				int val;
				fin >> val;
				// Output matrix1 + value just read in from matrix 2, and output to file
				// No need to store in memory
				fout << matrix[i][j] + val << " ";
			}
			// Print each row of values on a new line
			fout << endl;
		}
	}
	
	// And end nicely!
	return 0;
}