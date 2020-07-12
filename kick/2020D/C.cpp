#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>
using namespace std;

void solve(){
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> f(N+3, 1);
    vector<bool> vis(N+5, 0);
    vector<int> depth(N+5, 0);
    int maxDep = 0;
    for(int i = 2; i <= N; ++i){
        cin >> f[i];
        vis[f[i]] = 1;
        depth[i] = depth[f[i]] + 1;
        maxDep = max(depth[i], maxDep);
    }
    vector<int> cnt(N+5, 0);

    vector<double> sa(N+5, 1.0/N);
    vector<double> sb(N+5, 1.0/N);
    vector<double> pa(N+5, 1.0/N);
    vector<double> pb(N+5, 1.0/N);


    int step = 0;
    for(int i = maxDep; i > 0; --i){
        step += 1;
        for(int j = 1; j <= N; ++j){
            if(depth[j] != i) continue;
            int up = f[j];
            sa[up] += sa[j];
            sb[up] += sb[j];
            if(step % A == 0){
                pa[up] += sa[j];
            }
            if(step % B == 0){
                pb[up] += sb[j];
            }
        }
    }

    double res  = 0;
    for(int i = 1; i <= N; ++i){
        res += pa[i] + pb[i] - pa[i]*pb[i];
    }
    cout << res << endl;

}

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

