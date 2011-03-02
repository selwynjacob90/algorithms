#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int MAXSIZE = 100; 
int M[MAXSIZE][MAXSIZE];
int N;                  
int n;                  
int i;                  
int ii;                
int j;                  
int jj;
int k;                 
int esum;               
int sum;

int readfile()
{  
    cout << "Enter size of square (odd integer between 1 and " << MAXSIZE << "):";
    cin >>  N;
   
    if ( (N >= 1) && (N <=  MAXSIZE) )
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                M[i][j] = 0;
            }
        }  
    }
}

int median()
{       n = (N-1) / 2;      
        i = n;
        j = N - 1;
        M[i][j] = 1;       
        for (k = 2; k <= N*N; k++)
        {
            ii = (i + 1) % N;
            jj = (j + 1) % N;
            if (M[ii][jj] == 0)
            {
                i = ii;
                j = jj;
            }
            else
            {
                j = j -1;   
            }
            M[i][j] = k;
        }
       
}

int rowsums()
{
// check row sums
        for (i = 0; i < N; i++)
        {
            sum = 0;


            for (j = 0; j < N; j++)
            {
                sum = sum + M[i][j];
            }
            if (sum != esum)
            {
                cout << "sum row " << i << " = " << sum << endl;
            }
        }
}
int columnsums()
{  // check column sums
        for (j = 0; j < N; j++)
        {
            sum = 0;
            for (i = 0; i < N; i++)
            {
                sum = sum + M[i][j];
            }
            if (sum != esum)
            {
                cout << "sum column " << j << " = " << sum << endl;
            }
        }

}
int diagonals ()
{       sum = 0;
        for (i = 0; i < N; i++)
        {
            sum = sum + M[i][i];
        }
        if (sum != esum)
        {
            cout << "sum + diagonal = " << sum << endl;
        }
       
        sum = 0;
        for (i = 0; i < N; i++)
        {
            sum = sum + M[i][N - i - 1];
        }
        if (sum != esum)
        {
            cout << "sum - diagonal = " << sum << endl;
        }
}
int missingnumb ()
{
 for (i = N - 1; i >= 0; i--)
        {
            for (j = 0; j < N; j++)
            {
                cout << setw(4) << M[i][j];
            }
            cout << endl;
        }
       
        esum = ((1 + N*N) / 2) * N;
        cout << "Expected sum = " << esum << endl;
}


int main()
{
    readfile();  
    median();
    columnsums();
    diagonals();
    missingnumb();
       
   
    return 0;
}
