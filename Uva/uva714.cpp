#include <cstdio>
#include <algorithm>
#include<cstring>
using namespace std;

int ans[501][501],p[501],n[501];

main()
{
    int t,m,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&k);
        long long int Min=0,Max=0,mid;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&p[i]);
            if(p[i]>Min)Min=p[i];
            Max+=p[i];
        }
        while(Min<Max)
        {
            int amount=1;
            long long int sum=0;
            mid=(Max+Min)/2;
            for(int i=0;i<m;i++)
            {
                if(sum+p[i]>mid){amount++;sum=0;}
                sum+=p[i];
            }
            if(amount>k)Min=mid+1;
            else Max=mid;
        }
        memset(n,0,sizeof(n));
        long long int sum=0;
        for(int i=m-1,j=k-1;i>=0;i--)
        {  // i: book index, j: scriber index
            if (sum+p[i]>Max || j>i)
            {     // j>i: 因為每個人都至少要有一本書
                j--;
                sum = 0;
            }
            sum+=p[i];
            ans[j][n[j]++]=p[i];
        }
        for (int i=0; i<k; i++){
            for (int j=n[i]-1; j>=0; j--){
                if (i!=0 || j!=n[0]-1) printf(" ");
                printf("%d",ans[i][j]);
            }
            if (i != k-1) printf(" /");
        }
        printf("\n");
    }
    return 0;
}
