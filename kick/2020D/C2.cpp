//
// Created by lan on 2020/7/12.
// by dfs
//
/*
 * 愚蠢的问题
 * 用dfs即可，主要最后的输出问题
 *  fixed setprecision
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include  <iomanip>
#define LL long long
using namespace std;

void dfs(const vector<vector<int>>& child, vector<LL>& cntA, vector<LL>& cntB, vector<int>& path, int cur, int A, int B){
    cntA[cur] += 1;
    cntB[cur] += 1;
    path.push_back(cur);
    for(int i = 0; i < child[cur].size(); ++i){
        dfs(child, cntA, cntB, path, child[cur][i], A, B);
    }
    path.pop_back();
    int n = path.size();
    if(n >= A){
        cntA[path[n-A]] += cntA[cur];
    }
    if(n >= B){
        cntB[path[n-B]] += cntB[cur];
    }
}

void solve(){
    int N, A, B, p;
    cin >> N >> A >> B;
    vector<vector<int>> child(N+1, vector<int>());
    for(int i = 2; i <= N; ++i){
        cin >> p;
        child[p].push_back(i);
    }
    vector<LL> cntA(N+1, 0);
    vector<LL> cntB(N+1, 0);
    vector<int> path;
    dfs(child, cntA, cntB, path, 1, A, B);
    LL res = 0;
    for(int i = 1; i <= N; ++i){
        res += (cntA[i]  * N) + (cntB[i]  * N) -  (cntA[i] ) * (cntB[i] );
    }
    double ans = res * 1.0 / ((LL)N*N);
    cout<<fixed<<setprecision(6)<<ans<<endl;
    //cout << ans << endl;  // or long  double
}
/*
3
8 1 1
1 1 3 4 4 3 4
10 3 4
1 1 1 1 1 1 1 1 1
4 3 1
1 2 3
*/

int main(){
    int T;
    cin >> T;
    for(int ca=1; ca <= T; ca++){
        cout << "Case #" << ca << ": ";
        solve();
    }
}//
// Created by lan on 2020/7/12.
//

