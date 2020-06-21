#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void cal(vector<vector<int>>& grid, vector<vector<int>>& dis, int n, int m, int S, int T){
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    dis[S][T] = 0;
    vis[S][T] = 1;
    queue<pair<int,int>> q;
    q.push({S, T});
    int step = 0;
    int size = q.size();
    while(!q.empty()){
        step++;
        while(size--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x+1<n && !vis[x+1][y] && (grid[x][y]&2) == 0) {
                dis[x+1][y] = step;
                vis[x+1][y] = 1;
                q.push({x+1, y});
            }
            if(x-1>=0 && !vis[x-1][y] && (grid[x][y]&1) == 0) {
                dis[x-1][y] = step;
                vis[x-1][y] = 1;
                q.push({x-1, y});
            }
            if(y+1<m && !vis[x][y+1] && (grid[x][y]&8) == 0) {
                dis[x][y+1] = step;
                vis[x][y+1] = 1;
                q.push({x, y+1});
            }
            if(y-1>=0 && !vis[x][y-1] && (grid[x][y]&4) == 0) {
                dis[x][y-1] = step;
                vis[x][y-1] = 1;
                q.push({x, y-1});
            }
        }
        size = q.size();
    }

}


int main(){
	int T;
    cin >> T;
    for(int ca=1; ca<=T; ca++){
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cin >> grid[i][j];
        }
        vector<vector<int>> dis(n, vector<int>(m, -1));
        cal(grid, dis, n, m, S-1, T-1);
        cout << "Case " << ca << ":" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << dis[i][j] << " ";
            }
            cout << endl;
        }
    }
  	return 0;
}