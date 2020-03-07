#include <stdio.h>
int main(){
    //freopen("in.txt","r",stdin);
    int n,i,j,x,num[100];
    while(scanf("%d",&n)!=EOF){
        if(!n)break;
        for(i=0;i<100;i++)num[i]=0;
        for(i=0;i<n;i++)scanf("%d",&x),num[x]++;
        for(i=0;i<100;i++)for(j=0;j<num[i];j++)printf("%d ",i);
        printf("\n");
    }
    return 0;
}
