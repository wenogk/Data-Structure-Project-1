#include<iostream>
#include<string>
#include <fstream>
//#include "search.h"

using namespace std;


//START STUFF THAT HAS TO BE IN SEARCH.CPP
class dSearch {
	public:
		void binaryWordSearch(string a[],int numWords,string query);
		void binaryWordStarSearch(string a[],int numWords,string query);
		void binaryWordQSearch(string a[],int numWords,int qMarkPos, string query);

};

void dSearch::binaryWordSearch(string A[], int n, string value) {
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
        cout << comparison << " word comparisons carried out" << endl;
        } else cout<< "word not found" << endl;

}

void dSearch::binaryWordStarSearch(string A[], int n, string value) {
	int first = 0;
	//int starPos=value.size()-1;
	string newValue=value.substr(0,value.length()-1);
	cout<< "Looking for " << newValue <<endl;
    int last = n-1;
    int middle;
    int position;
    bool found = false;
    int comparison = 0;
    while (!found && first <= last) {
        middle = (first + last)/2;
        if (A[middle].find(newValue) == 0){ //toSearch.find('*') != std::string::npos
            found = true;
            position = middle;
        } else if (A[middle] > newValue) last = middle - 1;
        else first = middle + 1;
        comparison += 1;
    }
    int currentWord=position;
    int startIndex=position+1;
    while(A[startIndex-1].find(newValue) == 0) {
    	startIndex=startIndex-1;
    	comparison += 1;
    }
    int endIndex=position;
        while(A[endIndex+1].find(newValue) == 0) {
    	endIndex=endIndex+1;
    	comparison += 1;
    }

    if(!found) {
    	cout<< "word not found" << endl;
    } else {
    	cout << "word found" << endl;
        cout << comparison << " word comparisons carried out" << endl;
        //cout << "end: " << endIndex << "... start: " << startIndex << endl;
        if((endIndex-startIndex)>0) {
        for(int j=0;j<(endIndex+1-startIndex);j++) {
        	cout << A[startIndex+j] << endl;
        }
    } else {
    	cout << A[position] << endl;
    }
    }
}

void dSearch::binaryWordQSearch(string A[], int n, int qMarkPos, string value) {
	string frontStringPart = value.substr(0,qMarkPos);
	string backStringPart = value.substr(qMarkPos+1,value.size()-1);
	int first = 0;
	//int starPos=value.size()-1;
	//string newValue=value.substr(0,value.length()-1);
	//cout<< "Looking for " << newValue <<endl;
    int last = n-1;
    int middle;
    int position;
    bool found = false;
    int comparison = 0;
    while (!found && first <= last) {
        middle = (first + last)/2;
        if (A[middle].find(frontStringPart) == 0){ //toSearch.find('*') != std::string::npos
            found = true;
            position = middle;
        } else if (A[middle] > frontStringPart) last = middle - 1;
        else first = middle + 1;
        comparison += 1;
    }
    //cout << "found: " <<found << endl;
    int currentWord=position;
    int startIndex=position+1;
    while(A[startIndex-1].find(frontStringPart) == 0) {
    	startIndex=startIndex-1;
    }
    int endIndex=position;
        while(A[endIndex+1].find(frontStringPart) == 0) {
    	endIndex=endIndex+1;
    }
 	int first2= startIndex;
 	int last2= endIndex;
 	
 	bool foundFinal = false;
 	int finalPosition;
 	string curBackStringPart;
 	for(int j=0;j<(last2+1-first2);j++) {
 		comparison+=1;
 		if(A[first2+j].size()==value.size()) {
 		//cout << "CURRENT WORD IN LOOP---> " << A[first2+j] << endl;
 		curBackStringPart = A[first2+j].substr(qMarkPos+1,A[first2+j].size()-1);
 		//cout << "curBackStringPart: " << curBackStringPart << endl;
 		if(curBackStringPart==backStringPart) {
 			foundFinal=true;
 			finalPosition=first2+j;
 			cout << A[first2+j] << endl;
 		}
 	}
 }
 	//cout << "first2: " <<first2 << " last2: " << last2 << "backStringPart: " << backStringPart << "curBackStringPart: " << curBackStringPart << " Looking in: " << A[position] << endl;
    if(!foundFinal) {
    	cout<< "word not found" << endl;
    } else {
    	cout << "word found" << endl;
        cout << comparison << " word comparisons carried out" << endl;
        //cout << "end: " << endIndex << "... start: " << startIndex << endl;
     	/*for(int j=0;j<(last2+1-first2);j++) {
    	cout << A[first2+j] << endl;
    }*/
    
    }
}
//END STUFF TO GO TO SEARCH.CPP


int main(int count, char * args[])
{
	string filename="";
	int wordcount=-1;


	for(int i=1; i<count; i++)
	{
		if((string(args[i]) == "-d") && i+1 < count)
			filename=args[i+1];
		else if ((string(args[i])=="-l") && i+1 < count)
			wordcount=atoi(args[i+1]);
	}

	if(filename=="" || wordcount == -1)
	{
		cout<<"Usage ./myspeller -d <dictionaryfilename> -l <numberOfWordsSearch>"<<endl;
		return -1;
	}

    dSearch search;
    //search.binaryWordSearch();

	cout<<"filename = "<<filename<<endl;
	cout<<"WordCount = "<<wordcount<<endl;

    ifstream infile;
    int dicSize =wordcount;
    string A[dicSize];
    string toSearch;
    int position;
    int comparison;
    
    // read from the dictionary file and store the entries into an array 
    infile.open(filename);
    for (int i = 0; i < dicSize; i++){
        infile >> A[i];
    };
    infile.close();
    
    // continuously take a user-provided input  
    while (true){
        cout << "Which word are you looking for? Type 'exit' to stop : " << endl;
        cin >> toSearch; 
        int qMarkPosition = toSearch.find("?");

        if (toSearch == "exit") break;
        if (toSearch.find('*') != std::string::npos) {
        	search.binaryWordStarSearch(A, dicSize, toSearch);
        } else if(toSearch.find('?') != std::string::npos) {
        	search.binaryWordQSearch(A, dicSize,qMarkPosition, toSearch);
        }
        else{
        search.binaryWordSearch(A, dicSize, toSearch);
    }
    }

	return EXIT_SUCCESS;
	// ./a.out -d Dictionary141words.txt -l 141
}
