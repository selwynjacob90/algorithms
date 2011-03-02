//please enter arguments(string) through command line
#include <iostream>

using namespace std;

void permutation(string first, string second){
    if(second.length() <= 1)
        cout << (first+second) << endl;
    else {
        for(int i=0; i<second.length(); i++){
            string temp = second.substr(0,i) + second.substr(i+1);
            permutation((first+second.at(i)),temp);
        }    
    }    
}

int main(int argc, char* argv[]){
    string word = argv[1];
    cout << "Permutations of " << word << " are: " << endl;
    permutation("",word);        
    return 0;
}
