#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
    int T, N, K;
    cin >> T;
    for(int ca=1; ca<=T; ++ca){
        cin >> N >> K;
        vector<int> P(N);
        unordered_map<int, vector<int>> um;
        for(int i = 0; i < N; ++i) cin >> P[i];
        int color;
        for(int i = 0; i < N; ++i){
            cin >> color;
            um[color].push_back(P[i]);
        }
        int colorNum = um.size();
        for(auto it = um.begin(); it != um.end(); it++){
            sort(it->second.begin(), it->second.end());
        }
        vector<vector<vector<int>>> dp(colorNum, vector<vector<int>>(K+1, vector<int>(2, INT_MAX)));
        auto it = um.begin();
        dp[0][0][0] = 0;
        dp[0][0][1] = 0;
        for(int j = 1; j <= it->second.size(); ++j){
            dp[0][j][0] = 2*it->second[j-1];
            dp[0][j][1] = it->second[j-1];
        }
        it++;
        for(int i=1; it != um.end(); it++,++i){
            dp[i][0][0] = 0;
            dp[i][0][1] = 0;
            for(int j = 1; j <= K; ++j){
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0]);
                dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][1]); 
                for(int s = 1;  s <= it->second.size() && s <= j; ++s){
                    if(dp[i-1][j-s][0] != INT_MAX){
                        dp[i][j][0] = min(dp[i][j][0], dp[i-1][j-s][0]+2*it->second[s-1]);
                        dp[i][j][1] =  min(dp[i-1][j-s][0] + it->second[s-1], dp[i][j][1]);
                    }
                    if(dp[i-1][j-s][1] != INT_MAX){
                        dp[i][j][1] = min(dp[i][j][1], dp[i-1][j-s][1] + 2*it->second[s-1]);
                    }
                    
                }
            }
        }
        int res = dp[colorNum-1][K][1];
       
        
        cout << "Case #" << ca << ": " << res << endl;
    }
    return 0;   
}