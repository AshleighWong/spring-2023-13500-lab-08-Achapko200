#pragma once
#include "imageio.h"
#include <string>
// Flips the image horizontally
void flipHorizontal(int image[MAX_H][MAX_W], int height, int width);

// Negates the image (sets each pixel value to its complement)
void negate(int image[MAX_H][MAX_W], int height, int width);

// Converts the image to grayscale
void grayscale(int image[MAX_H][MAX_W], int height, int width);

// Changes the contrast of the image
void contrast(int image[MAX_H][MAX_W], int height, int width, int c);

// Blurs the image using a simple box filter
void blur(int image[MAX_H][MAX_W], int height, int width, int k);
