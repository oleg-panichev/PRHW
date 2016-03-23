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
	void calc_representation(T **img, uint8_t **pInt);

	template <typename T>
	void calc_representation(T** img, uint8_t **pInt, int mod);

	template <typename T>
	uint64_t gi(T** img, int row_top, int row_bottom, int col_left, int col_right);

	template <typename T>
	void printt(T **img) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << img[i][j] << "\t";
			}
			cout << endl;
		}
	}

public:
	IntImage(uint8_t** _img, int _rows, int _cols);

	IntImage(uint8_t** _img, int _rows, int _cols, int _maxRows, int _maxCols);

	~IntImage() {}

	imgTypeName getType() {
		return type;
	}

	char* getTypeStr() {
		if (type == IMG16)
			return "uint16";
		else if (type == IMG32)
			return "uint32";
		else
			return "uint64";
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

	void print_image() {
		if (type == IMG16)
			printt(img16);
		else if (type == IMG32)
			printt(img32);
		else
			printt(img64);
	}

	uint64_t get_integral(int row_top, int row_bottom, int col_left, int col_right);
};

#endif //INTIMAGE_INTIMAGE_H
