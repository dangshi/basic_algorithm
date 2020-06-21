#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>
#include <stack>
#define ll long long
using namespace std;



void solve(){
    string ins;
    cin >> ins;
    stack<int> pre;
    pre.push(1);
    int n = ins.size();
    int i = 0;
    ll X = 0;
    ll base = 1e9;
    unordered_map<char, ll> um;
    while(i < n){
        if(ins[i] >= '0' && ins[i] <= '9'){
            X = 0;
            while(ins[i] >= '0' && ins[i] <= '9'){
                X = X * 10 + ins[i] - '0';
                i++;
            }
        }else if(ins[i] == 'E' || ins[i] == 'W' || ins[i] == 'S' || ins[i] == 'N'){
            if(X) um[ins[i]] +=  pre.top() * X;
            else um[ins[i]] += pre.top();
            um[ins[i]] %= base;
            i++;
        }else if(ins[i] == '('){
            i++;
            pre.push(X*pre.top());
            X = 0;
        }else {
            i++;
            pre.pop();
            X = 0;
        }
    }
    ll colMove = um['E'] - um['W'];
    ll col = 0;
    col = (col + colMove) % base;
    if(col < 0) col += base;
    col++;
    ll rowMove = um['S'] - um['N'];
    ll row = 0;
    row = (row + rowMove) % base;
    if(row < 0) row += base;
    row++;
    cout << col << " " << row << endl;
}


int main(){
    int T;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca){
        cout << "Case #" << ca << ": ";
        solve();
    }   
    return 0;
}