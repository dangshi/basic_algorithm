#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>
#define ll double
#define pdd pair<double, double>
#define zero 1e-35
using namespace std;

void solve(int W, int H, int L, int U, int R, int D){
    vector<double> dp(W+1, 0);
    int width = R - L + 1;
    int height = D - U + 1;
    if(width == W || height == H ) {
        cout << 0.0 << endl;
        return;
    }
    if((L == 1 && U == 1) || (R==W && D==H)){
        cout << 0.0 << endl;
        return;
    }
    dp[1] = 2.0;
    for(int i = 1; i <= U-1; ++i){
        dp[1] = dp[1] / 2.0;
        for(int j = 2; j <= W; ++j){
            dp[j] = (dp[j-1] /2.0) + dp[j]/2.0;
        }
    }
    double npro = 0.0;
    for(int j = L; j <= R; ++j){
        npro += dp[j]/2.0;
    }
    for(int i = U; i <= min(H, D); ++i){
        dp[1] = dp[1] / 2.0;
        for(int j = 2; j < L; ++j){
            dp[j] = dp[j-1]/2.0 + dp[j]/2.0;
        }
        if(L > 1)npro += dp[L-1] / 2.0;
    }
    cout << 1.0 - npro << endl; 
}


int main(){
    int T, W, H, L, U, R, D;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca){
        cin >> W >> H >> L >> U >> R >> D;
        cout << "Case #" << ca << ": ";
        solve(W, H, L, U, R, D);
    }   
    return 0;
}