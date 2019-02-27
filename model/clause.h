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

#ifndef BLACK_HOLE_CLAUSE_H
#define BLACK_HOLE_CLAUSE_H

#include "../global.h"
#include "literal.h"

typedef struct clause {
    literal **literals;
    dimension size;
} clause;

/**
 * Crate new clause
 * @return allocated clause
 */
clause *clause_new();

/**
 * Add literal to clause
 * @param clause
 * @param literal
 * @return clause with new literal
 */
clause *clause_add_literal(clause *cls, literal *lit);

/**
 * Remove the first occurrence of lit on cls
 * @param cls
 * @param lit
 * @return cleaned clause
 */
clause *clause_remove_literal(clause *cls, literal *lit);

/**
 * Compare two clauses without order
 * @param cls_l
 * @param cls_r
 * @return true if equal else false
 */
bool clause_compare_clauses(clause *cls_l, clause *cls_r);

/**
 * Say if a clause contains a specific literal
 * @param cls
 * @param lit
 * @return
 */
bool clause_contains_literal(clause *cls, literal *lit);

/**
 * Print hte clause
 * @param cls
 */
void clause_print(clause *cls);

#endif /* BLACK_HOLE_CLAUSE_H */
