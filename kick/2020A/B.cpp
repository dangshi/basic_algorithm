#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, K, P, res;

int cal(vector<vector<int>>& plt){
    vector<vector<int>> dp(N, vector<int>(P+1, 0));
    for(int j = 1; j <= P; j++){
        if(j  <= K)dp[0][j] += dp[0][j-1] + plt[0][j-1];
        else dp[0][j] = dp[0][K];
    }
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= P; j++){
            int tmp = 0;
            for(int h=0; h <= min(j, K); h++){
                if(h == 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                else{
                    tmp += plt[i][h-1];
                    dp[i][j] = max(dp[i][j], dp[i-1][j-h]+tmp);
                }
            }
        }
    }
    return dp[N-1][P];
}


int main(){
    int T;
    cin >> T;
    for(int ca=1; ca<= T; ca++){
        cin >> N >> K >> P;
        vector<vector<int>> plt(N, vector<int>(K));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < K; j++){
                cin >> plt[i][j];
            }
        }
        res = cal(plt);
        
        cout << "Case #" << ca << ": " << res << endl;
        
    }
    return 0;
    
}   