#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int minLen = INT_MAX;
string toBinary(int a){
    string res = "";
    for( int i = 0; i < 8; i++){
        res = to_string(a&1) +  res;
        a = a >> 1;
    }
    return res;
}

string toMask(const string& ip){
    int start = 0;
    int n = ip.size();
    int i = start;
    string res = "";
    int mask = -1;
    int part = 0;
    string rule = "";
    while(i < n){
        int j = i;
        if(part == 4){
            mask = stoi(ip.substr(i, n-i+1));
            if(mask != 0)minLen = min(minLen, mask);
            break;
        }
        while(j<n && (ip[j] != '.' && ip[j] != '/')) j++;
        rule += toBinary(stoi(ip.substr(i, j-i)));
        i = j + 1;
        part++;
    }
    if(mask != -1) return rule.substr(0, mask);
    else return rule;
}

int main(){
    int M, N;
    cin >> N >> M;
    vector<pair<string, bool>> rules;
    for(int i = 0; i < N; i++){
        string allow, s ;
        cin >> allow >> s;
        bool flag = allow[0]=='a' ? true : false;
        rules.push_back({toMask(s), flag});
               
    }
    for(int i = 0; i < M; i++){
        string  s;
        cin  >> s;
        s = toMask(s);
        bool flag = true;
        for(auto it = rules.begin(); it != rules.end(); it++){
            string ru = it->first;
            if(ru == s.substr(0, ru.size())){
                flag = it->second;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    
    return 0;
}