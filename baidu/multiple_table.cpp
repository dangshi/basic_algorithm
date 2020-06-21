#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int getNum(int mid, int n, int m){
    int cnt = 0;
    for(int i = 1; i <= n && i <= mid; i++){
        cnt += min(mid/i, m);
    }
    return cnt;
}

int main(){
	int n, m, k;
    cin >> n >> m >> k;
    int l = 1, r=n*m+1;
    while(l < r){
        int mid = l + (r-l) / 2;
        int cnt = getNum(mid, n, m);
        if(cnt >= k) r = mid;
        else  l = mid + 1;
    }
    cout << l << endl;
  	return 0;
}