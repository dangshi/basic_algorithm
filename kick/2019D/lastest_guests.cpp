#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(int N, int G, int M){
    vector<int> lTime(N, -1);
    vector<int> rTime(N, -1);
    string dir;
    int pos;
    vector<int> H(G);
    vector<char> C(G);
    for(int i = 0; i < G; ++i){
        cin >> pos >> dir;
        pos--;  
        H[i] = pos;
        C[i] = dir[0];
        if(dir[0] == 'C'){
            int final = (pos + M) % N;
            rTime[final] = M;
        }else{
            int final = (pos - M) % N;
            if(final < 0) final += N;
            lTime[final] = M;
        }
    }
    int cur = -1;
    for(int i = 0; i < 2*N; ++i){
        cur = max(cur-1, lTime[i%N]);
        lTime[i%N] = cur;
    }
    cur = -1;
    for(int i = 2*N-1; i>=0; --i){
        cur = max(cur-1, rTime[i%N]);
        rTime[i%N] = cur;
    }
    vector<int> cntl(N, 0);
    vector<int> cntr(N, 0);
    for(int i = 0; i < N; i++){
        int res = max(lTime[i], rTime[i]);
        if(res < 0) continue;
        if(res == lTime[i]){
            cntl[(i+res)%N]++;  
        }
        if(res == rTime[i]){
            int idx = (i-res)%N;
            if(idx < 0) idx += N;
            cntr[idx]++;
        }
    }
    for(int i = 0; i < G; ++i){
        int ans = 0;
        if(C[i] == 'C'){
            ans = cntr[H[i]];
        }else{
            ans = cntl[H[i]];
        }
        cout <<  " " << ans ;
    }
    cout << endl;
}

int main(){
    int T, N, G, M;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca){
        cout << "Case #" << ca << ":";
        cin >> N >> G >> M;
        solve(N, G, M);
    }
    return 0;
}