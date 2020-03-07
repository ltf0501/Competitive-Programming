#include<bits/stdc++.h>
#include "lib1896.h"
using namespace std;
int c[1500];
void initialize(int n)
{
    memset(c,0,sizeof(c));
}
int hasEdge(int u,int v)
{
    return ++c[u > v ? u : v]==(u > v ? u : v);
}
