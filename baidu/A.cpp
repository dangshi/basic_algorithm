#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
#include <functional>
using namespace std;



int main(){
    //ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    long long  ans = 0;
    long long  sub = 0;
    for(int i = 0; i < m; i++){
        ans += a[i] - sub;
        sub += b[i];
    }
    cout << ans << endl;    
    return 0;
}