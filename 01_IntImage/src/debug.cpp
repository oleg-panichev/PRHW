//
// Created by Oleg Panichev on 03.03.2016.
//

#include "debug.h"

void debug_print(int msg_level, std::string format, ...)
{
	if (DEBUG_LEVEL >= msg_level) {
		va_list arg;
		va_start(arg, format);
		vprintf(format.c_str(), arg);
		va_end(arg);
	}
}
