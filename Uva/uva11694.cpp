#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 10
char chess[MAXN][MAXN];
int point[MAXN][MAXN];
bool link[MAXN][MAXN][MAXN][MAXN];
int n;
int go[4][2]={1,1,1,-1,-1,-1,-1,1};
main()
{
    int t;cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)cin>>chess[i][j];


    }
    return 0;
}
