#include<cstdio>
#include<algorithm>
using namespace std;

main()
{
    int n,d,r,afternoon[105],night[105];
    while(scanf("%d%d%d",&n,&d,&r)==3 && (n||d||r))
    {
        for(int i=0;i<n;i++)scanf("%d",&afternoon[i]);
        for(int i=0;i<n;i++)scanf("%d",&night[i]);
        sort(afternoon,afternoon+n);sort(night,night+n);

        int ans=0;
        for(int i=0;i<n;i++)//¤j°t¤p
            if(afternoon[i]+night[n-i-1]>d)ans+=(afternoon[i]+night[n-i-1]-d)*r;
        printf("%d\n",ans);
    }
    return 0;
}
