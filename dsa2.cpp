
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
  
const int ALPHABET_SIZE = 26; 
  
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
 
    bool isEndOfWord; 
}; 

struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
    string lastOne;
    for (int i = 0; i < key.length(); i++) 
    { 
        if(((key[i] - 'a')<=26)&&((key[i] - 'a')>=0)) {
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index];
        lastOne=key[i]; 
        }
    } 
  
    // mark last node as leaf 
    //cout<< lastOne<< endl;
    pCrawl->isEndOfWord = true; 
} 

bool search(struct TrieNode *root, string key, int &comparisons) 
{ 
    struct TrieNode *pCrawl = root; 
    
    for (int i = 0; i < key.length(); i++) 
    { 
        comparisons=i;
        int index = key[i] - 'a'; 

        if (!pCrawl->children[index]) {
            return false; 
        }
  
        pCrawl = pCrawl->children[index]; 
        //for (int j=0;j < pCrawl->children.length();j++) {
        //cout << pCrawl->children[j] << endl;
   // }
    } 
  //cout << "Length: " << pCrawl->children.length() << endl;
    return (pCrawl != NULL && pCrawl->isEndOfWord); 

} 

  
int main() 
{ 
ifstream infile("ds/d141.txt");
string line;
int numWords=141;
string keys[numWords];
  int x=0;
  while (getline(infile, line)) {
    keys[x]=line;
   // cout << keys[x] << endl;
    x++;
  }
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    struct TrieNode *root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
   while(1){
    string query;
    cin >> query;
    //ecout << rom
    int numComparisons;
    search(root, query,numComparisons)? cout << "Found result! " << numComparisons << " comparisons carried out" << endl: 
                         cout << "No results found! " << numComparisons << " comparisons carried out" << endl;
    //cout << "Found " << search.numMatched(words,query) << " results for " << query << " \n";
  }
    return 0; 
} 