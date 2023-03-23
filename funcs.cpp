#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imageio.h"
#include "funcs.h"
using namespace std;


// Invert the colors of the image
void invert(int image[MAX_H][MAX_W], int height, int width) {
        for (int row = 0; row < height; row++) {
                for (int col = 0; col < width; col++) {
                        image[row][col] = 255 - image[row][col];
                }
        }
}

// Half invert the colors of the image
void halfInvert(int image[MAX_H][MAX_W], int height, int width) {
        for (int row = 0; row < height; row++) {
                for (int col = 0; col < width/2; col++) {
                        image[row][col] = 255 - image[row][col];
                }
        }
}

// Pixelate the image by averaging values in 2x2 squares
void pixelate(int image[MAX_H][MAX_W], int height, int width) {
        int newImage[MAX_H][MAX_W];
        for (int row = 0; row < height; row += 2) {
                for (int col = 0; col < width; col += 2) {
                        int sum = image[row][col] + image[row+1][col] +
                                  image[row][col+1] + image[row+1][col+1];
                        int avg = sum / 4;
                        newImage[row][col] = avg;
                        newImage[row+1][col] = avg;
                        newImage[row][col+1] = avg;
                      newImage[row+1][col+1] = avg;
                }
        }
}
// Box blur the image
void box(int image[MAX_H][MAX_W], int height, int width) {
        int newImage[MAX_H][MAX_W];
        for (int row = 1; row < height - 1; row++) {
                for (int col = 1; col < width - 1; col++) {
                        int sum = 0;
                        for (int r = -1; r <= 1; r++) {
                                for (int c = -1; c <= 1; c++) {
                                        sum += image[row + r][col + c];
                                }
                        }
                        newImage[row][col] = sum / 9;
                }
        }
        // Copy the new image back into the original image array
        for (int row = 0; row < height; row++) {
                for (int col = 0; col < width; col++) {
                        image[row][col] = newImage[row][col];
                }
        }
}
// Add a frame of pixels around the image
void frame(int image[MAX_H][MAX_W], int height, int width) {
        int newImage[MAX_H][MAX_W];
        // Fill in the corners
        newImage[0][0] = 255;
        newImage[0][width - 1] = 255;
        newImage[height - 1][0] = 255;
        newImage[height - 1][width - 1] = 255;
        // Fill in the top and bottom rows
        for (int col = 1; col < width - 1; col++) {
                newImage[0][col] = 255;
                newImage[height - 1][col] = 255;
        }
        // Fill in the left and right columns
        for (int row = 1; row < height - 1; row++) {
                newImage[row][0] = 255;
                newImage[row][width - 1] = 255;
        }
        // Copy the original image into the center of the new image
        for (int row = 1; row < height - 1; row++) {
                for (int col = 1; col < width - 1; col++) {
                        newImage[row][col] = image[row - 1][col - 1];
                }
        }
        // Copy the new image back into the original image array
        for (int row = 0; row < height; row++) {
                for (int col = 0; col < width; col++) {
                        image[row][col] = newImage[row][col];
                }
        }
}
// Scale the image by a factor of 2
void scale(int image[MAX_H][MAX_W], int &height, int &width) {
    int newImage[MAX_H][MAX_W];
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int value = image[row][col];
            newImage[2 * row][2 * col] = value;
            newImage[2 * row][2 * col + 1] = value;
            newImage[2 * row + 1][2 * col] = value;
            newImage[2 * row + 1][2 * col + 1] = value;
        }
    }
    // Update the height and width variables
    height *= 2;
    width *= 2;
    // Copy the scaled image back to the original array
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            image[row][col] = newImage[row][col];
        }
    }
}