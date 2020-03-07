#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
char c[maxn][maxn];
int k,n;
vector<int> pos[maxn];
int cnt[26];
main()
{
    scanf("%d%d",&k,&n);
    scanf("%s",c[0]);
    for(int i=0;i<n;i++)cnt[c[0][i]-'a']++;
    bool ok=0;
    for(int i=0;i<26;i++)if(cnt[i]>=2){ok=1;break;}
    for(int i=1;i<k;i++)
    {
        scanf("%s",c[i]);
        int tmp_cnt[26]={0};
        for(int j=0;j<n;j++)tmp_cnt[c[i][j]-'a']++;
        for(int j=0;j<26;j++)if(tmp_cnt[j]!=cnt[j])
            return 0*puts("-1");
    }
    for(int i=1;i<k;i++)for(int j=0;j<n;j++)if(c[0][j]!=c[i][j])
    {
        pos[i].push_back(j);
        if(pos[i].size()>4)return 0*puts("-1");
    }
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
    {
        swap(c[0][i],c[0][j]);
        bool flag=1;
        for(int t=1;t<k;t++)
        {
            int id[2],a=0;
            if(c[0][i]!=c[t][i])id[a++]=i;
            if(c[0][j]!=c[t][j])id[a++]=j;
            //printf("%d %d %d\n",i,j,a);
            for(int p : pos[t])if(p!=i && p!=j && c[0][p]!=c[t][p])
            {
                if(a==2){flag=0;break;}
                id[a++]=p;
            }
            if(!flag)break;
            if(a==0)
            {
               if(ok)continue;
               else {flag=0;break;}
            }
            else if(a==1){flag=0;break;}
            else
            {
                if(c[0][id[0]]!=c[t][id[1]] || c[0][id[1]]!=c[t][id[0]]){flag=0;break;}
            }
        }
        if(flag)return 0*puts(c[0]);
        swap(c[0][i],c[0][j]);
    }
    puts("-1");
    return 0;
}
/*
3 4
abac
caab
acba
*/
