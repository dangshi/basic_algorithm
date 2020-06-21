#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

const int maxN = 1e5 + 5;
int T, N, S;

int type[maxN], a[maxN];
vector<int> pos[maxN];

struct Node{
    int l, r;
    int s, ps;
}tr[maxN<<2];

void build(int u, int l, int r){
    tr[u].l = l;
    tr[u].r = r;
    if(l == r){
        tr[u].s = tr[u].ps = a[l];
        return;
    }
    int mid = (l+r) >> 1, left=u<<1, right=left|1;
    build(left, l, mid);
    build(right, mid+1, r);
    tr[u].s = tr[left].s + tr[right].s;
    tr[u].ps = max(tr[left].ps, tr[right].ps+tr[left].s);
}

void update(int u, int k, int v){
    if(tr[u].l == tr[u].r){
        a[k] = v;
        tr[u].s = v;
        tr[u].ps = v;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1, left=u<<1, right=left|1;
    if(k  <= mid){
        update(left, k, v);
    }else{
        update(right, k, v);
    }
    tr[u].s = tr[left].s + tr[right].s;
    tr[u].ps = max(tr[left].ps, tr[right].ps+tr[left].s);
}

int main(){
    cin >> T;
    for(int ca = 1; ca <= T; ++ca){
        cin >> N >> S;
        for(int i = 0; i < maxN; ++i) pos[i].clear();
        for(int i = 0; i < N; ++i) {
            cin >> type[i];
            pos[type[i]].push_back(i);
        }

        memset(a, 0, sizeof(a));
        for(int i = 0; i < maxN; ++i){
            for(int j = 0; j < pos[i].size() && j < S; ++j){
                a[pos[i][j]] = 1;
            }
            if(pos[i].size() > S) a[pos[i][S]] = -S;
        }
        // cout << endl;
        // for(int i = 0; i < N; ++i) cout << a[i] << " ";
        // cout << endl;
        build(1, 0, N-1);
        int res = tr[1].ps;

        //cout << endl << res  << endl;
        for(int i = 0; i < N; ++i){
            update(1, i, 0);
            auto indexes = pos[type[i]];
            int j = find(indexes.begin(), indexes.end(), i) - indexes.begin();
            if(j+S < indexes.size()) update(1, indexes[j+S], 1);
            if(j+S+1 < indexes.size()) update(1, indexes[j+S+1], -S);
            res = max(res, tr[1].ps);
        }
        cout << "Case #" << ca << ": " << res << endl;
    }   
    return 0;
}