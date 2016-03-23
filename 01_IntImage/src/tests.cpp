//
// Created by Oleg Panichev on 03.03.2016.
//

#include "tests.h"

void test_integral_area(IntImage* img, int row_top, int col_left, int row_bottom, int col_right) {
	DBGPRINT(DEBUG_LEVEL_RESULTS, "[TEST] Integral region from (%d,%d) to (%d,%d): ", row_top, col_left, row_bottom, col_right);
	DBGPRINT(DEBUG_LEVEL_RESULTS, "%u\n", (uint64_t)img->get_integral(row_top, row_bottom, col_left, col_right));
}