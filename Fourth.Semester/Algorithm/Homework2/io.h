#ifndef __IO_H__
#define __IO_H__

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

ELEMENT* read_data(const char* filename, int cnt);
void write_data(const char* filename, int cnt, ELEMENT* elements);

#endif
