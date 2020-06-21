#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
	int N;
    cin >> N;
    string warrior;
    int total=0, maxAw=0;
    for(int i = 0; i < N; i++){
        string name;
        int a,b, num;
        string c, d;
        int cur = 0;
        cin >> name;
        cin >> a >> b >> c >> d >> num;
        if(a > 80 && num) cur += 8000;
        if(a>85 && b > 80) cur+=4000;
        if(a>90) cur+= 2000;
        if(a > 85 && d[0] == 'Y') cur += 1000;
        if(b >  80 && c[0] == 'Y') cur += 850;
        if(cur > maxAw){
            maxAw = cur;
            warrior = name;
        }
        total += cur;
    }
    cout << warrior << endl;
    cout << maxAw<<endl;
    cout << total << endl;
  	return 0;
}