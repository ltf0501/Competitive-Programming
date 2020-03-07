#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int a[maxn],b[maxn],no[2],p[maxn];
int vis1[maxn],vis2[maxn],z1,z2;
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),vis1[a[i]]++;
    for(int i=1;i<=n;i++)scanf("%d",&b[i]),vis2[b[i]]++;
    int now=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i])no[now++]=i;
        if(!vis1[i])z1=i;
        if(!vis2[i])z2=i;
    }
    if(vis1[a[no[0]]]==2 && vis1[a[no[1]]]==2)
    {
        if(vis2[b[no[0]]]==2)
        {

            for(int i=1;i<=n;i++)
            {
                if(i!=no[0])printf("%d ",b[i]);
                else printf("%d ",z2);
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(i!=no[1])printf("%d ",b[i]);
                else printf("%d ",z2);
            }
        }
    }
    else if(vis1[a[no[0]]]==2)
    {
        for(int i=1;i<=n;i++)
        {
            if(i!=no[0])printf("%d ",a[i]);
            else printf("%d ",z1);
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(i!=no[1])printf("%d ",a[i]);
            else printf("%d ",z1);
        }
    }
    return 0;
}
