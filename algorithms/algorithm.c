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

#include "algorithm.h"

bool exist_conflict(formula *frm, assigment *asg) {
    dimension i, j, count;
    for (i = 0; i < frm->size; i++) {
        count = 0;
        for (j = 0; j < frm->clauses[i]->size; j++) {
            if (frm->clauses[i]->literals[j]->variable == -asg->literals[INDEX(frm->clauses[i]->literals[j]->variable)]->variable) {
                count++;
            } else {
                break;
            }
            if (count == frm->clauses[i]->size) {
                return true;
            }
        }
    }
    return false;
}

void decide(assigment *asg) {
    dimension i, j = 0;
    for (i = 0; i < asg->size; i++) {
        j = ((dimension) random() + (j + i)) % asg->size;
        if (asg->literals[j]->variable == 0) {
            asg->literals[j]->variable = -(j + 1);
            asg->length++;
            return;
        }
    }
    for (i = 0; i < asg->size; i++) {
        if (asg->literals[i]->variable == 0) {
            asg->literals[i]->variable = -(i + 1);
            asg->length++;
            return;
        }
    }
}

bool backtrack(assigment *asg) {
    long i;
    for (i = 0; i < asg->size; i++) {
        if (asg->literals[i]->variable != 0) {
            if (asg->back_sapce[i]->variable == asg->literals[i]->variable) {
                asg->literals[i]->variable = 0;
                asg->back_sapce[i]->variable = 0;
                asg->length--;
            } else {
                asg->literals[i]->variable = -asg->literals[i]->variable;
                asg->back_sapce[i]->variable = asg->literals[i]->variable;
                return true;
            }
        }
    }
    return false;
}

bool run(formula *frm, assigment *asg) {
    dimension top = 0;
    for (;;) {
        if (exist_conflict(frm, asg)) {
            if (!backtrack(asg)) {
                return false;
            }
        } else {
            if (top < asg->length) {
                top = asg->length;
                printf("c %i\n", asg->size - asg->length);
            }
            if (asg->length == asg->size) {
                return true;
            } else {
                decide(asg);
            }
        }
    }
}