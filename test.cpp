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
	Solution sol = Solution();
    vector<vector<int>> inc = {{1,1,1},{2,5,0},{10,9,8}};
    //vector<vector<int>> inc =  {{0,4,5},{4,8,8},{8,6,1},{10,10,0}};
    vector<vector<int>> res = {{0,0,0},{20,2,6},{9,2,6},{10,18,3},{8,14,9}};
    vector<int> jump = {2, 6,3,1,1,1,1};
    sol.minJump(jump);
  	return 0;
}