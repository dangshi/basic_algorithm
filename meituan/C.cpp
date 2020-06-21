    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <utility>
    #include <climits>
    #include <functional>
    #include <stdio.h>
    #include <queue>
    using namespace std;

    struct my{
        float gl;
        float sc;
        int num;
    };


    int main(){
        //ios::sync_with_stdio(false);
        int n, k;
        cin >> n >> k;
        vector<float> p(n+1);
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) cin >> p[i];
        for(int i = 1; i <= n; i++) cin >> a[i];
        queue<my> q;
        q.push({p[1], a[1]*p[1], 1});
        float res = a[1] * p[1];
        vector<pair<float, float>> tmp(n, {0, 1});
        tmp[0] = {p[1], a[1]*p[1]};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                my cur = q.front();
                q.pop();
                for(int i = 1; i <= n; i++){
                    if(cur.num + i <= n){
                        res = max(res, cur.sc+cur.gl*p[i]*a[i]);
                        my next = {cur.gl*p[i], cur.sc+cur.gl*p[i]*a[i], cur.num+i};
                        if(next.sc <= tmp[next.num-1].second && next.gl <= tmp[next.num-1].first) continue;
                        else tmp[next.num-1] = {next.gl, next.sc};
                        q.push(next);
                    }
                }
            }
        }
        printf("%.2f\n", res);
        return 0;
    }