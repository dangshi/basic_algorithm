#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
#include <functional>
using namespace std;



int main(){
    //ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    if(n <= 1) {
        cout << 0 << endl;
        return 0;
    } 
    int l = 0;
    int res = 0;
    int i = 1;
    while(i < n){
         if(nums[i] - nums[l] <= x){
            res = max(res, i-l+1);
            i++;
        }else{
            l++;
        }
    }
   
    cout << n - res << endl;
    return 0;
}