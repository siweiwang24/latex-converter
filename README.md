# LaTeX Math

Converts dollar signs $...$ to parentheses \\(...\\) to delimit math environments in LaTeX documents.

To use, simply run the Makefile to produce the ltx binary. Then execute:

./ltx input.tex output.tex

to reformat input.tex into the file output.tex

The ltx program does not modify input.tex and will throw exceptions on command line errors.
