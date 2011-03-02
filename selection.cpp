//please enter arguments through command line
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
    int input[argc];
    for(int i=1; i<argc; i++){
        input[i-1]=atoi(argv[i]);
    }    
    
    for(int j=0; j<argc-1; j++){
       for(int k=j+1; k<argc-1; k++){
            if(input[j] > input[k]){
                int temp = input[j];
                input[j] = input[k];
                input[k] = temp;
            }    
       } 
    }

    cout << "The sorted list is: "<< endl << "[ ";
    for(int m=0; m<argc-1; m++)
        cout << input[m] <<", ";
    cout << "]";
    return 0;
}

