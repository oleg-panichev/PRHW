//
// Created by Oleg Panichev on 03.03.2016.
//

#include <iostream>
#include "debug.h"
#include "IntImage.h"

using namespace std;

const int rows = 5000;
const int cols = 5000;

int row_top, col_left;
int row_bottom, col_right;

int main() {
	// Creating image
    int val = 1;
	DBGPRINT(DEBUG_LEVEL_MATRICES, "Input image:\n");
	uint8_t** img = new uint8_t*[rows];
    for (int i = 0; i < rows; i++) {
		img[i] = new uint8_t[cols];
        for (int j = 0; j < cols; j++) {
			img[i][j] = 255; // val;
            if (++val > 255)
                val = 0;
			DBGPRINT(DEBUG_LEVEL_MATRICES, "%d\t", img[i][j]);
        }
		DBGPRINT(DEBUG_LEVEL_MATRICES, "\n");
    }

	// Creating Integral image object, which containe integral representation
    IntImage* int_img = new IntImage(img, rows, cols);
	DBGPRINT(DEBUG_LEVEL_MATRICES, "Integral image:\n");
	if (DEBUG_LEVEL >= DEBUG_LEVEL_MATRICES)
		int_img->print_image();
	DBGPRINT(DEBUG_LEVEL_RESULTS, "Integral image data type: %s\n", int_img->getTypeStr());

	// Getting integral brightness of region
    row_top = 0;
	col_left = 0;
    row_bottom = 4;   
    col_right = 4;
	DBGPRINT(DEBUG_LEVEL_RESULTS, "Integral region from (%d,%d) to (%d,%d):\n", row_top, col_left, row_bottom, col_right);
	DBGPRINT(DEBUG_LEVEL_RESULTS, "%d\n", int_img->get_integral(row_top, row_bottom, col_left, col_right));

	system("pause");
    return 0;
}