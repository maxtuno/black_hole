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

#ifndef BLACK_HOLE_LITERAL_H
#define BLACK_HOLE_LITERAL_H

#include "../global.h"

/**
 * The literal structure
 */
typedef struct literal {
    integer variable;
} literal;

/**
 * Create a new literal
 * @return allocated literal
 */
literal *literal_new();

/**
 * Get the pure variable without polarity
 * @param literal
 * @return variable
 */
integer literal_to_variable(literal *lit);

/**
 * Change the polarity of the literal
 * @param literal
 * @return negated literal
 */
literal *literal_negate(literal *lit);

/**
 * Compare two variables of literals
 * @param literal_l
 * @param literal_r
 * @return -1 if <, 0 if ==, 1 if >
 */
integer literal_compare_variables(literal *lit_l, literal *lit_r);

/**
 * Compare two literals
 * @param literal_l
 * @param literal_r
 * @return -1 if <, 0 if ==, 1 if >
 */
integer literal_compare_literals(literal *lit_l, literal *lit_r);

/**
 * Print the literal
 * @param lit
 */
void literal_print(literal *lit);

#endif /* BLACK_HOLE_LITERAL_H */
