#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int n;
int a[maxn][maxn];
int t[4];
main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    for(int i=0;i<n;i++)
    {
        printf("%s",a[i]);
       //for(int j=0;j<n;j++){printf("%c",a[i][j]);}
       puts("");
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)t[0]+=(a[i][j]-'0')==((i+j)%2);
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)t[1]+=(a[i][j]-'0')==((i+j)%2);
        for(int i=0;i<n;i++)scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)t[2]+=(a[i][j]-'0')==((i+j)%2);
        for(int i=0;i<n;i++)scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)t[3]+=(a[i][j]-'0')==((i+j)%2);
    int sz=n*n;
    int ans=10000000;
    printf("%d %d %d %d\n",t[0],t[1],t[2],t[3]);
    ans=min(ans,t[0]+t[1]+sz-t[2]+sz-t[3]);
    ans=min(ans,t[0]+t[2]+sz-t[1]+sz-t[3]);
    ans=min(ans,t[0]+t[3]+sz-t[1]+sz-t[2]);
    ans=min(ans,t[1]+t[2]+sz-t[0]+sz-t[3]);
    ans=min(ans,t[1]+t[3]+sz-t[0]+sz-t[2]);
    ans=min(ans,t[2]+t[3]+sz-t[0]+sz-t[1]);
    printf("%d\n",ans);
    return 0;
}
