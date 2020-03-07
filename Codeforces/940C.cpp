#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
char c[maxn];
int id[26];
bool ok[26];
vector<int> v;
main()
{
    int n,k;scanf("%d%d",&n,&k);
    scanf("%s",c+1);
    for(int i=1;i<=n;i++)ok[c[i]-'a']=1;
    int last;
    int cnt=0;
    for(int i=0;i<26;i++)if(ok[i])v.push_back(i),last=i,id[i]=cnt++;
    //for(int s : v)printf("%d ",s);puts("");
    if(n<k)
    {
        printf("%s",c+1);
        for(int i=1;i<=k-n;i++)printf("%c",v[0]+'a');
    }
    else
    {
        int cur=k;
        while(c[cur]==last+'a')
            c[cur--]=v[0]+'a';
        //printf("%d %d\n",c[cur]-'a'+1,id[c[cur]-'a'+1]);
        c[cur]=v[id[c[cur]-'a']+1]+'a';
        for(int i=1;i<=k;i++)printf("%c",c[i]);
    }
    return 0;
}
