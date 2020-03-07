#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100000],n;
int Sum(int k)
{
    int sum=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=k;i++)
    sum+=a[n-i+1];
    return sum;
}
int cmp(int b,int c)
{
    if(abs(b)!=abs(c))
        return abs(b)>abs(c);
    else
        return b>c;
}

int main()
{
    int k;
    while(scanf("%d %d",&n,&k)!=EOF&&n+k)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1,cmp);
        int flag=0,sum=0,p=0,q=0,tot=0;
        for(int i=1;i<=k;i++)
        {
            if(a[i]==0)
            {
                flag=1;
                break;
            }
        else if(a[i]<0)
        {
            tot++;
            q=a[i];
        }
        else
        {
            p=a[i];
        }
        sum+=a[i];
        }

        if(flag==1)
            printf("%d\n",Sum(k));
        else if(tot%2)
        {
            int x=0,y=0,te0=0;
            for(int i=k+1;i<=n;i++)
            {
                if(a[i]>0)
                {
                    x=a[i];
                    break;
                }
            }
            for(int i=k+1;i<=n;i++)
            {
                if(a[i]<0)
                {
                    y=a[i];
                    break;
                    }
                }
                for(int i=k+1;i<=n;i++)
                {
                    if(a[i]==0)
                    {
                        te0=a[i];
                        break;
                    }
                }
                if(p==0)
                {
                    if(x)
                        printf("%d\n",sum-q+x);
                    else
                        printf("%d\n",Sum(k));
                }
                else
                {
                    if (x == 0 && y == 0) sum = Sum(k);
                    else if (x == 0) sum = sum - p + y;
                    else if (y == 0) sum = sum - q + x;
                    else if (x * p >= y * q) sum = sum - q + x;
                    else sum = sum - p + y;
                    printf("%d\n",sum);
                }
            }
            else
                printf("%d\n",sum);
        }
        return 0;
}
