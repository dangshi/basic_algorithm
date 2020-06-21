#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int solve(vector<int>& nums, int n, int p){
    if(p == 1) return 0;
    sort(nums.begin(), nums.end());
    int res = 0;
    for(int i = 0; i < p; i++) res += nums[p-1] - nums[i];
    int next = res;
    for(int i = p; i<n; i++){
        next = next - (nums[i-1] - nums[i-p]);
        next += (nums[i] - nums[i-1]) * (p-1);
        res = min(res, next);
    }
    return res;
}

int main(){
    int T, N, P;
    cin >> T;
    for(int ca=1; ca <= T; ca++){
        cin >> N >> P;
        vector<int> nums(N);
        for(int i = 0; i < N; i++) cin >> nums[i];
        int res = solve(nums, N, P);
        cout << "Case #" << ca << ": " << res << endl;
    }
    return 0;
}