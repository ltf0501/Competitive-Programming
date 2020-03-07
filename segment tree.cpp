#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int mx[maxn*3],a[maxn];
void push_up(int id)
{
    mx[id]=max(mx[id<<1],mx[id<<1|1]);
}
void update(int l,int r,int id,int p,int x)//��a[p]�令x
{
    if(l==r)//��ܰ϶����u�Ѥ@�Ӽ�,�����ק�
    {
        mx[id]=x;
        return ;
    }
    int m=(l+r)>>1;//m=(l+r)/2
    if(p<=m)update(l,m,id<<1,p,x);//�Ya[p]�b�϶�[l,m]���h�b[l,m]�ק�
    else update(m+1,r,id<<1|1,p,x);//�_�h�b[m+1,r]�ק�
    push_up(id);//��s���϶������e
}
int query(int l,int r,int id,int ql,int qr)//�d��[ql,qr]���̤j��
{
    if(ql<=l && r<=qr)return mx[id];//�ثe�϶������]�t�b�d�߰϶��� ������^
    int m=(l+r)>>1;
    int ans=0;
    if(ql<=m)ans=max(ans,query(l,m,id<<1,ql,qr));//ql<=m��ܬd�߰϶����@�����b�ثe�϶����b�� ���j���o�����̤j��
    if(m<qr)ans=max(ans,query(m+1,r,id<<1|1,ql,qr));//�P�W
    return ans;
}
void init()
{
    memset(mx,0,sizeof(mx));
}
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1;i<=n;i++)//�إ߽u�q��
        {
            scanf("%d",&a[i]);
            update(1,n,1,i,a[i]);
        }
        int q;scanf("%d",&q);
        while(q--)
        {
            int c,x,y;scanf("%d%d%d",&c,&x,&y);
            if(c==1)
            {
                update(1,n,1,x,y);//�b[1,n]���ק�a[x]=y
            }
            else
            {
                printf("%d\n",query(1,n,1,x,y));//�b[1,n]�����a[x]~a[y]�̤j��
            }
        }
    }
    return 0;
}
/*
Practice 1
�Ц��p update �M query������
Practice 2
�Ч�إ߽u�q��ɶ��令O(n)
Practice 3
�令�d�߰϶��M
*/
