#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

vector<vector<int>> getDis(vector<string>& mat, int r, int c){
    vector<vector<int>> dis(r, vector<int>(c, INT_MAX));
    vector<vector<bool>> vis(r, vector<bool>(c,0));
    queue<int> que;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(mat[i][j] == '1'){
                dis[i][j] = 0;
                vis[i][j] = 1;
                que.push(i*c+j);
            }
        }
    }
    vector<int> dir = {1, 0, -1, 0, 1};
    while(!que.empty()){
        int loc = que.front();
        que.pop();
        int ir = loc / c;
        int ic = loc % c;
        for(int i = 0; i < 4; i++){
            int nr = ir + dir[i];
            int nc = ic + dir[i+1];
            if(nr>=0 && nr < r && nc >= 0&& nc < c && !vis[nr][nc]){
                que.push(nr*c+nc);
                dis[nr][nc] = dis[ir][ic] + 1;
                vis[nr][nc] = 1;
            }
        }
    }
    return dis;
}

bool isAble(vector<vector<int>>& dis, int k, int R, int C){
    int minAdd = R+C, maxAdd = -R - C, minSub=R+C, maxSub=-R-C;
    int n = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(dis[i][j] <= k) continue;
            n++;
            minAdd = min(minAdd, i+j);
            maxAdd = max(maxAdd, i+j);
            minSub = min(minSub, i-j);
            maxSub = max(maxSub, i-j);
        }
    }
    if(n == 0) return true;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            int add = i+j, sub=i-j;
            if(dis[i][j] > 0 && abs(minAdd-add)<=k && abs(maxAdd-add)<=k && abs(minSub-sub)<=k && abs(maxSub-sub)<=k) return true;
        }
    }
    return false;
}

// int solve(vector<vector<int>>& dis, vector<string>& mat, int r, int c){
//     int res = 0;
//     for(int i = 0; i < r; i++){
//         for(int j = 0; j < c; j++){
//             res = max(res, dis[i][j]);
//         }
//     }
//     if(res == 0) return res;
//     for(int i = 0; i < r; i++){
//         for(int j = 0; j < c; j++){
//             if(mat[i][j] == '1') continue;
//             int curRes = 0;
//             for(int ki=0; ki<r; ki++){
//                 for(int kj=0; kj<c; kj++){
//                     curRes = max(curRes, min(dis[ki][kj], abs(ki-i)+abs(kj-j)));
//                 }
//             }
//             res = min(res, curRes);
//         }
//     }
//     return res;
// }

int main(){
    int T, R, C;
    cin >> T;
    for(int ca=1; ca <= T; ca++){
        cin >> R >> C;
        vector<string> mat(R);
        for(int i = 0; i < R; i++){
            cin >> mat[i];
        }
        vector<vector<int>> dis = getDis(mat, R, C);
        int up = 0;
        for(int i = 0; i < R; i++){
            for(int j = 0; j< C; j++) up = max(up, dis[i][j]);
        }
        int low = 0;
        while(low < up){
            int mid = low + (up - mid) / 2;
            if(isAble(dis, mid, R, C)){
                up = mid;
            }else{
                low = mid + 1;
            }
        }
        cout << "Case #" << ca << ": " << up << endl;
    }
    return 0;
}