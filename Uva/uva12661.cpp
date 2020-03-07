#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 300+10
#define INF 100000000
int vis[maxn];
struct node
{
    int y,a,b,t;
    int time;
    node(int y1,int a1,int b1,int t1):y(y1),a(a1),b(b1),t(t1),time(INF) {}
    bool operator < (const node& rhs) const
    {
        return time<rhs.time;
    }
};
deque<node> G[maxn];
main()
{
    int cas=0,n,m,start,target,ans;
    while(scanf("%d",&n)==1)
    {
        scanf("%d%d%d",&m,&start,&target);
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)G[i].clear();
        priority_queue<node> pq;
        for(int j=0;j<m;j++)
        {
            int x,y,a,b,t;
            scanf("%d%d%d%d%d",&x,&y,&a,&b,&t);
            if(a>=t)G[x].push_back(node(y,a,b,t));
        }
        node Node=node(start,0,0,0);
        Node.time=0;
        pq.push(Node);
        while(!pq.empty())
        {
            Node=pq.top();pq.pop();
            if(vis[Node.y])continue;
            vis[Node.y]=1;
            if(Node.y==target)
            {
                ans=Node.time;
                break;
            }
            for(int i=0;i<G[Node.y].size();i++)
            {
                node tmp=G[Node.y][i];

                if( (Node.time)%(tmp.a+tmp.b)>=0 && (Node.time)%(tmp.a+tmp.b)<=(tmp.a-tmp.t) )
                    tmp.time=min(tmp.time,Node.time+tmp.t);

                else tmp.time=min(tmp.time,Node.time+(tmp.a+tmp.b)-Node.time%(tmp.a+tmp.b)+tmp.t);
                pq.push(tmp);
            }
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
/*
#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 310
#define INF 1<<30
using namespace std;
bool v[MAX];
typedef struct node{
  int y,a,b,t;
  int time;
  node(int y1,int a1,int b1,int t1):y(y1),a(a1),b(b1),t(t1),time(INF) {}
  bool operator<(const node& mynode) const{//為了priority queue
    return (mynode.time < time);
  }
}Node;
deque<Node> G[MAX];
int main(){
  int ncase=1,n,m,start,target,x,y,a,b,t,ans;
  while(scanf("%d",&n)==1){
  	scanf("%d%d%d",&m,&start,&target);
    memset(v,0,sizeof(v));//v[]為0表示未拜訪過，v[]為1表示已拜訪
    for(int i=1;i<=n;i++) G[i].clear();
    priority_queue<Node> pq;
		for(int j=0;j<m;j++){
    	scanf("%d%d%d%d%d",&x,&y,&a,&b,&t);
			if (a>=t) G[x].push_back(Node(y,a,b,t));       //a<t，此邊就不需加入，x->y
    }
    Node mynode=Node(start,0,0,0);	//起始點
    mynode.time=0;
    pq.push(mynode);
    while(!pq.empty()){
      mynode=pq.top();
      pq.pop();
      if (v[mynode.y]) continue;		//已拜訪過不再拜訪
      v[mynode.y]=1;		//設為已經拜訪
			if (mynode.y == target) {		//到達目的地
      	ans=mynode.time;
      	break;
			}
      for(int i=0;i<G[mynode.y].size();i++){		//Dijkstra演算法
        Node tmp=G[mynode.y][i];
        if ((((mynode.time)%(tmp.a+tmp.b))>=0)&&(((mynode.time)%(tmp.a+tmp.b))<=(tmp.a-tmp.t))){//來得及，到達時間在週期0到tmp.a-tmp.t之間
          if (tmp.time > (mynode.time+tmp.t)) tmp.time=mynode.time+tmp.t;		//時間更短就更新
				}else{		//來不及
					if (tmp.time > mynode.time+(tmp.a+tmp.b)-mynode.time%(tmp.a+tmp.b)+tmp.t) //mynode.time+(tmp.a+tmp.b)-mynode.time%(tmp.a+tmp.b)下一個周期的開頭，時間更短就更新，
						tmp.time=mynode.time+(tmp.a+tmp.b)-mynode.time%(tmp.a+tmp.b)+tmp.t;
				}
				pq.push(tmp);
	  	}
    }
    printf("Case %d: %d\n",ncase++,ans);
  }
}
*/
