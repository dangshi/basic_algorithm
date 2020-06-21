#include <iostream>
#include <vector>

#define LL long long
using namespace std;

const int maxn = 200000;
LL A[maxn+1];
struct Node{
    LL ms, si, size;
    Node operator + (const Node& node) const{
        Node res;
        res.size =  size + node.size;
        if(size & 1) res.si = si - node.si;
        else res.si = si + node.si;
        if(size & 1) res.ms = ms - node.ms - node.si * size;
        else res.ms = ms + node.ms + size * node.si;
        return res; 
    }
}T[maxn << 2];

void build(int v, int tl, int tr){
    if(tl == tr){
        T[v].size = 1;
        T[v].ms = T[v].si = A[tl];
    }else{
        int lv = v<<1, tm=(tl+tr) >> 1;
        int rv = lv|1;
        build(lv, tl, tm);
        build(rv, tm+1, tr);
        T[v] = T[lv] + T[rv];
    }
}

void update(int v, int tl, int tr, int X, int V){
    if(tl == tr){
        T[v].ms = T[v].si = V;
    }else{
        int tm = (tl + tr) >> 1, lv=v<<1;
        if(X <= tm) update(lv, tl, tm, X, V);
        else update(lv|1, tm+1, tr, X, V);
        T[v] = T[lv] + T[lv|1];
    }
}

Node query(int v, int tl, int tr, int L, int R){
    if(tl >= L && tr <= R) return T[v];
    int lv=v<<1, tm=(tl+tr) >> 1;
    if(R <= tm) return query(lv, tl, tm, L, R);
    if(L > tm)  return query(lv+1, tm+1, tr, L, R);
    return query(v<<1, tl, tm, L, R) + query(lv|1, tm+1, tr, L, R);
}


void solve(int N, int Q){
    for(int i = 1; i <= N; ++i) cin >> A[i];
    vector<Node> tree(4*N+10);
    build(1, 1, N);
    LL res = 0;
    for(int i = 1; i <=Q; ++i){
        string s;
        cin >> s;
        if(s == "U"){
            LL X, V;
            cin >> X >> V;
            update(1, 1, N, X, V);
        }else{
            int L, R;
            cin >> L >> R;
            res += query(1, 1, N, L, R).ms;
        }
    }
    cout << res << endl;
}

int main(){
    int T, N, Q;
    cin >> T;
    for(int ca = 1; ca <= T; ca++){
        cout << "Case #" << ca << ": " ;
        cin >> N >> Q;
        solve(N, Q);
    }
    return 0;
}