#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits.h>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <queue>
#include <memory.h>
#include <typeinfo>
#include <math.h>
using namespace std;

class Solution {
public:
    int cal(int x, int a, int b, int c){
        return x*x*a+b*x+c;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> res(n, 0);
        if(n == 0) return res;
        if(a == 0){
            if(b >= 0){
                for(int i = 0; i < n; i++){
                    res[i] = b*nums[i] + c;
                }
            }else{
                for(int i = 0; i < n; i++){
                    res[i] = b*nums[n-1-i] + c;
                }
            }
            return res;
        }
        int l=0, r=n-1, idx=0;
        double mid = -1.0 * b / a / 2.0;
        if(a > 0){
            idx = n-1;
            while(l <= r){
                if(abs(l-mid) > abs(r-mid)){
                    res[idx--] = cal(nums[l++], a, b, c);
                }else{
                    res[idx--] = cal(nums[r--], a, b, c);
                }
            }
        }else{
            idx = 0;
            while(l <= r){
                if(abs(l-mid) > abs(r-mid)){
                    res[idx++] = cal(nums[l++], a, b, c);
                }else{
                    res[idx++] = cal(nums[r--], a, b, c);
                }
            }
        }
        return res;

    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);
        getline(cin, line);
        int c = stringToInteger(line);
        
        vector<int> ret = Solution().sortTransformedArray(nums, a, b, c);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}