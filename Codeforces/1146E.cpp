#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int seg[maxn<<2],tg[maxn<<2],_set[maxn<<2];
int a[maxn];
void push_down(int o)
{
	if(_set[o]!=-1)
	{
		tg[o<<1]=tg[o<<1|1]=0;
		_set[o<<1]=_set[o<<1|1]=_set[o];
		_set[o]=-1;
	}
	if(tg[o])
	{
		tg[o<<1]^=1,tg[o<<1|1]^=1;
		tg[o]=0;
	}
}
void flip(int ql,int qr,int l=0,int r=maxn-1,int o=1)
{
	if(ql<=l && r<=qr){tg[o]^=1;return ;}
	push_down(o);
	int m=(l+r)>>1;
	if(ql<=m)flip(ql,qr,l,m,o<<1);
	if(qr>m)flip(ql,qr,m+1,r,o<<1|1);
}
void Set(int ql,int qr,int k,int l=0,int r=maxn-1,int o=1)
{
	if(ql<=l && r<=qr){tg[o]=0,_set[o]=k;return ;}
	push_down(o);
	int m=(l+r)>>1;
	if(ql<=m)Set(ql,qr,k,l,m,o<<1);
	if(qr>m)Set(ql,qr,k,m+1,r,o<<1|1);
}
int query(int p,int l=0,int r=maxn-1,int o=1)
{
	if(l==r)return (_set[o]==-1 ? 0 : _set[o])^tg[o];
	push_down(o);
	int m=(l+r)>>1;
	if(p<=m)return query(p,l,m,o<<1);
	else return query(p,m+1,r,o<<1|1);
}
int main()
{
	int n,q;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<(maxn<<2);i++)_set[i]=-1;
	while(q--)
	{
		char c[2];scanf("%s",c);
		int x;scanf("%d",&x);
		if(c[0]=='>' && x>=0)
		{
			Set(abs(x)+1,maxn-1,3);
		}
		else if(c[0]=='>' && x<0)
		{
			flip(0,abs(x)-1);
			Set(abs(x),maxn-1,3);
		}
		else if(c[0]=='<' && x>0)
		{
			flip(0,abs(x)-1);
			Set(abs(x),maxn-1,2);
		}
		else 
		{
			Set(abs(x)+1,maxn-1,2);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int w=query(abs(a[i]));
//		printf("%d ",w);
		int ans;
		if(w==0)ans=a[i];
		else if(w==1)ans=-a[i];
		else if(w==2)ans=abs(a[i]);
		else ans=-abs(a[i]);
		printf("%d ",ans);
	}
	puts("");
	return 0;
}
