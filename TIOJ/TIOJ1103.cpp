#include <bits/stdc++.h>
using namespace std;
#define modBASE 10000
#define N 10000

int graph[2][N + 10];
int val[N + 10];

int main(){
	int sz=0;
	for(int i=0;i<=N;i++)
		graph[0][i]=1;
	for(int i=1;i<=2*N;i++){
		if((i-1)%2==0)sz++;
		for(int j=0;j<=N;j++)
			graph[i%2][j]=0;
		for(int j=sz;j<=N;j++){
			graph[i%2][j]=graph[i%2][j-1];
			graph[i%2][j]%=modBASE;
			graph[i%2][j]+=graph[(i-1)%2][j];
			graph[i%2][j]%=modBASE;
			if(j*2==i)val[j]=graph[i%2][j];
		}
	}
	int n;
	scanf("%d",&n);
	while(n!=0){
		if(n>=8)
			printf("%04d\n",val[n]);
		else
			printf("%d\n",val[n]);
		scanf("%d",&n);
	}
	return 0;
}
