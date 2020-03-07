#include <iostream>
#include <cstdio>
#define MAX 200010
using namespace std;
int p[MAX],q[MAX];
int main(){
	int t,n,sum,s,cnt=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",p+i);
			p[i+n]=p[i];//擴大兩倍，不用求餘數
		}
		for(int i=1;i<=n;i++){
			scanf("%d",q+i);
			q[i+n]=q[i];//擴大兩倍，不用求餘數
		}
		bool success=false;
		for(int i=1;i<=n;i++){
			s=i;
			sum=0;
			while(i<s+n){
				sum+=p[i];
				sum-=q[i];
				if (sum<0) {//無法完成
					s=i;//起點更新
					break;
				}
				i++;
			}
			if((i-s)==n) {//已經完成n個站
				success=true;
				break;
			}
		}
		if (success){
			printf("Case %d: Possible from station %d\n",cnt++,s);
		}else{
			printf("Case %d: Not possible\n",cnt++);
		}
	}
}
