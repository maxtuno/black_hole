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

#ifndef BLACK_HOLE_FORMULA_H
#define BLACK_HOLE_FORMULA_H

#include "../global.h"
#include "literal.h"
#include "clause.h"
#include "assigment.h"

typedef struct formula {
    clause **clauses;
    dimension length;
    dimension size;
    literal **positives;
    literal **negatives;
} formula;

/**
 * Create a new formula
 * @return
 */
formula *formula_new();

/**
 * Add clause to formula
 * @param frm
 * @param cls
 * @return
 */
formula *formula_add_clause(formula *frm, clause *cls) ;

/**
 * Remove a clause from formula
 * @param cls
 * @return
 */
formula *formula_remove_clause(formula *frm, clause *cls);

/**
 * Change internal polarity of literals
 * @param frm
 * @return
 */
formula *formula_change_polarity(formula *frm);

/**
 * Change polarity of a single variable in the space
 * @param frm
 * @param variable
 * @return
 */
formula *formula_change_polarity_variable(formula *frm, integer variable);

/**
 * Create the internal space of literals
 * @param frm
 * @param length
 * @return
 */
formula *formula_create_space(formula *frm, dimension length);

/**
 * Parse a CNF file into a formula
 * @param file_name current cnf path
 * @return parsed formula
 */
formula *parse_from_file(string file_name);

/**
 * Swap the polarities between two variables
 * @param frm
 * @param var_l
 * @param var_r
 * @return
 */
formula *formula_swap_polarity_variables(formula *frm, integer var_l, integer var_r);

/**
 * Print the formula
 * @param frm
 */
void formula_print(formula *frm);

/**
 * Print the current model;
 * @param frm
 */
void formula_print_model(formula *frm, assigment *asg);

#endif /* BLACK_HOLE_FORMULA_H */
