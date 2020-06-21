#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

bool valid(vector<pair<int, int>>& itn, int k){
    int q = itn.size();
    vector<int> bias(q);
    for(int i = 0; i < q; i++) bias[i] = itn[i].first;
    for(int i = 0; i < q; i++){
        int r = itn[i].second;
        int st = bias[i];
        int cnt = 0, nextS;
        for(int j = i + 1; j<q; j++){
            if(itn[j].first > r) break;
            if(itn[j].second <= r){
                if(itn[j].first <= st){
                    st = max(st, itn[j].second+1);
                }else{
                    cnt += itn[j].first - st ;
                    st = itn[j].second+1;
                    if(cnt >= k){
                        nextS = itn[j].first - (cnt - k);
                        break;
                    }
                }
            }
        }

        if(cnt < k){
            cnt += r - st + 1;
            if(cnt < k ) return false;
            nextS = r - (cnt-k) + 1;
        }

        for(int j = i + 1; j < q; j++){
            if(itn[j].first >= nextS) break;
            if(itn[j].second > r){
                bias[j] =  max(bias[j], r+1);
            }
        }
        
    }
    return true;
}

int main(){
    int T, N, Q;
    cin >> T;
    for(int caseN=1; caseN<=T; caseN++){
        cin >> N >> Q;
        vector<pair<int, int>> itn(Q);
        int l=0, r=INT_MAX;
        for(int i = 0; i < Q; i++){
            cin >> itn[i].first >> itn[i].second;
            r = min(r, itn[i].second-itn[i].first+1);
        }
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            if(a.first == b.first) return a.second > b.second;
            else return a.first < b.first;
        };
        sort(itn.begin(), itn.end(), cmp);
        r++;
        while(l < r - 1){
            int mid = l + (r-l)/2;
            if(valid(itn, mid)) l = mid;
            else r = mid ;
        }
        cout << "Case #" << caseN << ": " << l << endl;
    }
}