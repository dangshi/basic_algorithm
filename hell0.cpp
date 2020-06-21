#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct node;
typedef node* pnode;
struct node
{
    pnode parent;
    int info;
};
pnode create(int x)
{
    pnode p;
    p=(pnode)malloc(sizeof(struct node));
    p->parent=p;p->info=x;
    return p;
}
pnode root(pnode p)
{
    if (p->parent==p) return p;
    else p->parent=root(p->parent);
    return p->parent;
}

int unionn (pnode s,pnode t)
{
    s->parent=root(t);
    return 0;
}

int main()
{
    pnode lan[50005];
    int n,m,i,j;
    int k,l[50005];
    int r[50005]={0};
    int use[50005] = {0};
    int sum=-1;
    int sumUse = 0;
    scanf("%d %d",&n,&m);
    for (i=1;i<=m;i++) lan[i]=create(i);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for (j=1;j<=k;j++)
        {
            scanf("%d",&l[j]);
            use[l[j]] = 1;
            if (j>1) unionn(lan[l[j]],lan[l[j-1]]);
        }
    }
    for (i=1;i<=m;i++) if (r[root(lan[i])->info]==0)
        {
            r[root(lan[i])->info]=1;
            sum++;
            
        }
    for(int i = 1; i <= m; i++)if(use[i] == 0) sumUse++;
    printf("%d",sum - sumUse);
    return 0;
}


public class Solution {

    private boolean used[] = new boolean[9];

    public int numberOfPatterns(int m, int n) {	        
        int res = 0;
        for (int len = m; len <= n; len++) {	            
            res += calcPatterns(-1, len);
            for (int i = 0; i < 9; i++) {	                
                used[i] = false;
            }            
        }
        return res;
    }

    private boolean isValid(int index, int last) {
        if (used[index])
            return false;
        // first digit of the pattern    
        if (last == -1)
            return true;
        // knight moves or adjacent cells (in a row or in a column)	       
        if ((index + last) % 2 == 1)
            return true;
        // indexes are at both end of the diagonals for example 0,0, and 8,8          
        int mid = (index + last)/2;
        if (mid == 4)
            return used[mid];
        // adjacent cells on diagonal  - for example 0,0 and 1,0 or 2,0 and //1,1
        if ((index%3 != last%3) && (index/3 != last/3)) {
            return true;
        }
        // all other cells which are not adjacent
        return used[mid];
    }

    private int calcPatterns(int last, int len) {
        if (len == 0)
            return 1;    
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            if (isValid(i, last)) {
                used[i] = true;
                sum += calcPatterns(i, len - 1);
                used[i] = false;                    
            }
        }
        return sum;
    }
}
