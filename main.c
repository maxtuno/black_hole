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

#include "global.h"
#include "algorithms/algorithm.h"
#include "model/formula.h"

int main(int argc, char *argv[]) {

    formula *frm = parse_from_file(argv[1]);
    assigment *asg = assigment_new(frm->length);

    if (run(frm, asg)) {
        printf("SAT\n");
        formula_print_model(frm, asg);
        printf("0\n");
    } else {
        printf("UNSAT\n");
    }

    return EXIT_SUCCESS;
}