//
// Created by Oleg Panichev on 03.03.2016.
//

#include "IntImage.h"

template <typename T>
void IntImage::calc_representation(T** img, uint8_t **pInt) {
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			img[i][j] = pInt[i][j];
			if (i > 0)
				img[i][j] += img[i - 1][j];
			if (j > 0)
				img[i][j] += img[i][j - 1];
			if (i > 0 && j > 0)
				img[i][j] -= img[i - 1][j - 1];
		}
	}
}

template <typename T>
uint64_t IntImage::gi(T** img, int row_top, int row_bottom, int col_left, int col_right) {	
	uint64_t val = img[row_bottom][col_right];
    if (col_left > 0)
        val -= img[row_bottom][col_left-1];
    if (row_top > 0)
        val -= img[row_top-1][col_right];
    if (col_left > 0 && row_top > 0)
        val += img[row_top-1][col_left-1];
    return val;
}
