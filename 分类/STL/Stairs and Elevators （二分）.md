# Stairs and Elevators （二分）

### 题目链接：http://codeforces.com/problemset/problem/967/C

### 题目大意：有n*m的酒店  ，有 cl 个楼梯 ，有ce个电梯,电梯的最大速度是v，其他的速度都是 1，楼梯和电梯都是按顺序输入，q次询问，（x1,y1）到(x2,y2)的时间最少是多少？



### 思路：

### 当两个点在一层时，直接计算距离；

### 不在一层时：利用二分找到离起点最近的两个楼梯或电梯  选择时间最少的那一个。

### 代码：

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+10;
const int INF = 0x3f3f3f3f;
int l[maxn];
int e[maxn];
int main()
{
	int n,m,cl,ce,v;
	scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v); 
	
	for(int i=0;i<cl;i++)
	{
		scanf("%d",&l[i]);
	}
	
	for(int i=0;i<ce;i++)
	{
		scanf("%d",&e[i]);
	}
	
	int q;
	scanf("%d",&q);
	int sx,sy,ex,ey;
	while(q--)
	{
		scanf("%d%d%d%d",&sy,&sx,&ey,&ex);	//注意输入的顺序
		
		if(sy == ey) //再同一层
		{
			printf("%d\n",abs(sx-ex));
		}
		else
		{
			int ans = INF;
			
			int t;
			
			t = lower_bound(l, l+cl, sx) - l;
			
			if( t < cl) ans = min(ans , abs(sx-l[t]) + abs(ex-l[t]) + abs(ey-sy));
			
			if( t > 0) ans = min(ans , abs(sx-l[t-1]) + abs(ex-l[t-1]) + abs(ey-sy));
			
			t= lower_bound(e, e+ce, sx) - e;
			
			if(t < ce) ans = min(ans , abs(sx-e[t]) + abs(ex-e[t]) + (abs(ey-sy)+v-1)/v );
			
			if(t > 0) ans = min(ans , abs(sx-e[t-1]) + abs(ex-e[t-1]) + (abs(ey-sy)+v-1)/v );
			printf("%d\n",ans);
		}
		
	}

}

```



### 