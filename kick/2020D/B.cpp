#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void solve(){
    int K;
    cin >> K;
    vector<int> num(K);
    for(int i = 0; i < K; ++i) cin >> num[i];
    vector<vector<int>> dp(10005, vector<int>(4, 0));
    for(int i = 1; i < K; ++i){
        int pre = dp[i-1][0];
        for(int j = 1; j < 4; ++j){
            pre = min(pre, dp[i-1][j]);
        }
        for(int j = 0; j < 4; ++j) dp[i][j] = pre + 1;
        for(int j = 0; j < 4; ++j){
            if(num[i] == num[i-1]){
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
            if(num[i] > num[i-1]){
                for(int k = j-1; k >=0; --k){
                    dp[i][j] = min(dp[i][j], dp[i-1][k]);
                }
            }
            if(num[i] < num[i-1]){
                for(int k = j + 1; k < 4; ++k){
                    dp[i][j] = min(dp[i][j], dp[i-1][k]);
                }
            }
        }
    }
    int res = dp[K-1][0];
    res = min(res, min(dp[K-1][1], min(dp[K-1][2], dp[K-1][3])));
    cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    for(int ca=1; ca <= T; ca++){
        cout << "Case #" << ca << ": ";
        solve();
    }
}