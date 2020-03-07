#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100000+10
int ans,A[maxn],n;
void mrge(int *a,int L,int M,int R)
{
    int left,right,i,tmp[maxn];
    left=L;
    right=M+1;
    i=L;
    while(left<=M && right<=R)
    {
		if(a[left]<a[right])tmp[i++]=a[left++];
        else
        {
            ans+=M-left+1;
			tmp[i++]=a[right++];
		}
	}
	while(left<=M)tmp[i++]=a[left++];//若左邊還有剩，拷貝到tmp陣列
    while(right<=R)tmp[i++]=a[right++];//若右邊還有剩，拷貝到tmp陣列

	for(i=L;i<=R;i++)a[i]=tmp[i];//將陣列tmp複製到陣列a

}
void mrgesort(int *a,int L,int R)
{
    int M;
    if(L<R)
    {
        M=L+(R-L)/2;
        mrgesort(a,L,M);
        mrgesort(a,M+1,R);
        mrge(a,L,M,R);
    }
}

main()
{
    while(scanf("%d",&n)==1 && n)
    {
        ans=0;
        for(int i=0;i<n;i++) scanf("%d",&A[i]);
        mrgesort(A,0,n-1);
        if(ans&1)printf("Marcelo\n");
        else printf("Carlos\n");
    }
    return 0;
}
