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

#include "assigment.h"

assigment *assigment_new(dimension size) {
    dimension i;
    assigment *asg = (assigment *) malloc(sizeof(assigment));
    asg->literals = (literal **) malloc(size * sizeof(literal *));
    asg->back_sapce = (literal **) malloc(size * sizeof(literal *));
    for (i = 0; i < size; i++) {
        asg->literals[i] = (literal *) malloc(sizeof(literal));
        asg->literals[i]->variable = 0;
        asg->back_sapce[i] = (literal *) malloc(sizeof(literal));
        asg->back_sapce[i]->variable = 0;
    }
    asg->size = size;
    asg->length = 0;
    return asg;
}

void assigment_print(assigment *asg) {
    dimension i;
    for (i = 0; i < asg->size; i++) {
        literal_print(asg->literals[i]);
        printf(" ");
    }
}