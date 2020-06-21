#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getNext(const string& s){
    int len = s.size();
    vector<int> next(len);
    next[0] = -1;
    int k = -1, j=0;
    while(j < len-1){
        if(k==-1 || s[j] == s[k]){
            j++;
            k++;
            if(s[j] != s[k]){
                next[j] = k;
            }else{
                next[j] = next[k];
            }
        }else{
            k = next[k];
        }
    }
    return next;
}


int search(const string& s, const string& p){
    int i = 0, j = 0;
    int sLen=s.size(), pLen = p.size();
    vector<int> next = getNext(p);
    while(i < sLen && j < pLen){
        if(j == -1 || s[i] == p[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j == pLen ) return i - j;
    else return -1;
}

int main(){
    string s = "abcbababc";
    string p = "abab";
    int res = search(s, p);
    cout << res << endl;
    return 0;
}