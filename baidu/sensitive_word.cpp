#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

class Trie{
public:
    bool isWord;
    vector<Trie*> child;
    Trie(){
        isWord = false;
        child = vector<Trie*>(26, nullptr);
    }
};

char getLower(char c){
    if(c >= 'A' && c <= 'Z') return c -'A' + 'a';
    else return c;
}

void add(Trie* root, const string& w){
    for(char c: w){
        int idx = getLower(c) - 'a';
        if(! root->child[idx]) root->child[idx] = new Trie();
        root = root->child[idx];
    }
    root->isWord = true;
}

bool search(Trie* root, const string& w){
    for(auto c : w){
        if(root->isWord) return true;
        int idx = getLower(c) - 'a';
        if(root->child[idx]) root= root->child[idx];
        else return false;
    }
    return root->isWord;
}

bool notAlpha(char c){
    if((c>='a' && c<='z') || (c>='A' && c<='Z')) return false;
    else return true;
}


int main(){
	int num;
    cin >> num;
    Trie* root = new Trie();
    string word;
    int maxLen=0, minLen = -1;
    for(int i = 0; i < num; i++) {
        cin >> word;
        add(root, word);
        maxLen = max(maxLen, (int)word.size());
        minLen = min(minLen, (int)word.size());
    }
    string line;
    getchar();
    getline(cin, line);
    int n = line.size();
    int i=0;
    while(i < n){
        while(i < n && notAlpha(line[i])){
            printf("%c", line[i]);
            i++;
        }
        int s = i;
        while(i < n && !notAlpha(line[i])) i++;
        word = line.substr(s, i-s);
        bool sensi = false;
        for(int j = 0; j < min(word.size()-minLen+1, word.size()); j++){
            if(search(root, word.substr(j))){
                sensi = true;
                break;
            }
        } 
        if(sensi) cout << string(word.size(), '*') ;
        else cout << word;
    } 
    cout << endl;
  	return 0;
}