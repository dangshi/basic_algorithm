#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#define ll long long
using namespace std;

int getF(vector<int>& f, int a){
    if(a != f[a]){
        f[a] = getF(f, f[a]);
    }
    return f[a];
}

void solve(int N, int M){
    vector<int> f(N+1);
    for(int i = 1; i < N+1; ++i){
        f[i] = i;
    }
    int x, y;
    int ans = 0;
    for(int i = 0; i < M; ++i){
        cin >> x >> y;
        int fx = getF(f,x);
        int fy = getF(f, y);
        if(fx != fy){
            f[fx] = fy;
            ans++;
        }
    }
    ans = ans + (N-1-ans) * 2;
    cout << ans << endl;
}


int main(){
    int T, N, M;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca){
        cout << "Case #" << ca << ": ";
        cin >> N >> M;
        solve(N, M);
    }
    return 0;
}