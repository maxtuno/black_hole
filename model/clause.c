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

#include "clause.h"

clause *clause_new() {
    clause *cls = (clause *) malloc(sizeof(clause));
    cls->literals = (literal **) malloc(sizeof(literal *));
    cls->size = 0;
    return cls;
}

clause *clause_add_literal(clause *cls, literal *lit) {
    cls->size++;
    cls->literals = (literal **) realloc(cls->literals, cls->size * sizeof(literal *));
    cls->literals[cls->size - 1] = lit;
    return cls;
}

clause *clause_remove_literal(clause *cls, literal *lit) {
    dimension i;
    for (i = 0; i < cls->size; i++) {
        if (literal_compare_literals(cls->literals[i], lit) == 0) {
            for (; i < cls->size - 1; i++) {
                cls->literals[i] = cls->literals[i + 1];
            }
            free(cls->literals[cls->size - 1]);
            cls->size--;
            break;
        }
    }
    return cls;
}

bool clause_compare_clauses(clause *cls_l, clause *cls_r) {
    dimension i, j, count = 0;
    if (cls_l->size != cls_r->size) {
        return false;
    }
    for (i = 0; i < cls_l->size; i++) {
        for (j = 0; j < cls_l->size; j++) {
            if (literal_compare_literals(cls_l->literals[i], cls_r->literals[j]) == 0) {
                count++;
                break;
            }
        }
    }
    if (count == cls_l->size) {
        return true;
    }
    return false;
}

bool clause_contains_literal(clause *cls, literal *lit) {
    dimension i;
    for (i = 0; i < cls->size; i++) {
        if (literal_compare_literals(cls->literals[i], lit) == 0) {
            return true;
        }
    }
    return false;
}

void clause_print(clause *cls) {
    dimension i;
    for (i = 0; i < cls->size; i++) {
        literal_print(cls->literals[i]);
        printf(" ");
    }
    printf("\n");
}