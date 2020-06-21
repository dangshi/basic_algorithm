#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#define ll long long
using namespace std;
struct Slot{
  int c;
  int e;
};

void solve(int D, int S){
    vector<Slot> slots(S);
    for(int i = 0; i < S; ++i){
        cin >> slots[i].c >> slots[i].e;
    }
    auto cmp = [](const Slot&a, const Slot& b){
      return (a.c*1.0/a.e) > (b.c*1.0/b.e);  
    };
    sort(slots.begin(), slots.end(), cmp);
    vector<int> preCoding(S, 0);
    preCoding[0] = slots[0].c;
    for(int i = 1; i < S; ++i){
        preCoding[i] = preCoding[i-1] + slots[i].c;
    }
    vector<int> sufEating(S, 0);
    sufEating[S-1] = slots.back().e;
    for(int i = S-2; i>=0; --i){
        sufEating[i] = sufEating[i+1] + slots[i].e;
    }
    for(int i = 0; i < D; ++i){
        int A, B;
        cin >> A >> B;
        auto it = lower_bound(preCoding.begin(), preCoding.end(), A);
        if(it == preCoding.end()){
            cout << "N";
        }else{
            if(B == 0) cout << "Y";
            else{
                int idx = (int)(it - preCoding.begin());
                double left = (*it-A)*1.0 / slots[idx].c * slots[idx].e;
                if(idx + 1 < S){
                    left += sufEating[idx + 1];
                }
                if(left >= B) cout << "Y";
                else cout << "N";
            }
              
        }
    }
    cout << endl;
}

int main(){
    int T, D, S;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca){
        cout << "Case #" << ca << ": ";
        cin >> D >> S;
        solve(D, S);
    }
    return 0;
}