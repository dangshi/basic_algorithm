#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
	int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        int cnt=0, h, pre=-1;
        while(n--){
            cin >> h;
            if(h > pre){
                cnt++;
                pre = h;
            }
        }
        cout << cnt << endl;
    }
  	return 0;
}