#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int m;
char c[maxn];
map<int,string> mp;
int cnt[60];
int x[3],iid[3];
int id(char c)
{
    if('a'<=c && c<='z')return c-'a';
    return c-'A'+26;
}
bool cmp(int i,int j){return x[i]>x[j];}
main()
{
    scanf("%d",&m);
    mp[0]="Kuro",mp[1]="Shiro",mp[2]="Katie";
    for(int k=0;k<3;k++)
    {
        scanf("%s",c+1);
        int n=strlen(c+1);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)cnt[id(c[i])]++;
        for(int i=0;i<52;i++)
        {
            if(n>cnt[i]+m)x[k]=max(x[k],cnt[i]+m);
            else
            {
                if(cnt[i]==n && m==1)x[k]=max(x[k],n-1);
                else x[k]=n;
            }
        }
    }
    //for(int i=0;i<3;i++)printf("%d ",x[i]);puts("");
    for(int i=0;i<3;i++)iid[i]=i;
    sort(iid,iid+3,cmp);
    if(x[iid[0]]==x[iid[1]])return 0*puts("Draw");
    else cout<<mp[iid[0]];
    return 0;
}

