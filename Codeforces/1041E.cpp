#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int cnt[maxn],n;
set<int> s;
main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(y!=n)return 0*puts("NO");
        cnt[x]++;
    }
    for(int i=1;i<n;i++)
    {
        cnt[i]+=cnt[i-1];
        if(cnt[i]>i)return 0*puts("NO");
    }
    puts("YES");
    for(int i=1;i<n;i++)s.insert(i);
    int cur=-1;
    for(int i=1;i<n;i++)
    {
        if(cnt[i])
		{
			s.erase(i);
			if(cur!=-1)printf("%d %d\n",cur,i);
			cur=i;
			cnt[i]--;
		}
		while(cnt[i] > 0)
		{
			printf("%d %d\n", last, *unused.begin());
			last = *unused.begin();
			cnt[i]--;
			unused.erase(unused.begin());
		}
    }
    return 0;
}
