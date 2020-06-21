#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int getBit(int x){
    int ans = 0; 
    int bit = 1;
    for(int i = 0; i < 32; ++i){
        if(x & bit) ans++;
        bit = bit << 1;
    }
    return ans;
}

int main(){
    //ios::sync_with_stdio(false);
    int T, N, Q;
    cin >> T;
    for(int ca=1; ca<=T; ca++){
        cin >> N >> Q;
        vector<int> pos;
        int Ai;
        for(int i = 0; i < N; i++){
            cin >> Ai;
            int bitNum = getBit(Ai);
            if(bitNum & 1) pos.push_back(i);    
        }
        cout << "Case #" << ca << ":";
        int pi, vi;
        for(int i = 0; i < Q; ++i){
            cin >> pi >> vi;
            int bitNum = getBit(vi);
            auto it = lower_bound(pos.begin(), pos.end(), pi);
            if(bitNum & 1){
                if(it == pos.end() || *it != pi){
                    pos.insert(it, pi);
                }
            }else{
                if(it !=pos.end() && *it == pi){
                    pos.erase(it);
                }
            }
            
            if(pos.size() & 1){
                cout << " " << max(pos.back(), N-pos.front()-1);
            }else{
                cout << " " << N;
            }
        }
        cout << endl;
    }
    
    
    return 0;
}