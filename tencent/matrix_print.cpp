#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n = 4;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            int k = min(min(i-0, n-1-i), min(j-0, n-1-j));
            k = n - 2*k;
            int m = (n-1-k-1) / 2 + 1;
            int base = m * (n-1)*4 - (m-1)*m / 2; 
            if(j >= i){
                cout << base + (i+j-(n-k)) << " ";
            }else{
                cout << base + 4*(k-1) - (i+j) << " ";
            }

        }
        cout << endl;
    }
    return 0;
}