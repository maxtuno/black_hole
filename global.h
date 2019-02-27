/*
Copyright (c) 2012-2019 Oscar Riveros. all rights reserved. oscar.riveros@peqnp.science
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef BLACK_HOLE_GLOBAL_H
#define BLACK_HOLE_GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#define ABS(x) ((x) > 0 ? (x) : -(x))
#define INDEX(x) (ABS(x) - 1)

/**
 * Generic string type
 */
typedef char* string;

/**
 * All integers can be from this type
 */
typedef int integer;

/**
 * Generic dimensions, sizes, counters, all not integer types
 */
typedef unsigned int dimension;

#endif /* BLACK_HOLE_GLOBAL_H */
