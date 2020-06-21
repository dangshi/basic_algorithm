#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int main(){
    int T, R, C, K;
    cin >> T;
    for(int ca=1; ca<=T; ++ca){
        cin >> R >> C >> K;
        vector<vector<int>> mat(R, vector<int>(C));
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                cin >> mat[i][j];
            }
        }
        vector<vector<int>> len(R, vector<int>(C, 1));
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                int curMax = mat[i][j];
                int curMin = curMax;
                for(int k = j+1; k < C; ++k){
                    curMax = max(curMax, mat[i][k]);
                    curMin = min(curMin, mat[i][k]);
                    if(curMax - curMin <= K){
                        len[i][j]++;
                    }else break;
                }
            }
        }
        int res = 0;
        for(int j = 0; j < C; ++j){
            stack<int> height;
            int area = 0;
            for(int i = 0; i < R; ++i){
                if(height.empty() || len[height.top()][j] < len[i][j]){
                    height.push(i);
                }else{
                    while(!height.empty() && len[i][j] <= len[height.top()][j]){
                        int h = len[height.top()][j];
                        height.pop();
                        int w = height.empty()? i : i-height.top()-1;
                        area = max(area, h*w);
                    }
                    height.push(i);
                }
            }
            while(!height.empty()){
                int h = len[height.top()][j];
                height.pop();
                int w = height.empty()? R : R-height.top()-1;
                area = max(area, h*w);
            }
            res = max(res, area);
        }
        
        cout << "Case #" << ca << ": " << res << endl;
    }
    return 0;   
}