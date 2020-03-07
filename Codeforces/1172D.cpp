#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
#define pii pair<int,int>
#define F first
#define S second
int r[maxn],c[maxn];
int pos_r[maxn],pos_c[maxn];
int st_r[maxn],st_c[maxn],ed_r[maxn],ed_c[maxn];
vector<pair<pii,pii>> ans;
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&r[i]),ed_r[r[i]]=i;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]),ed_c[c[i]]=i;
	for(int i=1;i<=n;i++)st_r[i]=st_c[i]=pos_r[i]=pos_c[i]=i;
	for(int i=1;i<n;i++)
	{
		int now_r=ed_r[i],now_c=ed_c[i];
		int sr=st_r[i],sc=st_c[i];
		if(st_r[now_r]==i && st_c[now_c]==i)continue;
		if(st_r[i]==ed_r[i] && st_c[i]==ed_c[i])continue;
		ans.push_back(make_pair(pii(pos_r[now_r],i),make_pair(i,pos_c[now_c])));
		//swap poeple now_r and pos_r[i]
		swap(st_r[i],st_r[pos_r[now_r]]);
		swap(st_c[i],st_c[pos_c[now_c]]);
		//swap the position cur_row and i
		swap(pos_r[now_r],pos_r[sr]);
		swap(pos_c[now_c],pos_c[sc]);
	}
	printf("%d\n",(int)ans.size());
	for(auto t : ans)printf("%d %d %d %d\n",t.F.F,t.F.S,t.S.F,t.S.S);
	return 0;
}
