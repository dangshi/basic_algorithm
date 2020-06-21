#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
typedef pair<int, int> pii;
 
const int N = 50010;
 
int n;
char s[N];
long long ans;
priority_queue<pii, vector<pii>, greater<pii> > q;
 
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    
    int cnt = 0;
    
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == '(') ++cnt;
        else if (s[i] == ')') --cnt;
        else
        {
            int a, b;
            scanf("%d%d", &a, &b);
            --cnt;
            s[i] = ')';
            ans += b;
            q.push(pii(a - b, i));
        }
        if (cnt < 0)
        {
            if (q.empty()) break;
            cnt += 2;
            ans += q.top().first;
            s[q.top().second] = '(';
            q.pop();
        }
    }
    
    if (cnt == 0) printf("%lld\n%s", ans, s + 1);
    else printf("-1\n");
    
    return 0;
}
