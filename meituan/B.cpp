#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
#include <functional>
using namespace std;



int main(){
    //ios::sync_with_stdio(false);
    int n;
    long long m;
    cin >> n >> m;
    vector<int> room(n);
    for(int i = 0; i < n; i++) cin >> room[i];
    int res = 0;
    int st = 0;
    while(m > 0){
        m -= room[st];
        if(m >= 0) res++;
        else break;
        st = (st + 1) % n;
    }
    cout << res << endl;
    return 0;
}