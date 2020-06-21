#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<char, pair<int, int>> dirMap;

map<char, pair<int,int>> getNeighbor(int x, int y){
    map<char, pair<int, int>> neigh;
    for(auto it=dirMap.begin(); it!=dirMap.end(); it++){
        neigh[it->first] = {x+it->second.first, y+it->second.second};
    }
    return neigh;
}

int main(){
    dirMap['W'] = pair<int, int>(0, -1);
    dirMap['E'] = pair<int, int>(0, 1);
    dirMap['N'] = pair<int, int>(-1, 0);
    dirMap['S'] = pair<int, int>(1, 0);
    int T, N, R, C, sr, sc;
    cin >> T;
    for(int ca=1; ca<=T; ++ca){
        cin >> N >> R >> C >> sr >> sc;
        string ins;
        cin >> ins;
        map<pair<int,int>, map<char, pair<int, int>>> uF; // union find
        uF[pair<int, int>(sr, sc)] = getNeighbor(sr, sc);
        for( char ch : ins){
            sr += dirMap[ch].first;
            sc += dirMap[ch].second;
            vector<pair<int, int>> posV;
            while(uF.find(pair<int,int>(sr, sc)) != uF.end()){
                pair<int, int> pos = pair<int,int>(sr, sc);
                posV.push_back(pos);
                sr = uF[pos][ch].first;
                sc = uF[pos][ch].second;
            }
            for(auto it=posV.begin(); it!=posV.end(); it++){
                uF[*it][ch] = pair<int, int>(sr, sc);
            }
            uF[pair<int,int>(sr, sc)] = getNeighbor(sr, sc);
        }
        cout << "Case #" << ca << ": " << sr << " " << sc << endl;
    }
    return 0;   
}