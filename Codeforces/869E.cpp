#include<bits/stdc++.h>
using namespace std;
#define maxn 2505
#define mod 1000000007
#define ll long long
int n,m,q;
#define pii pair<int,int>
#define piiii pair<pii,pii>
#define mkp make_pair
map<piiii,int> mp;
ll d[maxn][maxn];
void update(int x,int y,ll z)
{
	for(int i=x;i<=n;i+=i&-i)
		for(int j=y;j<=m;j+=j&-j)
			d[i][j]+=z;

}

ll query(int x,int y)
{
	ll ret=0;
	for(int i=x;i;i-=i&-i)
		for(int j=y;j;j-=j&-j)
			ret+=d[i][j];
	return ret;
}

int rd()
{
	return rand() << 15 | rand();
}
main()
{
	scanf("%d%d%d",&n,&m,&q);
	srand(time(0));
	for(int i=0;i<011;i++)srand(rd());
	for(int i=0;i<q;i++)
    {
		int t,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		if(t==1)
		{
			int g=rd();
			mp[mkp(mkp(x1,y1),mkp(x2,y2))]=g;
            update(x1,y1,g);
            update(x2+1,y2+1,g);
            update(x1,y2+1,-g);
            update(x2+1,y1,-g);
		}
		else if(t==2)
        {
			int g=mp[mkp(mkp(x1,y1),mkp(x2,y2))];
			update(x1,y1,-g);
            update(x2+1,y2+1,-g);
            update(x1,y2+1,g);
            update(x2+1,y1,g);
		}
		else
        {
			ll t1=query(x1,y1),t2=query(x2,y2);
			puts(t1==t2 ? "Yes" : "No");
		}
	}
	return 0;
}
