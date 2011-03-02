//please enter the arguments(string) through command line
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Combinations{
  string comb[200];
  string input;
  int counter;

  public:
    Combinations(string line){
        counter = -1;
        input = line;
        generate(input);
        cout << "Generated "<<counter+1<<" subsets " << endl;
        for(int i =0; i < counter+1; i++){
           cout << comb[i] << endl;        
        }//for
     }//constructor

    int inComb(string word){
        for(int i=0; i<counter+1; i++){
            if(word == comb[i]){
                return 1;
            }
        }
    }
    void generate(string word) {
        if(inComb(word) != 1){
            comb[++counter] = word;
        }
        if(word.length() == 1) {
                return;
        } // if
       // comb[++counter] = word;
        for(int i = 0; i < word.length(); i++) {
            generate(word.substr(0,i)+word.substr(i+1));
        }//for
    }//generate
    
};//class

int main(int argc, char* argv[]){
  Combinations obj(argv[1]);
  return 0;
  }
