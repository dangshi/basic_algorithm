#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    int N;
    cin >> N;
    if( N <= 1) return N;
    vector<pair<int, int>> brick(N);
    for(int i = 0; i < N; i++){
        int w, h;
        cin >> w >> h;
        brick[i] = {w, h};
    }
    auto cmp = [](const pair<int,int>& a, const pair<int, int>& b){
        if(a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
    };
    sort(brick.begin(), brick.end(), cmp);
    vector<int> lis;
    for(int i = 0; i < N; i++){
        if(lis.empty() || brick[i].second >= lis.back()){
            lis.push_back(brick[i].second);
        }else{
            auto it = lower_bound(lis.begin(), lis.end(), brick[i].second);
            *it = brick[i].second;
        }
    }
    cout << lis.size() << endl;
    
    return 0;
}