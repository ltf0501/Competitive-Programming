#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

#define ULL unsigned long long

using namespace std;

main()
{
    int N,i,j,cnt,r,l,m;
    ULL n,v;
    vector<ULL> num;

    while(scanf("%d",&N)!=EOF)
    {
        num.resize(N);
        for(i=0;i<N;i++)
        {
            scanf("%llu",&n);
            num[i]=n*n;
        }
        sort(num.begin(),num.end());

        for(i=cnt=0;i<N-2;i++)
            for(j=i+1;j<N-1;j++)
            {
                v=num[i]+num[j];
                l=j+1;r=N-1;
                while(l<r)
                {
                    m=(l+r)/2;
                    if(v<=num[m])
                        r=m;
                    else
                        l=m+1;
                }
                if(num[l]==v) cnt++;
            }
        printf("%d\n",cnt);
    }

    return 0;
}
