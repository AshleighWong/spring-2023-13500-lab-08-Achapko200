#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

#include "imageio.h"


// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open(filename);

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open(filename);
	if (ostr.fail()) {
		std::cout << "Unable to write file\n";
		exit(1);
	}

	// print the header
	ostr << "P2\n";
	// width, height
	ostr << width << ' ';
	ostr << height << std::endl;
	ostr << 255 << std::endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (image[row][col] < 0 || image[row][col] >= 256) {
				std::cerr << "Invalid pixel value: " << row << ", col " << col << ": " << image[row][col] << std::endl;
				exit(1);
			}
			ostr << image[row][col] << ' ';
		}
		ostr << std::endl;
	}
	ostr.close();
}

