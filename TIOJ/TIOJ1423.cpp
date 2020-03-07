#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< int, int > pii;
typedef vector< pii > vp;

int N;
vp A;

void init()
{
    cin>>N;
    A=vp(N);
    for(int i=0;i<N;i++)
        cin>>A[i].first>>A[ i ].second;
}

void solve()
{
    int ans=0;
    for(int i=0;i<N;i++)
    { // ay + bx + c = f
        for(int j=i+1;j<N;j++)
        {
            int a=A[j].first-A[i].first;
            int b=-(A[j].second-A[i].second);
            int c=-(a*A[i].second+b*A[i].first);
            int pcnt=0,ncnt=0;
            for(int u=0;u<N;u++)
                if(u!=i && u!=j)
                {
                    int f=a*A[u].second+b*A[u].first+c;
                    if(f>0)pcnt++;
                    if(f<0)ncnt++;
                }
            ans+=pcnt*ncnt;
        }
    }
    cout<<ans<<endl;
}

main()
{
    ios::sync_with_stdio( false );
    init();
    solve();
    return 0;
}
