#include<bits/stdc++.h>
using namespace std;
#define maxn 150000
int a[5][2]={{-1,0},{0,-1},{1,-1},{1,0},{0,1}};
pair<int,int> p[maxn];
main()
{
    for(int i=1,j=1,k=0;i<maxn;i+=j,j+=6,k++)
    {
        p[i]=make_pair(0,k);
        for(int m=0;m<k;m++)p[i-m]=make_pair(m,k-m);
        int cur=i;
        for(int m=0;m<5;m++)for(int n=0;n<k;n++)
        {
            int x=p[cur].first+a[m][0];
            int y=p[cur].second+a[m][1];
            p[cur+1]=make_pair(x,y);
            cur++;
        }
    }
    int n;
    while(~scanf("%d",&n))printf("%d %d\n",p[n].first,p[n].second);
    return 0;
}
