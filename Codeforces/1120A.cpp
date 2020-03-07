#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define pii pair<int,int>
#define F first
#define S second
int n,m,k,s;
int a[maxn],b[maxn],cnt[maxn];
int need[maxn];
vector<int> ans;
main()
{
    scanf("%d%d%d%d",&m,&k,&n,&s);
    for(int i=1;i<=m;i++)scanf("%d",&a[i]);
    int ccnt=0;
    for(int i=1;i<=s;i++)
    {
        scanf("%d",&b[i]);
        if(!need[b[i]])ccnt++;
        need[b[i]]++;
    }
    for(int i=1,r=0;i<=m;i++)
    {
        while(r<=m && ccnt)
        {
            r++;
            need[a[r]]--;
            if(!need[a[r]])ccnt--;
        }
        if(!ccnt)
        {
            int tmp=(i-1)/k+(m-r)/k;
            if(tmp<n)continue ;
            vector<pii> p;
            vector<int> tt;
            for(int j=i;j<r;j++)p.push_back(pii(a[j],j));
            sort(p.begin(),p.end());
            int pos=0;
            for(int j=0;j<s;j++)
            {
                while(pos<(int)p.size() && b[j]!=p[pos].F)tt.push_back(p[pos++].S);
                pos++;
            }
            while(pos<(int)p.size())tt.push_back(p[pos++].S);
            for(int j=k-s;j<(int)tt.size();j++)ans.push_back(tt[j]);
            for(int j=0;j<i%k;j++)ans.push_back(j+1);
            sort(ans.begin(),ans.end());
            printf("%d %d\n",i,r);
            printf("%d\n",(int)ans.size());
            for(int id : ans)printf("%d ",id);puts("");
            return 0;
        }
        if(!need[a[i]])ccnt++;
        need[a[i]]++;
    }
    puts("-1");
    return 0;
}

