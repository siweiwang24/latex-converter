/*
Copyright 2020. Siwei Wang.

LaTeX math environment dollar sign to parentheses converter.
*/
#include <exception>
#include <fstream>
#include <iostream>

using std::cout;
using std::ifstream;
using std::ios_base;
using std::noskipws;
using std::ofstream;
using std::runtime_error;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  cout << "Converts $ <math> $ to \\( <math> \\) in LaTeX documents.\n";
  cout << "Usage: ./ltx input.tex output.tex\n";

  // Check that command line arguments match up.
  if (argc != 3) {
    throw runtime_error("Program requires 2 command line arguments.");
  }

  // Open input file stream.
  ifstream fin(argv[1]);
  if (!fin.is_open()) {
    throw runtime_error("Could not open input file.");
  }
  // Make sure to preserve all white space.
  fin >> noskipws;

  // Open output file stream.
  ofstream fout(argv[2]);

  cout << "Transforming " << argv[1] << " into " << argv[2] << "...\n";

  bool toggle = true;

  // x contains the character BEFORE y.
  for (char x = '0', y = '0'; fin >> y; x = y) {
    // Don't change if this is a LITERAL dollar sign.
    if (y == '$' && x != '\\') {
      // Output parenthesis depends on toggle value.
      fout << (toggle ? "\\(" : "\\)");
      toggle = !toggle;
    } else {
      fout << y;
    }
  }

  cout << "Finished!\n";
}
