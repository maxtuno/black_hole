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

#include "formula.h"

formula *formula_new() {
    formula *frm = (formula *) malloc(sizeof(formula));
    frm->clauses = (clause **) malloc(sizeof(clause *));
    frm->size = 0;
    return frm;
}

formula *formula_add_clause(formula *frm, clause *cls) {
    frm->size++;
    frm->clauses = (clause **) realloc(frm->clauses, frm->size * sizeof(clause *));
    frm->clauses[frm->size - 1] = cls;
    return frm;
}

formula *formula_remove_clause(formula *frm, clause *cls) {
    dimension i;
    for (i = 0; i < frm->size; i++) {
        if (clause_compare_clauses(frm->clauses[i], cls)) {
            for (; i < frm->size - 1; i++) {
                frm->clauses[i] = frm->clauses[i + 1];
            }
            free(frm->clauses[frm->size - 1]);
            frm->size--;
            break;
        }
    }
    return frm;
}

formula *formula_create_space(formula *frm, dimension length) {
    dimension i;

    frm->length = length;
    frm->positives = (literal **) malloc(frm->length * sizeof(literal *));
    frm->negatives = (literal **) malloc(frm->length * sizeof(literal *));

    for (i = 0; i < frm->length; i++) {
        frm->positives[i] = literal_new();
        frm->positives[i]->variable = +(i + 1);
        frm->negatives[i] = literal_new();
        frm->negatives[i]->variable = -(i + 1);
    }
    return frm;
}

formula *parse_from_file(string file_name) {
    dimension i, n, m;
    integer aux;
    char buffer[32];
    FILE *file = fopen(file_name, "r");
    if (strcmp(buffer, "c") == 0) {
        while (strcmp(buffer, "\n") != 0) {
            fscanf(file, "%s", buffer);
        }
    }
    while (strcmp(buffer, "p") != 0) {
        fscanf(file, "%s", buffer);
    }
    formula *frm = formula_new();
    fscanf(file, " cnf %i %i", &n, &m);
    formula_create_space(frm, n);
    for (i = 0; i < m; i++) {
        clause *cls = clause_new();
        do {
            fscanf(file, "%s", buffer);
            if (strcmp(buffer, "c") == 0) {
                continue;
            }
            aux = atoi(buffer);
            if (aux > 0) {
                clause_add_literal(cls, frm->positives[INDEX(aux)]);
            } else if (aux < 0) {
                clause_add_literal(cls, frm->negatives[INDEX(aux)]);
            }
        } while (strcmp(buffer, "0") != 0);
        formula_add_clause(frm, cls);
    }
    fclose(file);
    return frm;
}

formula *formula_change_polarity(formula *frm) {
    dimension i;
    for (i = 0; i < frm->length; i++) {
        frm->positives[i]->variable = -frm->positives[i]->variable;
        frm->negatives[i]->variable = -frm->negatives[i]->variable;
    }
    return frm;
}

formula *formula_change_polarity_variable(formula *frm, integer variable) {
    dimension i = (dimension) INDEX(variable);
    frm->positives[i]->variable = -frm->positives[i]->variable;
    frm->negatives[i]->variable = -frm->negatives[i]->variable;
    return frm;
}

formula *formula_swap_polarity_variables(formula *frm, integer var_l, integer var_r) {
    dimension i = (dimension) INDEX(var_l), j = (dimension) INDEX(var_r);
    formula_change_polarity_variable(frm, frm->positives[i]->variable);
    formula_change_polarity_variable(frm, frm->positives[j]->variable);
    return frm;
}

void formula_print(formula *frm) {
    dimension i;
    for (i = 0; i < frm->size; i++) {
        clause_print(frm->clauses[i]);
    }
}

void formula_print_model(formula *frm, assigment *asg) {
    dimension i;
    for (i = 0; i < frm->length; i++) {
        if (frm->negatives[i]->variable > 0) {
            literal_print(literal_negate(asg->literals[i]));
        } else {
            literal_print(asg->literals[i]);
        }
        printf(" ");
    }
}