#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    vector<int> vec(10);
    cout << vec.size() << endl;
    vec.push_back(10);
    cout << vec.front() << endl;
    
    return 0;
}