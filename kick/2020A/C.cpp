#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <math.h>
using namespace std;

bool isValid(vector<int>& gap, int k, int m){
    sort(gap.begin(), gap.end(), greater<int>());
    for(auto v : gap){
        if(v > m){
            k -= ceil(v*1.0 / m) - 1;
            if(k < 0) return false;
            
        }else{
            break;
        }
    }
    return k >= 0;
}

int cal(vector<int>& p, int k){
    int dif = 0;
    int n = p.size();
    vector<int> gap(n-1, 0);
    for(int i = 0; i < n-1; i++){
        gap[i] = p[i+1] - p[i];
        dif = max(dif, gap[i]);
    }
    if(dif <= 1) return dif;
    int l = 1, r=dif;
    while(l < r){
        int mid = l + (r-l)/2;
        if(isValid(gap, k, mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
    int T, N, K;
    cin >> T;
    for(int ca=1; ca<= T; ca++){
        cin >> N >> K;
        vector<int> p(N);
        for(int i = 0; i < N; i++) cin >> p[i];
        int res = cal(p, K);
        cout << "Case #" << ca << ": " << res << endl;
    }
    return 0;
    
}   