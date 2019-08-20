#include <stdio.h>
#include "Equation.h"

int main(int argc, char **argv)
{
        
    vector <vector <double>> e_s 
    {
        {10, 15, 2, 4, 100},
        {5, 10, 3, 6, 75},
        {9, 10, 5, 8, 115},
        {12, 7, 3, 9, 186},
    };
    //e_s = read_system ();
    print_vector(e_s);
    
   
    
    e_s = create_row_echelon (e_s);
    //print_vector(e_s);
    e_s = create_reduced_row_echelon (e_s);
    print_vector(e_s);
    return 0;
}
