#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int n, m, q;
vector<bool> newRow;
vector<bool> newCol;

void tuidao(vector<vector<int>>& ma, vector<vector<int>>& know, int i, vector<bool>& rows){
    if(rows[i]) return;
    int n = ma.size(), m = ma[0].size();
    int cnt = 0;
    for(int j = 0; j < m; j++){
        cnt += know[i][j];
    }
    if(cnt < 2) return;
    int a=-1, b=-1;
    for(int j = 0; j < m; j++){
        if(know[i][j]){
            if(a==-1) a=j;
            else{
                b = j;
                break;                    
            }
        }
    }
    if(a == -1 || b == -1) return;
    rows[i] = true;
    int gap = (ma[i][b] - ma[i][a]) / (b-a);
    for(int j = 0; j < m; j++){
        if(!know[i][j]){
            ma[i][j] = ma[i][a] + gap*(j-a);
            know[i][j] = true;
            newRow[i] = true;
        }
        
    }
}

void tuidaoCol(vector<vector<int>>& ma, vector<vector<int>>& know, int j, vector<bool>& cols){
    if(cols[j]) return;
    int n = ma.size(), m = ma[0].size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += know[i][j];
    }
    if(cnt < 2 ) return ;
    int a=-1, b=-1;
    for(int i = 0; i < n; i++){
        if(know[i][j]){
            if(a == -1) a = i;
            else {
                b = i;
                break;
            }
        }
    }
    if(a == -1 || b == -1) return;
    int gap = (ma[b][j] - ma[a][j]) / (b - a);
    for(int i = 0; i < n; i++){
        if(!know[i][j]){
            ma[i][j] = ma[a][j] + (i-a)*gap;
            know[i][j] = true;
            newCol[j] = true;
        }
    }
    cols[j] = 1;
}

void reset(){
    newRow = vector<bool>(n, 0);
    newCol = vector<bool>(m, 0);
}


int main(){
    //ios::sync_with_stdio(false);
   
    cin >> n >> m >> q;
    vector<vector<int>> ma(n, vector<int>(m));
    vector<bool> cols(m, 0);
    vector<bool> rows(n, 0);
    vector<vector<int>> know(n, vector<int>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ma[i][j];
            if(ma[i][j] > 0) {
                know[i][j] = true;
            }
        }
    }
    reset();
    for(int i = 0; i < n; i++){
        tuidao(ma, know, i, rows);
    }
    reset();
    for(int j = 0; j < m; j++){
        tuidaoCol(ma, know, j, cols);
    }
    bool flag = true;
    
    
    int x, y;
    while(q--){
        cin >> x >> y;
        if(know[x-1][y-1]){
            cout << ma[x-1][y-1] << endl; 
        }else{
            tuidao(ma, know, x-1, rows);
            tuidap(ma,know, y-1, cols);
            cout << "Unkown" << endl;
        }
    }
    
    
    return 0;
}