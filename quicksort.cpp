//enter arguments through command line
#include <iostream>
#include <cstdlib>
using namespace std;

void quicksort(int input[], int left, int right) {
    int i = left, j = right;
    int x = input[(left+right)/2];

    do {
        while((input[i] < x) && (i < right))
            i++;
        while((x < input[j]) && (j > left))
            j--;

        if(i <= j) {
            int y = input[i];
            input[i] = input[j];
            input[j] = y;
            i++ ; j--;
        }
    } while(i <= j);

    if(left < j) {
        quicksort(input, left, j);
    }
    if(i < right){
        quicksort(input, i, right);
    }
}

void quick(int input[], int count) {
    quicksort(input, 0, count-1);
    cout << "sorted list is: " << endl << "["; 
    for(int i=0; i<count; i++)
        cout <<input[i] <<", ";
    cout << "]";
}

int main(int argc, char* argv[]){
    int input[argc-1];
    for(int i=1; i<argc; i++)
        input[i-1] = atoi(argv[i]);
    quick(input, argc-1);
}
