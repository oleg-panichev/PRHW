//
// Created by Oleg Panichev on 03.03.2016.
//

#include <iostream>
#include "debug.h"
#include "IntImage.h"
#include "tests.h"

int main() {
	int rows, cols;
	int maxRows, maxCols;
	int val;

	// Creating image  
	rows = 1024;
	cols = 1024;
	DBGPRINT(DEBUG_LEVEL_LOG, "Creating image %dx%d...\n", rows, cols);
	DBGPRINT(DEBUG_LEVEL_MATRICES, "Input image:\n");
	uint8_t** img = new uint8_t*[rows];
	val = 1;
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

	// Creating integral image object, which contains integral representation
	DBGPRINT(DEBUG_LEVEL_LOG, "Creating integral image...\n");
    IntImage* int_img = new IntImage(img, rows, cols);
	DBGPRINT(DEBUG_LEVEL_MATRICES, "Integral image:\n");
	if (DEBUG_LEVEL >= DEBUG_LEVEL_MATRICES)
		int_img->print_image();
	DBGPRINT(DEBUG_LEVEL_RESULTS, "Integral image data type: %s\n", int_img->getTypeStr());

	// Getting integral brightness of region
	test_integral_area(int_img, 1, 1, 3, 3);
	test_integral_area(int_img, 16, 4, 23, 11);
	test_integral_area(int_img, 10, 50, 30, 60);
	test_integral_area(int_img, 0, 0, rows - 1, cols - 1);
	test_integral_area(int_img, 0, 0, rows - 2, cols - 2);
	test_integral_area(int_img, rows - 103, cols - 103, rows - 101, cols - 101);
	test_integral_area(int_img, rows - 33, cols - 23, rows - 31, cols - 21);
	test_integral_area(int_img, rows - 3, cols - 3, rows - 1, cols - 1);


	// Creating integral image object, which contains integral representation with limited area of integration
	DBGPRINT(DEBUG_LEVEL_LOG, "Creating integral image with limited area of integration...\n");
	maxRows = 8;
	maxCols = 8;
	IntImage* int_img_lim = new IntImage(img, rows, cols, maxRows, maxCols);
	DBGPRINT(DEBUG_LEVEL_MATRICES, "Integral image:\n");
	if (DEBUG_LEVEL >= DEBUG_LEVEL_MATRICES)
		int_img_lim->print_image();
	DBGPRINT(DEBUG_LEVEL_RESULTS, "Integral image data type: %s\n", int_img_lim->getTypeStr());

	// Getting integral brightness of region
	test_integral_area(int_img_lim, 1, 1, 3, 3);
	test_integral_area(int_img_lim, 16, 4, 23, 11);
	test_integral_area(int_img_lim, 10, 50, 30, 60);
	test_integral_area(int_img_lim, 0, 0, rows - 1, cols - 1);
	test_integral_area(int_img_lim, 0, 0, rows - 2, cols - 2);
	test_integral_area(int_img_lim, rows - 103, cols - 103, rows - 101, cols - 101);
	test_integral_area(int_img_lim, rows - 33, cols - 23, rows - 31, cols - 21);
	test_integral_area(int_img_lim, rows - 3, cols - 3, rows - 1, cols - 1);

	system("pause");
    return 0;
}

