//
// Created by Oleg Panichev on 03.03.2016.
//

#include "IntImage.h"

IntImage::IntImage(uint8_t** _img, int _rows, int _cols) {
	rows = _rows;
	cols = _cols;
	int maxSum = ceil(log2(rows*cols)) + 8;
	if (maxSum <= 16) 
	{
		type = IMG16;
		img16 = new uint16_t*[rows];
		for (int i = 0; i < rows; i++)
			img16[i] = new uint16_t[cols];
		calc_representation(img16, _img);
	}
	else if (maxSum > 16 && maxSum <= 32) 
	{
		type = IMG32;
		img32 = new uint32_t*[rows];
		for (int i = 0; i < rows; i++)
			img32[i] = new uint32_t[cols];
		calc_representation(img32, _img);
	}
	else 
	{
		type = IMG64;
		img64 = new uint64_t*[rows];
		for (int i = 0; i < rows; i++)
			img64[i] = new uint64_t[cols];
		calc_representation(img64, _img);
	}
}

IntImage::IntImage(uint8_t** _img, int _rows, int _cols, int _maxRows, int _maxCols) {
	rows = _rows;
	cols = _cols;
	maxRows = _maxRows;
	maxCols = _maxCols;

	int maxSum = ceil(log2(maxRows*maxCols)) + 8;
	if (maxSum <= 16)
	{
		type = IMG16;
		img16 = new uint16_t*[rows];
		for (int i = 0; i < rows; i++)
			img16[i] = new uint16_t[cols];
		calc_representation(img16, _img);
	}
	else if (maxSum > 16 && maxSum <= 32)
	{
		type = IMG32;
		img32 = new uint32_t*[rows];
		for (int i = 0; i < rows; i++)
			img32[i] = new uint32_t[cols];
		calc_representation(img32, _img);
	}
	else
	{
		type = IMG64;
		img64 = new uint64_t*[rows];
		for (int i = 0; i < rows; i++)
			img64[i] = new uint64_t[cols];
		calc_representation(img64, _img);
	}
	
}

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

uint64_t IntImage::get_integral(int row_top, int row_bottom, int col_left, int col_right) {
	if (type == IMG16)
		return (uint64_t)gi(img16, row_top, row_bottom, col_left, col_right);
	else if (type == IMG32)
		return (uint64_t)gi(img32, row_top, row_bottom, col_left, col_right);
	else
		return (uint64_t)gi(img64, row_top, row_bottom, col_left, col_right);
}

template <typename T>
inline uint64_t IntImage::gi(T** img, int row_top, int row_bottom, int col_left, int col_right) {
	uint64_t val = img[row_bottom][col_right];
    if (col_left > 0)
        val -= img[row_bottom][col_left-1];
    if (row_top > 0)
        val -= img[row_top-1][col_right];
    if (col_left > 0 && row_top > 0)
        val += img[row_top-1][col_left-1];
    return val;
}
