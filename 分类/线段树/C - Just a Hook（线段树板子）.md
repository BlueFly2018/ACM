# [C - Just a Hook](https://vjudge.net/problem/HDU-1698)（线段树板子）

### 题目链接：[HDU - 1698 ](https://vjudge.net/problem/15763/origin) 

​                         

```c++
#include<stdio.h>
#include<string.h>
#define MAXN 100000+10
#define ll long long
ll tree[MAXN<<2];
ll vis[MAXN<<2];

void build(int l,int r,int rt)
{
	if(l==r)
	{
		tree[rt]=1;
		return;
	}
	int mid=(r+l)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void down(int l,int r,int rt)
{
	if(vis[rt]!=0)
	{
		int mid=(r+l)>>1;
		vis[rt<<1]=vis[rt];
		vis[rt<<1|1]=vis[rt];
		
		tree[rt<<1]=(mid-l+1)*vis[rt];
		tree[rt<<1|1]=(r-mid)*vis[rt];
		vis[rt]=0;
	}
}
void update(int L,int R,int c,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		tree[rt]=(r-l+1)*c;
		vis[rt]=c;
		return;
	}
	down(l,r,rt);
	int mid=(r+l)>>1;
	if(mid>=L) update(L,R,c,l,mid,rt<<1);
	if(mid<R)  update(L,R,c,mid+1,r,rt<<1|1);
	
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}

ll query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		return tree[rt];
	}
	down(l,r,rt);
	int mid=(r+l)>>1;
	ll sum=0;
	if(mid>=L)  sum+=query(L,R,l,mid,rt<<1);
	if(mid<R) sum+=query(L,R,mid+1,r,rt<<1|1);
	
	return sum;
}
int main()
{
	int M;
	scanf("%d",&M);
	for(int i=1;i<=M;i++)
	{
		memset(vis,0,sizeof(vis));
		memset(tree,0,sizeof(tree));
		int N;
		scanf("%d",&N);
		build(1,N,1);
		int T;
		scanf("%d",&T);
		while(T--)
		{
			int m,n,t;
			scanf("%d%d%d",&m,&n,&t);
			
			update(m,n,t,1,N,1);
			}	
		printf("Case %d: The total value of the hook is %lld.\n",i,tree[1]);
	}
	return 0;
}


```

