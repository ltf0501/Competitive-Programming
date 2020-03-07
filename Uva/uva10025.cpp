#include<bits/stdc++.h>
using namespace std;
main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
    {
		scanf("%d",&n);
		n=abs(n);
		int k;
		for(k=0; ;k++)
		{
			if(k*(k+1)/2>=n && (k*(k+1)/2-n)%2==0)
				break;
		}
		printf("%d\n",n==0?3:k);
		if(t)puts("");
	}
    return 0;
}
