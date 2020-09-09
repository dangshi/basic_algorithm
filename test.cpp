#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;

class Solution {
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();
        int step = 0;
        vector<bool> vis(n, 0);
        vis[0] = 1;
        if(jump[0] >= n) return 1;
        queue<int> q;
        q.push(0);
        int res;
        int preMax = 0;
        int sz = q.size();
        while(!q.empty()){
            step++;
            while(sz--){
                int cur = q.front();
                q.pop();
                int next = cur + jump[cur];
                if(next  >= n){
                    res = step;
                    return res;
                }
                if(next < n && !vis[next]) q.push(next);
                vis[next] = 1;
                if(cur <= preMax) continue;
                else{
                    for(int i = preMax+1; i < cur; ++i){
                        if(!vis[i]){
                            q.push(i);
                            vis[i] = true;
                        }
                    }
                    preMax = cur;
                }
                
            }
            sz = q.size();
        }
        return res;
    }
};

int main(){
	int a = INT_MIN;
    for(int i = 0; i < 32; ++i){
        cout << (a & 1) << endl;
        a = a >> 1;
    }
  	return 0;
}