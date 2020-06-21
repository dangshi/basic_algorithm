#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int c=1; c<= T; c++){
        vector<int>  dig(9, 0);
        vector<int> smv(9, 0);
        vector<int> bigv(9, 0);
        long long n = 0;
        for(int i = 0; i<9; i++) {
            cin >> dig[i];
            n += dig[i];
        }
        long long subN = n / 2;
        int smallN=0, ind=0;
        while( smallN < subN){
            if(smallN + dig[ind] < subN){
                smallN += dig[ind];
                smv[ind] = dig[ind];
                ind++;
            }else{
                smv[ind] = subN - smallN;
                break;
            }
        }
        int l=ind, r=ind;
        bigv[ind] = dig[ind] - smv[ind];
        for(int i = ind+1; i<9; i++){
            bigv[i] = dig[i];
        }
        
        int dif = 0;
        for(int i = 0; i < 9; i++){
            dif += (bigv[i] - smv[i]) * (i+1);
        }
        cout << "Case #" << c << ": ";
        if(dif % 11 == 0){
            cout << "YES" << endl;
            continue;
        } 
        bool res = false;
        while(r < 9){
            while(r < 9 && bigv[r] == 0) r++;
            if(r >= 9) {
                break;
            }
            int l = r - 1;
            while(l >= 0 && smv[l] == 0) l--;
            if(l < 0){
                r++;
                continue;
            }
            dif -= (r-l)*2;
            if(dif % 11 == 0){
                res = true;
                break;
            }
            bigv[r]--;
            bigv[l]++;
            smv[l]--;
            smv[r]++;
            
        }
        if(res) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}