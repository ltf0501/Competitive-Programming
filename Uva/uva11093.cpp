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
			p[i+n]=p[i];//�X�j�⭿�A���ΨD�l��
		}
		for(int i=1;i<=n;i++){
			scanf("%d",q+i);
			q[i+n]=q[i];//�X�j�⭿�A���ΨD�l��
		}
		bool success=false;
		for(int i=1;i<=n;i++){
			s=i;
			sum=0;
			while(i<s+n){
				sum+=p[i];
				sum-=q[i];
				if (sum<0) {//�L�k����
					s=i;//�_�I��s
					break;
				}
				i++;
			}
			if((i-s)==n) {//�w�g����n�ӯ�
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
