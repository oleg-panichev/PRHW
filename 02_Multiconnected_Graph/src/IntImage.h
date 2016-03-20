//
// Created by Oleg Panichev on 03.03.2016.
//

#ifndef INTIMAGE_INTIMAGE_H
#define INTIMAGE_INTIMAGE_H

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "debug.h"

using namespace std;

enum imgTypeName {
	IMG16 = 0,
	IMG32,
	IMG64
};

class IntImage {
private:
	uint16_t** img16;
	uint32_t** img32;
	uint64_t** img64;
	imgTypeName type;
	int rows, cols; // Image size
	int maxRows = 0, maxCols = 0; // Maximum numbers of rows and collumns for integral. If equals to 0 - not defined.

	template <typename T>
	void calc_representation(T** img, uint8_t **pInt);

	template <typename T>
	uint64_t gi(T** img, int row_top, int row_bottom, int col_left, int col_right);

public:
    IntImage(uint8_t** _img, int _rows, int _cols) {
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

	IntImage(uint8_t** _img, int _rows, int _cols, int _maxRows, int _maxCols) {
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

	imgTypeName getType() {
		return type;
	}

	uint16_t** get_representation16() {
		return img16;
	}

	uint32_t** get_representation32() {
        return img32;
    }

	uint64_t** get_representation64() {
		return img64;
	}

	//uint64_t get_integral(int row_top, int row_bottom, int col_left, int col_right) {
	//	if (type == IMG16)
	//		return (uint64_t)gi(img16, row_top, row_bottom, col_left, col_right);
	//	else if (type == IMG32) 
	//		return (uint64_t)gi(img32, row_top, row_bottom, col_left, col_right);
	//	else
	//		return (uint64_t)gi(img64, row_top, row_bottom, col_left, col_right);
	//}
};

#endif //INTIMAGE_INTIMAGE_H
