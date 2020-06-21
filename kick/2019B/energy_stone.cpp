#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stone{
    int S;
    int E;
    int L;
};  

int main(){
    int T, N;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca){
       cin >> N;
       vector<stone> st(N);
       int totalTime = 0;
       for(int i = 0; i < N; ++i){
           cin >> st[i].S >> st[i].E >> st[i].L;
           totalTime += st[i].S;
        }
        auto cmp = [](const stone& a, const stone& b){
          return a.S*b.L <   b.S*a.L;  
        };
        int res = 0;
        sort(st.begin(), st.end(), cmp);
        vector<int> dp(totalTime+1, 0);
        for(int i = 0; i < N; ++i){
            for(int j = totalTime; j >= 0; --j){
                if(j >= st[i].S) dp[j] = max(dp[j], dp[j-st[i].S] + max(0, st[i].E - (j-st[i].S)*st[i].L));
                res = max(res, dp[j]);
            }
        }
        cout << "Case #" << ca << ": " << res << endl;
     }
    return 0;
}