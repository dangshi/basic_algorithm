#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;


int main(){

    vector<int> vec = {2,1,4,3,6,5};
    sort(vec.begin(), vec.end(), greater<int>());
    auto it = lower_bound(vec.begin(), vec.end(), 8);
    cout << (it == vec.end());
    int  k = it - vec.begin();
    cout << vec[0] << endl;
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(2);
    pq.push(1);
    cout << pq.top() << endl; 

    vector<vector<int>> ma = {{1,2}, {4, 3}, {3, 4}, {2, 1}, {7, 7}};
    sort(ma.begin(), ma.end());
    auto cmp = [](const vector<int>& a, int b) {return a[0] < b;};
    auto lb = lower_bound(ma.begin(), ma.end(), 4, cmp);

    map<int, int> mp = {{1,2}, {3,5}, {8, 9}, {5,4}};
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first;
        mp.erase(it);
        cout << it->first;
    }


    return 0;

}
