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
  bool operator<(const node& mynode) const{//���Fpriority queue
    return (mynode.time < time);
  }
}Node;
deque<Node> G[MAX];
int main(){
  int ncase=1,n,m,start,target,x,y,a,b,t,ans;
  while(scanf("%d",&n)==1){
  	scanf("%d%d%d",&m,&start,&target);
    memset(v,0,sizeof(v));//v[]��0��ܥ����X�L�Av[]��1��ܤw���X
    for(int i=1;i<=n;i++) G[i].clear();
    priority_queue<Node> pq;
		for(int j=0;j<m;j++){
    	scanf("%d%d%d%d%d",&x,&y,&a,&b,&t);
			if (a>=t) G[x].push_back(Node(y,a,b,t));       //a<t�A����N���ݥ[�J�Ax->y
    }
    Node mynode=Node(start,0,0,0);	//�_�l�I
    mynode.time=0;
    pq.push(mynode);
    while(!pq.empty()){
      mynode=pq.top();
      pq.pop();
      if (v[mynode.y]) continue;		//�w���X�L���A���X
      v[mynode.y]=1;		//�]���w�g���X
			if (mynode.y == target) {		//��F�ت��a
      	ans=mynode.time;
      	break;
			}
      for(int i=0;i<G[mynode.y].size();i++){		//Dijkstra�t��k
        Node tmp=G[mynode.y][i];
        if ((((mynode.time)%(tmp.a+tmp.b))>=0)&&(((mynode.time)%(tmp.a+tmp.b))<=(tmp.a-tmp.t))){//�ӱo�ΡA��F�ɶ��b�g��0��tmp.a-tmp.t����
          if (tmp.time > (mynode.time+tmp.t)) tmp.time=mynode.time+tmp.t;		//�ɶ���u�N��s
				}else{		//�Ӥ���
					if (tmp.time > mynode.time+(tmp.a+tmp.b)-mynode.time%(tmp.a+tmp.b)+tmp.t) //mynode.time+(tmp.a+tmp.b)-mynode.time%(tmp.a+tmp.b)�U�@�өP�����}�Y�A�ɶ���u�N��s�A
						tmp.time=mynode.time+(tmp.a+tmp.b)-mynode.time%(tmp.a+tmp.b)+tmp.t;
				}
				pq.push(tmp);
	  	}
    }
    printf("Case %d: %d\n",ncase++,ans);
  }
}
*/
