// The owner of this program is Shravan

#include <iostream>
#include<cstdlib>	

using namespace std;
const int S=20;

void strassen (int A[][S], int B[][S], int C[][S],int mS );
void matrix_multiply (int as, int A[][S], int B[][S],int C[][S]);
int add (int n1, int n2);
int multiply (int n1, int n2);
void addM(int A[][S], int B[][S],int R[][S], int mS);
void subM (int A[][S], int B[][S],int R[][S], int mS);
void readA(int A[][S],int n);
void readB(int B[][S],int n);
void printC(int C[][S],int n);

int main ()
{                     
                  
	int a[S][S], b[S][S], c[S][S];
	int i, j, n;
		  cout<<"\nenter the sizeof the matrix: ";
		  cin>>n;
	                     readA(a,n);
		  readB(b,n);
		  cout<<"\nMatrixA:\n";
		  printC(a,n);
		   cout<<"\nMatrixB:\n";
		  printC(b,n);
	strassen (a, b, c, n );
		cout<<"\nResultantnt matrix C:\n";
		printC(c,n);

		   return 0;
}

void strassen (int A[][S], int B[][S], int C[][S],int mS)
{
	int p;
	int a11[S][S], a12[S][S], a21[S][S], a22[S][S];
	int b11[S][S], b12[S][S], b21[S][S], b22[S][S];
	int c11[S][S], c12[S][S], c21[S][S], c22[S][S];
	int m1[S][S];
	int m2[S][S];
	int m3[S][S];
	int m4[S][S];
	int m5[S][S];
	int m6[S][S];
	int m7[S][S];
	int aR1[S][S], aR2[S][S], sR[S][S];
	if (mS <= 2)
	{
		matrix_multiply (mS, A, B, C);
	}
	else
	{
		p = mS/2;
		for (int i = 0; i < p; i++)
			for (int j = 0; j < p; j++)
			     {
			                 a11[i][j] = A[i][j];
				a12[i][j] = A[i][j + p];
				a21[i][j] = A[i + p][j];
				a22[i][j] = A[i + p][j + p];
				b11[i][j] = B[i][j];
				b12[i][j] = B[i][j + p];
				b21[i][j] = B[i + p][j];
				b22[i][j] = B[i + p][j + p];
			}

		//   m1[]
		addM (a11, a22, aR1, p);
		addM (b11, b22, aR2, p);
		strassen (aR1, aR2, m1, p);
		//   m2[]
		addM (a21, a22, aR1, p);
		strassen (aR1, b11, m2, p);
		//   m3[]
		subM (b12, b22, sR, p);
		strassen (a11, sR, m3, p);
		//  m4[]
		subM (b21, b11, sR, p);
		strassen (a22, sR, m4, p);
		//  m5[]
		addM (a11, a12, aR1, p);
		strassen (aR1, b22, m5, p);
		//  m6[]
		subM (a21, a11, sR, p);
		addM (b11, b12, aR1, p);
		strassen (sR, aR1, m6, p);
		//   m7[]
		subM (a12, a22, sR, p);
		addM (b21, b22, aR1, p);
		strassen (sR, aR1, m7, p);
		//  c11
		addM (m1, m4, aR1, p);
		addM (aR1, m7, aR2, p);
		subM (aR2, m5, c11, p);
		//   c12
		addM (m3, m5, c12, p);
		//   c21
		addM (m2, m4, c21, p);
		//   c22
		addM (m1, m3, aR1, p);
		addM(aR1, m6, aR2, p);
		subM (aR2, m2, c22, p);
		for (int k = 0; k < p; k++)
			for (int j = 0; j < p; j++)
			{
				C[k][j] = c11[k][j];
				C[k][j + p] = c12[k][j];
				C[k + p][j] = c21[k][j];
				C[k + p][j + p] = c22[k][j];
			}
	}
}


void matrix_multiply (int as, int arrA[][S], int arrB[][S],int pA[][S])
{
	int i,j,k,r;
	for (i = 0; i < as; i++)
		for (j = 0; j < as; j++)
		{
			pA[i][j] = 0;
			for (k = 0; k < as; k++)
			{
				r = multiply (arrA[i][k],arrB[k][j]);
				pA[i][j] = add (pA[i][j], r);
			}
		}
}


int add (int n1, int n2)
{
	int r = n1 + n2;
	return r;
}


int multiply (int n1, int n2)
{
	int r = n1 * n2;
	return r;
}


void addM (int A[][S], int B[][S],int R[][S], int m)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			R[i][j] = add (A[i][j], B[i][j]);
}


void subM (int A[][S], int B[][S],int R[][S], int m)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			R[i][j] = add (A[i][j], (0 - B[i][j]));
}
void readA(int A[][S],int n)
{
    for (int i = 0; i < n; i++)
       for (int j = 0; j < n; j++)
	A[i][j]=rand( ) % 5 ;
}
void readB(int B[][S],int n)
{
    for (int i = 0; i < n; i++)
       for (int j = 0; j < n; j++)
	B[i][j]=rand( ) % 8 ;
}		
void printC(int C[][S],int n)
{
          for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		       cout<<C[i][j]<<"\t";
		       cout<<endl;
	 }
}
