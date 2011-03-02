//enter the arguments through command line
#include <iostream>
#include <cstdlib> 

using namespace std;

void towers(int count, char source, char temp, char dest){
    if(count > 0) {
        towers(count-1,source,dest,temp);
        cout << "move disk " << count << " " << source << " --> " << dest << endl;;
        towers(count-1,temp,source,dest);
    }    
}//towers functions

int main(int argc, char* argv[]){
    int count = atoi(argv[1]);
    char source = 'S';
    char temp = 'T';
    char dest = 'D';
    cout << "The sequence is: " << endl;
    towers(count,source,temp,dest);
    return 0;
}
