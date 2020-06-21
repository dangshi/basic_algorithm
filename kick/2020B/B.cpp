#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>
#define ll long long
using namespace std;

bool canReach(vector<ll>& bus, ll st, ll D){
    ll res = st;
    for(auto v : bus){
        ll left = res % v;
        if(left < 0) left += v;
        if(left){
            res += (v - left);
        } 
        if(res > D) break;
    }
    return res <= D;
}

void solve(ll N, ll D){
    vector<ll> bus(N);
    bool oneDay = true;
    for(ll i = 0; i < N; ++i){
        cin >> bus[i];
        if(bus[i] != 1) oneDay = false;
    }
    if(oneDay){
        cout << D << endl;
        return;
    }
    ll l=1,  r=D;
    while(l <= r){
        ll mid = (r-l)/2 + l;
        if(canReach(bus, mid, D)) l = mid+1;
        else r = mid-1;
    }
    if(l-1>=0 && canReach(bus, l-1, D)) cout << l-1 << endl;
    else cout << l << endl;
    return ;
    
}


int main(){
    ll T, N;
    ll D;
    cin >> T;
    for(ll ca = 1; ca <= T; ++ca){
        cin >> N >> D;
        cout << "Case #" << ca << ": ";
        solve(N, D);
    }   
    return 0;
}