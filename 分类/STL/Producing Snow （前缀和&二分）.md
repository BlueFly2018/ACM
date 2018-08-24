# Producing Snow （前缀和&二分）

### 题目链接：http://codeforces.com/problemset/problem/948/C

### 题目大意：有n 天，每天都会堆一堆雪，但是因为每天的温度不同，每一堆雪每天都会融化一部分，问你每天融化多少雪；

### 题目思路：利用前缀和把每天要融化的数量统计出来，然后看每一堆雪可以在哪一天全部融化，中间的天数融化的雪堆数+1；有的雪堆，最后一天不一定正好是融化的数量，所以用一个数组存储下来，最后答案加上就行；

## 骚操作：比如在 [r,l),中每天都要 +1；可以a[r]++,a[l]--;  最后利用前缀和就可以统计每天的具体数量sum[i] = sum[i-1] + a[i]；（这个减少了操作的数量）



### 代码：

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+10;
ll sum[maxn];	//每天融化的前缀和
ll V[maxn];		//每天堆的雪堆
ll T[maxn];		//每天融化的雪
ll vis[maxn];	//骚操作中的a[i]
ll v[maxn];		//每堆雪最后一天融化的数量
ll num[maxn];	//骚操作的sum[i],也是最终的结果

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&V[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&T[i]);
		sum[i] = sum[i-1] + T[i];
		
	}
	
	for(int i=1;i<=n;i++)
	{
		int t ;
		t = lower_bound(sum+i,sum+n+1,sum[i-1]+V[i]) - sum;
		
		v[t] += sum[i-1] + V[i] - sum[t-1];
		
		vis[i]++;	//第一天+1
		vis[t]--;	//最后一天-1
		 
		 
	}
	
	for(int i=1;i<=n;i++)//统计最终结果
	{
		num[i] = num[i-1] + vis[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		printf("%lld%c",num[i]*T[i]+v[i],i==n?'\n':' ');
	}

}

```

