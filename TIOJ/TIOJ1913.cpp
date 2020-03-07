#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
#define maxn 10000+5
#define INF 10000000
int a[maxn],b[maxn],c[maxn],ml[maxn],mr[maxn];
stack<int> S;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        memset(c,0,sizeof(c));
        int n;scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++){scanf("%d",&a[i]);b[i]=a[i]-i+n;}
        a[0]=INF;a[n+1]=-INF;
        for(int i=1;i<=n+1;i++)
        {
            while(!S.empty() && a[S.top()]>a[i])
            {
                mr[S.top()]=i;
                S.pop();
            }
            if(a[i]>a[i+1])mr[i]=i+1;
            else S.push(i);
        }
        for(int i=n;i>=0;i--)
        {
            while(!S.empty() && a[S.top()]<a[i])
            {
                ml[S.top()]=i;
                S.pop();
            }
            if(i && a[i]<a[i-1])ml[i]=i-1;
            else S.push(i);
        }
        /*
        for(int i=1;i<=n;i++)printf("%d ",ml[i]);
        puts("");
        */
        stack<int> s[maxn*2];
        for(int i=0;i<=2*n;i++)s[i].push(0);
        for(int i=1;i<=n;i++)
        {
            stack<int>& S=s[b[i]];
            while(ml[i]<S.top() && mr[S.top()]<i)S.pop();
            if(ml[i]<S.top())c[i]=c[S.top()]+1;
            S.push(i);
        }
        for(int i=1;i<=n;i++){sum+=c[i];}

        for(int i=1;i<=n;i++)b[i]=a[n+1-i];
        for(int i=1;i<=n;i++)a[i]=b[i];
        for(int i=1;i<=n;i++)b[i]=a[i]-i+n;
        a[0]=INF;a[n+1]=-INF;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n+1;i++)
        {
            while(!S.empty() && a[S.top()]>a[i])
            {
                mr[S.top()]=i;
                S.pop();
            }
            if(a[i]>a[i+1])mr[i]=i+1;
            else S.push(i);
        }
        for(int i=n;i>=0;i--)
        {
            while(!S.empty() && a[S.top()]<a[i])
            {
                ml[S.top()]=i;
                S.pop();
            }
            if(i && a[i]<a[i-1])ml[i]=i-1;
            else S.push(i);
        }
        /*
        for(int i=1;i<=n;i++)printf("%d ",ml[i]);
        puts("");
        */
        for(int i=0;i<=2*n;i++)if(!s[i].empty())s[i].pop();
        for(int i=0;i<=2*n;i++)s[i].push(0);
        for(int i=1;i<=n;i++)
        {
            stack<int>& S=s[b[i]];
            while(ml[i]<S.top() && mr[S.top()]<i)S.pop();
            if(ml[i]<S.top())c[i]=c[S.top()]+1;
            S.push(i);
        }
        for(int i=1;i<=n;i++){sum+=c[i];}
        printf("%d\n",sum);

    }
    return 0;
}
