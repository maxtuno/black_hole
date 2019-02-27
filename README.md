# "Black Hole" a (API) Template for a Optimal HPC SAT Solver

#### Features:

- Optimal Memory Usage, for the CNF formula exist +L and -L pointers to positive literals and negative literals, then the clauses point to this structures.

- Space Modification, the entire estructure of CNF formula can be changes modifying +L and -L coordinately, obtaining a new formula equivalent to the first.

- The solution assignment is converted from the Modified space to the original Formula automatically.

- Include a very simple SAT solver, https://github.com/maxtuno/quark_sat a QuarkSAT implementation, as a example.

### To build:

mkdir build

cd build 

cmake -DCMAKE_BUILD_TYPE=MinRelSize ..

make

### Try: (Homework)

- 10 Assign a literal
- Propagate 
- If conflict do CDCL else goto 20
- minimize the falsified clauses on F and get F' 
- F <- F' goto 10
- 20 The assignment and formula for this assignment 
- Obtain the solution for the original formula its trivial

More of my work:
https://twitter.com/maxtuno
