// enter the arguments through command line
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
    
    int input[argc-1],i,temp;
    for(i=1; i<argc; i++)
        input[i-1] = atoi(argv[i]);
    
    //insertion sort
    for(i=1;i<argc-1;i++){
        for(int j=0; j<=i; j++){
            if(input[i] < input[j]){
                temp = input[j];
                input[j] = input[i];
                input[i] = temp;
            }
        }
    }
    cout << "The sorted list is:" << endl << "[";
    for(i=0; i<argc-1; i++)
          cout << input[i] << ", ";
    cout << "]";   
    return 0;
}
