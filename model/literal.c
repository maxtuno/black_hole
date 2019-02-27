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

#include "literal.h"

literal *literal_new() {
    literal *lit = (literal *) malloc(sizeof(literal));
    lit->variable = 0;
    return lit;
}

integer literal_to_variable(literal *lit) {
    return ABS(lit->variable);
}

literal *literal_negate(literal *lit) {
    lit->variable = -lit->variable;
    return lit;
}

integer literal_compare_variables(literal *lit_l, literal *lit_r) {
    if (literal_to_variable(lit_l) < literal_to_variable(lit_r)) {
        return -1;
    } else if (literal_to_variable(lit_l) > literal_to_variable(lit_r)) {
        return 1;
    } else {
        return 0;
    }
}

integer literal_compare_literals(literal *lit_l, literal *lit_r) {
    if (lit_l->variable < lit_r->variable) {
        return -1;
    } else if (lit_l->variable > lit_r->variable) {
        return 1;
    } else {
        return 0;
    }
}

void literal_print(literal *lit) {
    printf("%i", lit->variable);
}