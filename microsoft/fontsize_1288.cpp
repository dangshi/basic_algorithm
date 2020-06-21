#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isValid(vector<int>& para, int f, int P, int W, int H){
    if(f > W || f > H) return false;
    int w = floor(W*1.0 / f);
    int h = floor(H*1.0 / f);
    P = P * h;
    for(auto v : para){
        if(P >= 0){
            P -=  ceil(v * 1.0 / w);
        }else break;
    }
    return P >= 0;
}

int main(){
    int T, N, P, W, H;
    cin >> T;
    while(T--){
        cin >> N >> P >> W >> H;
        vector<int> para(N);
        int sum = 0;
        for(int i = 0; i < N; i++) {
            cin >> para[i];
            sum += para[i];            
        }
        int res;
        if(ceil(sum*1.0 / W) > P*H)  {
            cout << 0 << endl;
            continue;
        }
        int l=1, r= min(W,H) + 1;
        while(l < r-1){
            int mid = l + (r-l) / 2;
            if(isValid(para, mid,  P,  W,  H)) l = mid;
            else r = mid;
        }
        cout << l << endl;
    }
    return 0;
}