// solution by Xuri Gong

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <queue>
using namespace std;

struct Interval{
    int s, e, k;
};

auto cmp = [](const Interval& a, const Interval& b) {
    if(a.s == b.s) return a.e < b.e;
    else return a.s > b.s;
};

bool valid(priority_queue<Interval, vector<Interval>, decltype(cmp)> pq, int k){
    Interval cur = pq.top();
    pq.pop();
    while(!pq.empty()){
        Interval top = pq.top();
        int need = cur.k == -1? k : cur.k;
        if(cur.e < top.s ) {
            if(cur.e - cur.s +1 < need) return false;
            else{
                cur = top;
                pq.pop();
                continue;
            }
        }

        if(top.s - cur.s >= need) {
            cur = top;
            pq.pop();
            continue;
        }else{
            int req = top.s - cur.s;
            if(top.e == cur.e){
                return false;
            }else if(top.e < cur.e){
                Interval right = {top.e+1, cur.e, need-req};
                pq.push(right);
                cur = pq.top();
                pq.pop();
                continue;
            }else{
                pq.pop();
                int topNeed = top.k == -1? k : top.k;
                Interval right = {cur.e+1, top.e, topNeed};
                pq.push(right);
            }
        }
    }
    int need = cur.k == -1? k : cur.k;
    return cur.e - cur.s + 1 >= need;
}

int main(){
    int T, N, Q;
    cin >> T;
    for(int caseN=1; caseN<=T; caseN++){
        cin >> N >> Q;
        vector<pair<int, int>> itn(Q);
        priority_queue<Interval, vector<Interval>, decltype(cmp)> pq(cmp);
        int l=0, r=INT_MAX;
        int s, e, k;
        for(int i = 0; i < Q; i++){
            cin >> s >> e;
            pq.push({s, e, -1});
            r = min(r, e-s+1);
        }

        r++;
        while(l < r - 1){
            int mid = l + (r-l)/2;
            if(valid(pq, mid)) l = mid;
            else r = mid ;
        }
        cout << "Case #" << caseN << ": " << l << endl;
    }
}