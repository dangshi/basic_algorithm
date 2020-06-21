#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

typedef long long ll;
using namespace std;

void dfs(int u, int fa, vector<int>& parent, vector<vector<int>>& adj){
  int d = adj[u].size();
  for(int i = 0; i < d; ++i){
    int v = adj[u][i];
    if(v != fa) dfs(v, parent[v]=u, parent, adj);
  }
}

void toTree(vector<vector<int>>& adj){
  vector<int> parent(adj.size());
  parent[0] = -1;
  dfs(0, -1, parent, adj);
  for(int i = 0; i < adj.size(); ++i) adj[i].clear();
  for(int i = 1; i < adj.size(); ++i){
    adj[parent[i]].push_back(i);
  }
}

void traverse(int u, vector<vector<ll>>& dp, vector<vector<int>>& adj, vector<int>& bt){
  if(adj[u].empty()){
    dp[u][0] = 0;
    dp[u][1] = bt[u];
    dp[u][2] = LLONG_MIN;
    return ;
  }
  dp[u][0] = 0;
  for(auto v : adj[u]){
    traverse(v, dp, adj, bt);
    dp[u][0] += max(dp[v][0], dp[v][2]);
  }
  bool flag=false; // whether exists one son of node u that has a lighthouse
  int accu = 0;
  ll delta = INT_MAX;
  dp[u][1] = bt[u];
  dp[u][2] = bt[u];
  for(auto v : adj[u]){
    dp[u][1] += max(dp[v][0]+bt[v], max(dp[v][1], dp[v][2]));
    ll m = max(dp[v][0], dp[v][2]);
    accu += max(dp[v][1], m);
    delta = min(delta, m-dp[v][1]);
  }
  dp[u][2] += accu - (delta>0? delta : 0);
}



void solve(int V){
  vector<int> bt(V);
  for(int i=0; i<V; ++i){
    cin >> bt[i];
  }
  vector<vector<int>> adj(V);
  int x, y;
  for(int i = 0; i < V-1; ++i){
    cin >> x >> y;
    adj[x-1].push_back(y-1);
    adj[y-1].push_back(x-1);
  }
  toTree(adj);
  // dp[i][0]: i is not illuminated
  // dp[i][1]: node i has lighthouse ,so is illuminated
  // dp[i][2]: node i has no lighthouse, but is illuminated
  vector<vector<ll>> dp(V, vector<ll>(3));
  traverse(0, dp, adj, bt);
  ll res = max(dp[0][0], max(dp[0][1], dp[0][2]));
  cout << res << endl;
}


int main() {
  int T, V;
  cin >> T;
  for(int ca=1; ca<=T; ca++){
    cout << "Case #" << ca << ": ";
    cin >> V;
    solve(V);
  }
  return 0;
}
