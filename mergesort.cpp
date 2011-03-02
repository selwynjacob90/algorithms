//enter the arguments through command line
#include <iostream>
#include <cstdlib>

using namespace std;

void merge(int input[],int low,int mid,int high){
    
    int *temp = new int[high-low+2];
    int i = low, j = mid+1, k = 0;

    while((i <= mid) && (j <= high)){
        if(input[i] < input[j])
            temp[k++] = input[i++];
        else 
            temp[k++] = input[j++];
    } 

    if(i <= mid){
        for(j=i; j<=mid; j++)
            temp[k++] = input[j];
    }
    else {
        for(i=j; i<=high; i++)
            temp[k++] = input[i];
    }
    
    k=0;
     for(i=low; i<=high; i++)
         input[i] = temp[k++];    
     delete [] temp;
}//merge function

void mergesort(int input[], int low, int high){
    
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergesort(input,low,mid);
        mergesort(input,mid+1,high);
        merge(input,low,mid,high);
    }
}//mergesort function


int main(int argc, char* argv[]){
    
    int input[argc-1],i;
    for(i=1; i<argc; i++){
        input[i-1] = atoi(argv[i]);
     }
    mergesort(input,0,argc-2);
    cout << "The sorted list is:" << endl << "[";
    for(i=0; i<argc-1; i++)
        cout << input[i] << ", ";
    cout << "]";
    return 0;
}
