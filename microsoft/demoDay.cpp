#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int getMinNum( vector<string>& maze, int N, int M){
    int dp[N][M][2];
    if(N == 1 || M == 1){
        int sum = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++) sum += int(maze[i][j] == 'b');
        }
        return sum;
    }
    
    dp[0][0][0] = maze[0][0] == 'b' ;
    dp[0][0][1] = (int)(maze[0][0] == 'b') + (int)(maze[0][1] != 'b');
    for(int i = 1; i < N; i++){
        int j = 0;
        dp[i][j][0] = dp[i-1][j][1] + (maze[i][j] == 'b') + (i+1<N && maze[i+1][j] != 'b');
        dp[i][j][1] = dp[i-1][j][1] + (maze[i][j] == 'b');
    }
    for(int j = 1; j < M; j++){
        int i = 0;
        dp[0][j][0] = dp[0][j-1][0] + (maze[0][j] == 'b');
        dp[0][j][1] = dp[0][j-1][0] + (maze[0][j] == 'b') + (j+1<M && maze[0][j+1] != 'b');
    }
    for(int i = 1; i < N; i++){
        for(int j = 1; j < M; j++){
            dp[i][j][0] = min(dp[i][j-1][0], dp[i-1][j][1]  + (i+1<N && maze[i+1][j]!='b')) + (maze[i][j]=='b');
            dp[i][j][1] = min(dp[i-1][j][1], dp[i][j-1][0]  + ((j+1<M && maze[i][j+1] != 'b'))) + (maze[i][j]=='b');
        }
    }
    return min(dp[N-1][M-1][0], dp[N-1][M-1][1]);

}



int main(){
    int M, N;
    cin >> N >> M;
    vector<string> maze(N);
    
    for(int i = 0; i < N; i++){
        cin >> maze[i];
    }
    int res = getMinNum(maze, N, M);
    cout << res << endl;
    return 0;
}