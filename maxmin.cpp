// please enter arguments through command line
#include <iostream>
#include <cstdlib>

using namespace std;
int input[20], max, min;

void maxmin(int i, int j) {
        int max1, min1, mid;
        
        if(i == j) {
            ::max = ::min = ::input[i];
        }
        else {
            if(i == j-1){
                if(input[i] < input[j]){
                   ::max = input[j];
                   ::min = input[i];
                }    
                else {
                   ::max = input[i];
                   ::min = input[j];
                }
            }
            else {
                mid = (i+j)/2;    
                maxmin(i,mid);
                max1 = ::max; 
                min1 = ::min;
                maxmin(mid+1,j);
                if(::max < max1)
                    ::max = max1;
                if(::min > min1)
                    ::min = min1;
            }
        }
    }


int main(int argc, char* argv[]){
//    int input[argc-1], max, min;
   
    for(int i=1; i<argc; i++)
        ::input[i-1] = atoi(argv[i]);

    
    ::max = ::input[0];
    ::min = ::input[0];
    maxmin(0,argc-2);
    cout << "The maximum valued number is " << ::max << endl;
    cout << "The minimum valued number is " << ::min << endl;
    
    return 0;
}

