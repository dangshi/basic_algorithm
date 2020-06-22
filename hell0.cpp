#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <iostream>
using namespace std;

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
    cout << "hello world" << endl;
    return 0;
}

