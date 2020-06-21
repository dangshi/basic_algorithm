#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

void solve(int N, int K){
    vector<int> height(N+1);
    for(int i = 1; i <= N; ++i){
        cin >> height[i];
    }
    vector<vector<int>> rm(N+1, vector<int>(N+1));
    for(int i = 1; i <= N; ++i){
        unordered_map<int,int> um;
        int tmp = 0;
        for(int j = i; j <= N; ++j){
            um[height[j]]++;
            tmp = max(tmp, um[height[j]]);
            rm[i][j] = j-i+1 - tmp;
        }
    }
    vector<vector<int>> dp(N+1, vector<int>(K+1, INT_MAX));
    for(int i = 0; i <= K; ++i) dp[0][i] = 0;
    for(int i = 1; i <=N; ++i )dp[i][0] = rm[1][i];
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j < i; ++j){
            for(int k=0; k < K; ++k){
                if(dp[j][k] != INT_MAX){
                    dp[i][k+1] = min(dp[i][k+1], dp[j][k]+rm[j+1][i]);
                }   
            }
        }
    }
    cout << dp[N][K] << endl;  
    return;
}

int main(){
    int T, N, K;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca){
        cin >> N >>K ;
        cout << "Case #" << ca << ": ";
        solve(N, K);
    }
    return 0;
}