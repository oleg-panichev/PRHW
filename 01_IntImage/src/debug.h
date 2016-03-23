//
// Created by Oleg Panichev on 03.03.2016.
//

#ifndef DEBUG_H
#define DEBUG_H

#include <stdarg.h> 
#include <stdio.h>
#include <string>

#define DEBUG_LEVEL 150

#define DEBUG_LEVEL_NONE 0
#define DEBUG_LEVEL_LOG 20
#define DEBUG_LEVEL_RESULTS 100
#define DEBUG_LEVEL_MATRICES 200
#define DEBUG_LEVEL_ALL 255

#define DBGPRINT(msg_level, format, ...) debug_print(msg_level, format, __VA_ARGS__)

void debug_print(int msg_level, std::string format, ...);

#endif // DEBUG_H
