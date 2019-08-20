#pragma once
#include <iostream>
#include <vector>


using namespace std;

vector <vector <double>> multiply_by_non_zero (vector <vector <double>> e_s, unsigned line, double n);
vector <vector <double>> read_system ();
void print_vector(vector <vector <double>> e_s);
vector <vector <double>> swap_lines (vector <vector <double>> e_s, unsigned line1, unsigned line2);
vector <vector <double>> add_lines (vector <vector <double>> e_s, unsigned line1, unsigned line2, double n=1.0);
vector <vector <double>> create_row_echelon (vector <vector <double>> e_s);
vector <vector <double>> create_reduced_row_echelon (vector <vector <double>> e_s);


