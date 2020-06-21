#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int cal(vector<vector<int>>& ma){
    int n = ma[0].size();
    vector<vector<long long>> dp(n, vector<long long>(3, LONG_LONG_MAX));
    for(int j = 0; j < 3; j++) dp[0][j] = 0;
    for(int i = 1; i <n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                dp[i][j] = min(dp[i][j], abs(ma[j][i] - ma[k][i-1])+dp[i-1][k]);
            }
            
        }
    }
    return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}

int main(){
    //ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> ma(3, vector<int>(n));
    int a, b, c;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cin >> ma[i][j];
        }
    }
    int res = cal(ma);
    cout << res << endl;
    return 0;
}