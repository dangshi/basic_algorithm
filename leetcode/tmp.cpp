#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1;
        int res = min(height[l], height[r]) * (n-1);
        while(l < r){
            if(height[l] < height[r]){
                int lmax = height[l];
                while(l < r){
                    l++;
                    if(height[l] > lmax){
                        lmax = height[l];
                        res = min(height[l], height[r]) * (l-r);
                        break;
                    }
                }
            }else{
                int rmax = height[r];
                while(l < r){
                    r--;
                    if(height[r] > rmax){
                        rmax = height[r];
                        res = min(height[l], height[r]) * (l-r);
                        break;
                    }
                }
            }
        }
        return res;
    }
    
};