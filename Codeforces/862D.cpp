#include<bits/stdc++.h>
using namespace std;
char s[1005],t[1005];
int a[2],n,f,p,q;
/*
int cnt(char s[],char t[])
{
    int cnt=0;
    for(int i=0;i<strlen(t);i++)
        if(s[i]!=t[i])cnt++;
    return cnt;
}
*/
int bs(int l,int r)
{
    if(l==r)return l;
    int m=(l+r)>>1;
    for(int i=0;i<n;i++)s[i]='0'+f;
    for(int i=l;i<=m;i++)s[i]='0'+(f^1);
    printf("? %s\n",s);
    fflush(stdout);
    int tmp;
    scanf("%d",&tmp);
    if(p+r-m==tmp)
    {
        p=tmp;
        return bs(l,m);
    }
    int a=(p+r-m-tmp)/2;
    p=q-(r-m-a)+a;
    return bs(m+1,r);
}
main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)s[i]='0';
    printf("? %s\n",s);
    fflush(stdout);
    scanf("%d",&p);
    s[0]='1';
    printf("? %s\n",s);
    fflush(stdout);
    scanf("%d",&q);
    if(p>q)a[1]=1;
    else a[0]=1;
    f=a[0]?1:0;
    for(int i=0;i<n;i++)s[i]='0'+(f^1);
    printf("? %s\n",s);
    fflush(stdout);
    scanf("%d",&p);
    q=n-p;
    a[f]=bs(0,n-1)+1;
    printf("! %d %d\n",a[0],a[1]);
    fflush(stdout);
    return 0;
}
