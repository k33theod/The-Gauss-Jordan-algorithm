# The-Gauss-Jordan-algorithm
c++ implementation
The Gauss-Jordan algorithm
The input of the algorithm is an m*m+1 matrix, which is 
typically an augmented matrix of a linear system.

1. If aij= 0 swap the i-th row with some other row below to guarantee that aij != 0.
The non-zero entry in the (i, j)-position is called a pivot. If all entries in the 
column are zero, increase j by 1.

2. Divide the i-th row by aij to make the pivot entry = 1.

3. Eliminate all other entries in the j-th column by subtracting suitable multiples 
of the i-th row from the other rows.

4. Increase i by 1 and j by 1 to choose the new pivot element. Return to Step 1.

The algorithm stops after we process the last row or the last column of the matrix.
The output of the Gauss-Jordan algorithm is the matrix inreduced row-echelon form.

Reduced row-echelon form A matrix is in reduced row-echelon form (RREF) if it satisfies 
all of the following conditions.

1. If a row has nonzero entries, then the first non-zero entry is 1 called the leading 1 
in this row.

2. If a column contains a leading one then all other entries in that column are zero.

3. If a row contains a leading one the each row above contains a leading one further to
the left.

The last point implies that if a matrix in rref has any zero rows they must appear as 
the last rows of the matrix.

  
