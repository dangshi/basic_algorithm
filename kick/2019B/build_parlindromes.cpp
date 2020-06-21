#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    int T, N, Q;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca){
        cin >> N >> Q;
        vector<vector<int>> dp(N, vector<int>(26, 0));
        string blo;
        cin >> blo;
        int ans = 0;
        dp[0][blo[0]-'A'] = 1;
        for(int i = 1; i < N; ++i){
            dp[i] = dp[i-1];
            dp[i][blo[i] - 'A']++;
        }
        int L, R;
        for(int i = 0; i < Q; ++i){
            cin >> L >> R;
            vector<int> cur(26, 0);
            if(L == 1) cur = dp[R-1];
            else{
                for(int j = 0; j < 26; ++j){
                    cur[j] = dp[R-1][j] - dp[L-2][j]; 
                }
            }
            
            int single = 0;
            for(int j = 0; j < 26; ++j){
                if(cur[j] % 2) single++;
                if(single >= 2) break;
            }
            if(single <= 1) ans++;
        }
        cout << "Case #" << ca << ": " << ans << endl;
    }
    return 0;
}