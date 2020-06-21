#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
#include <cmath>
using namespace std;

int main(){
    //ios::sync_with_stdio(false);
     int M, N;
    vector<long long> dp(1010, 0);
    dp[0] = 1;
    cin >> M;
    int modNum = pow(10, 9) + 3;
    while(M--){
        cin >> N;
        if(dp[N]) cout << dp[N] % modNum<< endl;
        else {
            int i = 1;
            while(dp[i]) i++;
            while(i <= N){
                int pre = 1;
                while(i - pre >= 0){
                    dp[i] += dp[i-pre];
                    pre *= 2;
                }
                i++;
            }
            cout << dp[N] % modNum << endl;
        }
    }
    
    return 0;
}