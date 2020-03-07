bool debug=false;
#include <stdio.h>
#include <utility>
#include <vector>
#include <bitset>
#include <stack>
using namespace std;
#define F first
#define S second
#define PB push_back
const int N=2e5+10;
const int INF=1e9+10;
bitset<N> used,went,con;
vector<pair<int,int>> graph[N];
int edge[N],ans,t=0,nd[N];
stack<pair<int,int>> s;
void dfs(int pos){
	if(went[pos]){
		while(s.top().F!=pos){
			edge[s.top().S]=t;
			s.pop();
		}
		edge[s.top().S]=t;
		s.pop();
		t++;
		return ;
	}
	went[pos]=true;
	for(pair<int,int> i:graph[pos])if(!used[i.S]){
		used[i.S]=true;
		s.push({pos,i.S});
		dfs(i.F);
	}
	return ;
}
void dfs2(int pos,int ring,int need){
	if(debug)printf("dfs2(%d,%d,%d)\n",pos,ring,need);
	if(need)nd[pos]=need;
	if(went[pos])return ;
	went[pos]=true;
	if(ring==-1)ring--;
	bool cost=false;
	for(pair<int,int> i:graph[pos])if(edge[i.S]!=ring&&!used[i.S]){
		used[i.S]=true;
		dfs2(i.F,edge[i.S],0);
		if(!con[i.F])cost=true;
	}
	if(cost){
		if(debug)printf("true at %d so plus\n",pos);
		ans++;
		con[pos]=true;
		need=0;
	}
	else if(nd[pos]){
		if(debug)printf("need at %d so plus\n",pos);
		ans++;
		need=0;
		con[nd[pos]]=con[pos]=true;
	}
	else{
		if(debug)printf("false at %d\n",pos);
		need=pos;
	}
	if(ring!=-2){
		for(pair<int,int> i:graph[pos])if(edge[i.S]==ring&&!used[i.S]){
			used[i.S]=true;
			dfs2(i.F,edge[i.S],need);
		}
	}
	return ;
}
int main(){
	int l,r,n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&l,&r);
		graph[l].PB({r,i});
		graph[r].PB({l,i});
		edge[i]=-1;
	}
	for(int i=1;i<=n;i++)nd[i]=0;
	ans=0;
	used.reset();
	went.reset();
	dfs(1);
	if(debug){
		for(int i=1;i<=n;i++){
			for(pair<int,int> j:graph[i])printf("(%d,%d) ",j.F,edge[j.S]);
			printf("\n");
		}
	}
	used.reset();
	went.reset();
	con.reset();
	dfs2(1,-1,0);
	printf("%d\n",ans);
}
