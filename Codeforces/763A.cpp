#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#define F first
#define S second
#define mkp make_pair
using namespace std;
typedef pair<int,int> pii;
int deg[100005],c[100005];
pii e[100005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++) scanf("%d%d",&e[i].F,&e[i].S);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<n;i++) if(c[e[i].F]!=c[e[i].S])
        deg[e[i].F]++,deg[e[i].S]++;
    int cnt=0,ma=0,ans=0;
    for(int i=1;i<=n;i++){
        if(deg[i]) cnt++;
        if(deg[i]>=ma) ans=i,ma=deg[i];
    }
    if((cnt==0)||(cnt==ma+1)) printf("YES\n%d\n",ans);
    else printf("NO\n");
    return 0;
}
