#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;


class Searching{
    public:
        void wordSearch(string A[], int n, string value);
        //void prefixSearch(string A[], int n, string value);
};


int main(){
    
    Searching search;
    ifstream infile;
    int dicSize = 141;
    string A[dicSize];
    string toSearch;
    int position;
    int comparison;
    
    // read from the dictionary file and store the entries into an array 
    infile.open("dictionary.txt");
    for (int i = 0; i < dicSize; i++){
        infile >> A[i];
    };
    infile.close();
    
    // continuously take a user-provided input  
    while (true){
        cout << "Which word are you looking for? Type 'exit' to stop : " << endl;
        cin >> toSearch; 
        
        if (toSearch == "exit") break;
        
        search.wordSearch(A, dicSize, toSearch);
    }
    return 0;    
}


// binary search with while loop
void Searching::wordSearch(string A[], int n, string value){

    int first = 0;
    int last = n-1;
    int middle;
    int position;
    bool found = false;
    int comparison = 0;
    
    while (!found && first <= last) {
        middle = (first + last)/2;
        if (A[middle] == value){
            found = true;
            position = middle;
        } else if (A[middle] > value) last = middle - 1;
        else first = middle + 1;
        comparison += 1;
    }
    
    if(found == true){
        cout << "word found" << endl;
        cout << comparison << " word comparison carried out" << endl;
        } else cout<< "word not found" << endl;
}

/*
void prefixSearch(string A[], int n, string value){
    value.pop_back();
    int first = 0;
    int last = n-1;
    int middle;
    int position;
    bool found = false;
    int comparison = 0;
    
    while (!found && first <= last) {
        middle = (first + last)/2;
        if (A[middle] == value){
            found = true;
            position = middle;
        } else if (A[middle] > value) last = middle - 1;
        else first = middle + 1;
        comparison += 1;
    }
}

*/

/* binary search with recursion
string Searching::binarySearch(string A[], int first, int n, string value){
    int last = n - 1;
    if(first > last) return "word not found";
    else {
        middle = lower_bound((first + last)/2);
        if (A[middle] == value){
            return A[middle];
            else if(A[middle] <= value) return binarySearch(A, middle + 1, last, value);
            else return binarySearch(A, first, middle - 1, value);
        }
    }
*/

