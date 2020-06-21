#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#define ll long long
using namespace std;


struct spot{
  int x;
  int c;
};
void solve(int K, int N){
    vector<spot> pos(N);
    for(int i = 0; i < N; ++i){
        cin >> pos[i].x;
    }
    for(int i = 0; i < N; ++i){
        cin >> pos[i].c;
    }
    auto cmp = [](const spot&a, const spot& b){
      return a.x < b.x;  
    };
    sort(pos.begin(), pos.end(), cmp);
    int leftNum = K / 2;
    int rightNum = K - leftNum;
    priority_queue<int> leftSingle;
    vector<ll> leftTotal(N, LLONG_MAX);
    ll cur = 0;
    for(int i = 0; i < leftNum; ++i){
        int cost = pos[i].c + abs(pos.back().x-pos[i].x);
        leftSingle.push(cost);
        cur += cost;
    }
    leftTotal[leftNum] = cur + leftNum * (ll)(pos[leftNum].x - pos.back().x);
    for(int i = leftNum; i < N-rightNum-1; ++i){
        int cost = pos[i].c + abs(pos.back().x-pos[i].x);
        if(leftNum && cost < leftSingle.top()){
            cur -= (leftSingle.top() - cost);
            leftSingle.pop();
            leftSingle.push(cost);
        }
        leftTotal[i+1] = cur + leftNum * (ll)(pos[i+1].x - pos.back().x);
    }
    // do for the right part, similar to left
    cur = 0;
    priority_queue<int> rightSingle;
    vector<ll> rightTotal(N, LLONG_MAX);
    for(int i = 0; i < rightNum; ++i){
        int cost = pos[N-1-i].c + pos[N-1-i].x;
        rightSingle.push(cost);
        cur += cost;
    }
    rightTotal[N-rightNum-1] = cur - rightNum * (ll)pos[N-1-rightNum].x;
    for(int i = N-1-rightNum; i>leftNum; --i){
        int cost = pos[i].c + pos[i].x;
        if(rightNum && cost < rightSingle.top()){
            cur -= (rightSingle.top() - cost);
            rightSingle.pop();
            rightSingle.push(cost);
        }
        rightTotal[i-1] = cur - rightNum * (ll)pos[i-1].x;
    }
    ll res = LLONG_MAX;
    for(int i = 0; i < N; ++i){
        if(leftTotal[i] == LLONG_MAX || rightTotal[i]==LLONG_MAX) continue;
        res = min(res, leftTotal[i]+rightTotal[i]+pos[i].c);
    }
    cout << res << endl;
}

int main(){
    int T,K, N;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca){
        cout << "Case #" << ca << ": ";
        cin >> K >> N;
        solve(K, N);
    }
    return 0;
}