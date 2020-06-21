#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void qS(vector<int>& nums, int l, int r){
    if(l < r){
        int key = nums[l];
        int i = l, j=r;
        while(i < j){
            while(j > i && nums[j] >= key) j--;
            if(j > i) nums[i++] = nums[j];
            while(i < j && nums[i] < key) i++;
            if(i < j) nums[j--] = nums[i];
        }
        nums[i] = key;
        qS(nums, l, i-1);
        qS(nums, i+1, r);
    }
}

void qS2(vector<int>& nums, int l, int r){
    if(l < r){
        int pivot =  nums[l];
        int i = l;
        for(int j = l; j <= r; j++){
            if(nums[j] <= pivot){
                swap(nums[i++], nums[j]);
            }
        }
        swap(nums[i-1], nums[l]);
        qS2(nums, l, i-2);
        qS2(nums, i, r);

    }
}

void qS3(vector<int>&nums, int l, int r){
    if(l < r){
        int pivot = nums[r];
        int k = l;
        for(int i = l; i < r; i++){
            if(nums[i] <= pivot){
                swap(nums[i], nums[k++]);
            } 
        }
        swap(nums[k], nums[r]);
        qS3(nums, l, k-1);
        qS3(nums, k+1, r);
    }
}


int main(){
    vector<int> nums = {3,5,7,9,2,3,1,0,7,5,4};
    qS3(nums, 0, nums.size()-1);
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}