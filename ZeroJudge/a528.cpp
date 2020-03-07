#include<bits/stdc++.h>
using namespace std;
struct p
{
	int n;
	char s[110];
};
bool cmp(p a,p b)
{
	if(a.n<b.n)return 1;
	if(a.n>b.n)return 0;
	int len=a.n;
	if(len>0)
    {
        for(int i=0;i<len;i++)
        {
            if(a.s[i]<b.s[i])return 1;
            if(a.s[i]>b.s[i])return 0;
        }
    }
	else
    {
        len=abs(len);
        for(int i=1;i<len;i++)
        {
            if(a.s[i]<b.s[i])return 0;
            if(a.s[i]>b.s[i])return 1;
        }
    }
	return 1;
}
p a[1010];
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s",a[i].s);
			int len=strlen(a[i].s);
			a[i].n=(a[i].s[0]=='-') ? -len : len;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		{
			printf("%s\n",a[i].s);
		}
	}
	return 0;
}
