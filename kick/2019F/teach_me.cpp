#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <functional>
#define ll long long
using namespace std;

class myHash{
public:
    ll operator()(const vector<int>& cur) const {
        //vector<int> cur = x;
        //sort(cur.begin(), cur.end());
        ll res = cur.front();
        for(int i = 1; i < cur.size(); ++i){
            res <<= 10;
            res |= cur[i];
        }
        return res;
    }
};

vector<vector<int>> getSub(const vector<int>& num){
    vector<vector<int>> res;
    res.push_back({});
    int end = res.size();
    for(int i = 0; i < num.size(); ++i){
        for(int j = 0; j < end; ++j){
            vector<int> tmp = res[j];
            tmp.push_back(num[i]);
            res.push_back(tmp);
        }
        end = res.size();
    }
    return res;
}

void solve(int N, int S){
    unordered_map<vector<int>, int, myHash> emp;
    for(int i = 0; i < N; ++i){
        int c;
        cin >> c;
        vector<int> cur(c);
        for(int j = 0; j < c; ++j){
            cin >> cur[j];
        }
        sort(cur.begin(), cur.end());
        emp[cur]++;
    }
    ll ans = 0;
    for(auto it=emp.begin(); it != emp.end(); it++){
        vector<vector<int>> subs = getSub(it->first);
        int cnt = 0;
        for(int i = 1; i < subs.size(); ++i){
            if(emp.find(subs[i]) != emp.end()) cnt += emp[subs[i]];
        }
        ans += (N - cnt) * it->second;
    }
    
    cout << ans << endl;
    
}


int main(){
    int T, N, S;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca){
        cin >> N >> S;
        cout << "Case #" << ca << ": ";
        solve(N, S);
    }   
    return 0;
}