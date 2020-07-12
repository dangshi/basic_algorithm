#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void solve(){
    int N;
    cin >> N;
    vector<int> num(N);
    for(int i = 0; i < N; ++i){
        cin >> num[i];
    }
    int pre = INT_MIN;
    int res = 0;
    for(int i = 0; i < N; ++i){
        if(num[i] > pre && (i == N-1 || num[i] > num[i+1])){
            res++;
        }
        pre = max(pre, num[i]);
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
}