#include <iostream>
#include <cstdio>

using namespace std;
int a[12][12],b[12][12],c[12][12];

void multimatrices(int n,int p,int q,int r,int s)
{
    if(n%2!=0)
    { printf("\nNot a square matrix");}
    if(n==2)
    {
        c[p][s]+=(a[p][q]*b[r][s])+(a[p][q+1]*b[r+1][s]);/*calculate a11*/
        c[p][s+1]+=(a[p][q]*b[r][s+1])+(a[p][q+1]*b[r+1][s+1]);/*calculate a12*/
        c[p+1][s]+=(a[p+1][q]*b[r][s])+(a[p+1][q+1]*b[r+1][s]);/*calc a21*/
        c[p+1][s+1]+=(a[p+1][q]*b[r][s+1])+(a[p+1][q+1]*b[r+1][s+1]);/*calc a22*/
    }   
    else
    {
        multimatrices(n/2,p,q,r,s);
        multimatrices(n/2,p,q+n/2,r+n/2,s);/*calc c11*/
        multimatrices(n/2,p,q,r,s+n/2);
        multimatrices(n/2,p,q+n/2,r+n/2,s+n/2);/*calc c12*/
        multimatrices(n/2,p+n/2,q,r,s);
        multimatrices(n/2,p+n/2,q+n/2,r+n/2,s);/*calc c21*/
        multimatrices(n/2,p+n/2,q,r,s+n/2);
        multimatrices(n/2,p+n/2,q+n/2,r+n/2,s+n/2);/*calc c22*/
    }   
}

int main()
{
    int p,q,r,s,n;
    cout << "\norder must be equal to multiples of 2: ";
    cout << "\nenter order of matrix A n: ";
    cin >> n;
    cout << "\nenter elements of a: ";
    for(p=0;p<n;p++)
        for(q=0;q<n;q++)
            cin >> a[p][q];
    cout << "\nenter order of matrix B: ";
    cin >> n;
    cout << "\nenter elements of B: ";
    for(r=0;r<n;r++)
        for(s=0;s<n;s++)
            cin >> b[r][s];
    cout << "\nMatrix A is:";
    for(p=0;p<n;p++)
    {
        printf("\n");
        for(s=0;s<n;s++)
        {
             cout<< "\t" << a[p][s];
             
        }
    }   
    cout << "\nMatrix B is:";
    for(p=0;p<n;p++)
    {
        cout << endl;
        for(s=0;s<n;s++)
        {
            cout << "\t" << b[p][s];
        }   
    }
    for(p=0;p<n;p++)
        for(s=0;s<n;s++)
            c[p][s]=0;
    multimatrices(n,0,0,0,0);
    cout << "\nMultiplication of a[][]*b[][] is:";
    for(p=0;p<n;p++)
    {
        cout << endl;
        for(s=0;s<n;s++)
        {
            cout << "\t" << c[p][s];
        }
    }
    cout << endl;
return 0;
}

