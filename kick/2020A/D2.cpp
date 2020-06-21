#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int cal(vector<string>& p, int k){
    int n = p.size();
    if(n <= 0) return 0;
    int len = 0;
    auto cmp = [](const string& a, const string& b) {
        if(a.size() == b.size()) return a < b;
        return a.size() < b.size();
    };
    sort(p.begin(), p.end(), cmp);
    int minLen = p[0].size();
    int maxLen = p[n-1].size();
    len =maxLen;
    
    int score = 0;
    int i = p.size() - 1;
    while(i >= 0){
        vector<string> left;
        for(; i >= 0; i--){
            if(p[i].size() < len)  break;
            int cnt = 1;
            while(i >= 1 && p[i] == p[i-1]){
                cnt++;
                i--;
            }
            score += len * (cnt / k);
            cnt = cnt % k;
            while(cnt-- && len){
                left.push_back(p[i].substr(0, len-1));
            }
        }
        if(len == 1) break;
        for(int j = 0; j < left.size(); j++){
            p[++i] = left[j];
        }
        len = p[i].size();
        
    }
    return score;
    
}

int main(){
    int T, N, K;
    cin >> T;
    for(int ca=1; ca<= T; ca++){
        cin >> N >> K;
        vector<string> p(N);
        for(int i = 0; i < N; i++) cin >> p[i];
        int res = cal(p, K);
        cout << "Case #" << ca << ": " << res << endl;
    }
    return 0;
    
}       