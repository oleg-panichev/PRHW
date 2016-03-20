//
// Created by Oleg Panichev on 03.03.2016.
//

#include <iostream>
#include "debug.h"
#include "IntImage.h"

using namespace std;

const int rows = 5;
const int cols = 5;

int main() {	
    int val = 1;
#ifdef DEBUG_PRINT
    cout << "Input image:" << endl;
#endif
	uint8_t** img = new uint8_t*[rows];
    for (int i=0; i<rows; i++) {
		img[i] = new uint8_t[cols];
        for (int j=0; j<cols; j++) {
            img[i][j] = val;
            val++;
            if (val > 255)
                val = 0;
#ifdef DEBUG_PRINT
            cout << img[i][j] << "\t";
#endif
        }
#ifdef DEBUG_PRINT
        cout << endl;
#endif
    }

    IntImage* int_img = new IntImage(img, rows, cols);
//	imgTypeName type = int_img->getType();
//	if (type == IMG16)
//	{
//		//uint16_t** iimg = int_img->get_representation16();
//#ifdef DEBUG_PRINT
//		//cout << "Integral image:" << endl;
//		//for (int i = 0; i < rows; i++) {
//		//	for (int j = 0; j < cols; j++) {
//		//		cout << iimg[i][j] << "\t";
//		//	}
//		//	cout << endl;
//		//}
//#endif
//	}

#ifdef DEBUG_PRINT
    cout << "Integral region:" << endl;
#endif
    int row_top = 0;
    int row_bottom = 4;
    int col_left = 0;
    int col_right = 4;
#ifdef DEBUG_PRINT
//    cout << int_img->get_integral(row_top, row_bottom, col_left, col_right) << endl;
#endif

	system("pause");
    return 0;
}