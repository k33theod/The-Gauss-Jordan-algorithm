#include "Equation.h"

vector <vector <double>> read_system ()
{
    
    /******************************************
     * GET THE EQUATION FROM CIN
     * 
     * ***************************************/
    int v_size =0;
    cout << "What is the size of equation system : ";
    cin >> v_size; 
    vector <vector <double>> e_s (v_size);
    vector <double> line(v_size+1);
    for (int i=0; i<v_size; i++ )
    {
        cout << "Give line "<< i << " with spaces between : " ;
        for (int j=0; j<v_size+1; j++)
        {
            cin >> line[j]; 
        }
        e_s[i]=line;
    }     
    return e_s;
}

void print_vector(vector <vector <double>> e_s)
{   
    /******************************************
     * PRINT ON COUT A 2 DIMENSIONAL VECTOR
     * 
     * ***************************************/
    cout<<endl<<"system"<<endl;
    for (unsigned i=0; i<e_s.size(); i++ )
    {
        for (unsigned j=0; j<e_s.size()+1; j++)
        {
            printf("%.2f\t",e_s[i][j]) ; 
        }
        cout<<endl;
    }
    cout<<"end of system"<<endl<<endl;
}






vector <vector <double>> multiply_by_non_zero (vector <vector <double>> e_s, unsigned line, double n)
{
    
    /******************************************
     * HELP FUNCTION TO IMPLEMENT THE
     * GAUSS ALGORITHM
     * ***************************************/
    if (n == 0)
    {
        cout <<"I cant multiply with 0. Multiply row by_non_zero failed";
        return e_s;
    }
        
    if (line <0 || line>e_s.size()-1)
    {
        cout <<"Line number out of limits. Multiply row by_non_zero failed"<<endl;
        return e_s;
    }
    for (unsigned i = 0; i<e_s[line].size(); i++)
    {
        e_s[line].at(i)*=n;
    }
    return e_s;
}

vector <vector <double>> swap_lines (vector <vector <double>> e_s, unsigned line1, unsigned line2)
{
    /******************************************
     * HELP FUNCTION TO IMPLEMENT THE
     * GAUSS ALGORITHM
     * ***************************************/
    if (line1 <0 || line1 <0 || line1 > e_s.size()-1 || line2 > e_s.size()-1)
    {
        cout <<"Line number out of limits. Change 2 rows operation failes"<<endl;
        return e_s;
    }
    
    vector <double> temp (e_s[0].size());
    temp = e_s[line1];
    e_s[line1]=e_s[line2];
    e_s[line2]=temp;
    return e_s;
}

vector <vector <double>> add_lines (vector <vector <double>> e_s, unsigned line1, unsigned line2, double n)
{
    /******************************************
     * HELP FUNCTION TO IMPLEMENT THE
     * GAUSS ALGORITHM
     * ***************************************/
    if (line1 <0 || line1 <0 || line1 > e_s.size()-1 || line2 > e_s.size()-1)
    {
        cout <<"Line "<<line1 <<" or line "<<line2<< " out if row limits. Add 2 lines operation failed "<<endl;
        return e_s;
    }
    for (unsigned i = 0; i<e_s[line1].size(); i++)
    {
        e_s[line2].at(i)+=n*e_s[line1].at(i);
    }
    return e_s;
}

vector <vector <double>> create_row_echelon (vector <vector <double>> e_s)
{
    /*****************************************
    * CREATE ROW ECHELON ALGORITHM 
    * IMPLEMENTATION
    ****************************************/
    unsigned swap_line {0};
    int j {0};
    for (unsigned i=0; i<e_s.size(); i++)
    {
        swap_line=i+1;
        while (e_s[i][j]==0 && swap_line < e_s.size())
        {
            e_s = swap_lines(e_s,0,swap_line);
            swap_line++;
        }
        
        if (e_s[i][j]!=0)
        {
            e_s = multiply_by_non_zero (e_s, i, 1/(e_s[i][j]));
            for(unsigned k =i+1; k < e_s.size(); k++ )
            {
                e_s = add_lines (e_s, i, k, -e_s[k][j]); 
            }
        }
        j++;
    }    
    return e_s;
}

vector <vector <double>> create_reduced_row_echelon (vector <vector <double>> e_s)//e_s vector should be ib row echelon
{
    /******************************************
     * GAUSS-JORDAN ELIMINATION IMPLEMENTATION ALGORITHM
     * ALGORITHM TO CREATE REDUCED ROW ECHELON
     * ***************************************/
    int up_line {0};
    unsigned j {e_s.size()-1};
    for (unsigned i=e_s.size()-1; i>0; i--)
    {
        up_line=i-1;
        while (up_line >=0)
        {
            e_s = add_lines (e_s, i, up_line, -e_s[up_line][j]); 
            up_line--;
        }        
        j--;
    }    
    return e_s;
}
