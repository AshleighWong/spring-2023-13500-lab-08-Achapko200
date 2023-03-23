#include <sstream>
#include <cctype>
#include <string>
#include "funcs.h"
#include "imageio.h"

int main() {
    int img[MAX_H][MAX_W];
    int height, width;
    int out[MAX_H][MAX_W];
    readImage("image1.pgm",img, height, width);

    // Invert colors
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img[i][j] = 255 - img[i][j];
        }
    }
  writeImage("taskA.pgm", out, height, width);
// Invert colors in right half
    for (int i = 0; i < height; i++) {
        for (int j = width/2; j < width; j++) {
            img[i][j] = 255 - img[i][j];
        }
    }
  writeImage("taskB.pgm", out, height, width);
    int box_width = width / 2;
    int box_height = height / 2;
    int box_x = (width - box_width) / 2;
    int box_y = (height - box_height) / 2;

    for (int i = box_y; i < box_y + box_height; i++) {
        for (int j = box_x; j < box_x + box_width; j++) {
            img[i][j] = 255;
        }
    }
  writeImage("taskC.pgm", out, height, width);
  for(int row = 0; row < MAX_H; row++) {
for(int col = 0; col < MAX_W; col++) {
if(row == MAX_H/4 || row == (3*MAX_H)/4)
{
if(col >=MAX_W/4 && col <=(3*MAX_W)/4)
out[row][col] = 255;
else
out[row][col] = img[row][col];
}else if(col == MAX_W/4 || col == (3*MAX_W)/4)
{
if(row >= MAX_H/4 && row <= (3*MAX_H)/4)
out[row][col] = 255;
else
out[row][col] = img[row][col];

}else
out[row][col] = img[row][col];
}
}
writeImage("taskD.pgm", out, height, width);
int avg = 0;
int h, w;

int scalingFactor = 2;

// reset the width and height of the images
h = h * scalingFactor;
w = w * scalingFactor;

// declare a temporary variable
int temp;

// loop through each new row
for (int row = 0; row < h; row = row+2)
{
// loop through each new column
for (int col = 0; col < w; col = col+2)
{
// get the original value present in the img
temp = img[row / 2][col / 2];

// copy the value to resize
out[row][col] = temp;
out[row + 1][col] = temp;
out[row][col + 1] = temp;
out[row + 1][col + 1] = temp;
}
}
  writeImage("taskE.pgm", out, height, width);
  for(int row = 0; row < MAX_H; row++) {
            for(int col = 0; col < MAX_W; col++) {
                if(row % 2 == 0) {
                   if(col % 2 == 0) {
                      out[row][col] = (img[row][col]+img[row+1][col]+img[row][col+1]+img[row+1][col+1]) / 4;
               } else {
                  out[row][col] = (img[row][col]+img[row+1][col]+img[row][col-1]+img[row+1][col-1]) / 4;
               }
            } else {
               if(col % 2 == 0) {
                      out[row][col] = (img[row][col]+img[row-1][col]+img[row-1][col+1]+img[row][col+1]) / 4;
               } else {
                  out[row][col] = (img[row][col]+img[row-1][col]+img[row][col-1]+img[row-1][col-1]) / 4;
               }
            }
            }
        }
  writeImage("taskF.pgm", out, height, width);
    return 0;
}
