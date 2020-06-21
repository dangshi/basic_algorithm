#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include <vector>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) cin >> b[i];
	for(int i = 1;i <= n - 1;i++)
		for(int j = i + 1;j <= n;j++)
		if(b[i] < b[j]) 
		{
			swap(b[i],b[j]);
			swap(a[i],a[j]);
    	}
	for(int i = 1;i <= n;i++)
	{
		dp[i - 1][0] = 0;
		for(int j = 1;j <= min(i, m);j++)
			dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 1] + a[i] - b[i] * (j - 1));
	}
	cout << dp[n][m] << endl;
	return 0;
}