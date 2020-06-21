#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Trie{
    char c;
    int num;
    int cNum;
    bool isLeaf;
    Trie* next[26];
    
    Trie(){
        num = 0;
        cNum = 0;
        isLeaf = false;
    }
    void insert(string word){
        TreeNode* cur = this;
        for(char c : word){
            if(!cur->next[c-'A']) cur->next[c-'A'] = new Trie();
            cur = cur->next[c-'A'];
            cur->cNum++;
        }
        cur->isLeaf = true;
        cur->num++;
    }
}

int score(vector<string>& p, int k){
    int n = p.size();
    Trie* root = new Trie();
    for(int i = 0; i < n; i++){
        root->insert(p[i]);
    }
    
}


int main(){
    int T, N, K;
    cin >> T;
    for(int ca=1; ca<= T; ca++){
        cin >> N >> K;
        vector<string> p(N);
        for(int i = 0; i < N; i++) cin >> p[i];
        int res = cal(p, B);
        cout << "Case #" << ca << ": " << res << endl;
    }
    return 0;
    
}   