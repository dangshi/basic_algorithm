#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int cal(vector<int>&p, int b){
    int res = 0;
    sort(p.begin(), p.end());
    for(auto v: p){
        if(b >= v){
            b-=v;
            res++;
        }else break;
    }
    return res;
}

int main(){
    int T, N, B;
    cin >> T;
    for(int ca=1; ca<= T; ca++){
        cin >> N >> B;
        vector<int> p(N);
        for(int i = 0; i < N; i++) cin >> p[i];
        int res = cal(p, B);
        cout << "Case #" << ca << ": " << res << endl;
    }
    return 0;
    
}   