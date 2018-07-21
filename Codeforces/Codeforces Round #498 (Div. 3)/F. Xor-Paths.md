# F. Xor-Paths 

### 题目链接：http://codeforces.com/contest/1006/problem/F

### 题目要求：

#### 给你一个n*m的 二维数组，从左上角到右下角的路线中，有多少条路线是 路线上每个 点的 与非值（^）是k的；

### 解题思路：

#### 	x^y=k;可以变化为 x^k=y

#### 	因为20*20的如果暴力输出的话，会超时

#### 	所以可以把这个二维数组按 x+y=max(x,y) 这条线分成 两部分计		算，时间可以减少到原来的开根号倍； 

#### 	  前半部分 从开始到 a[x][y]  的 ^值为 s的路有t条，后半部分  从终点到  a[x][y]  的与k的^值 为s的路有l条；总路线次数  加上 t*l;

####  	把一个点的特殊情况 另外写出来；一个点不能分成两部分 







### 代码：

```c++
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

	
ll a[25][25];
map<ll,ll> v[25][25];
int n,m;
int MAX;
ll ans;
void dfs1(int x,int y,ll s)
{
	s^=a[x][y];
	if(x+y==MAX)
	{
		v[x][y][s]++;
		return;
	}
	
	
	
	if(x+1<=n) dfs1(x+1,y,s);
	if(y+1<=m) dfs1(x,y+1,s);
}

void dfs2(int x,int y,ll s)
{
	if(x+y==MAX)
	{
					
		ans+=v[x][y][s];
		return ;
	}
	s^=a[x][y];
	if(x-1>=1) dfs2(x-1,y,s);
	if(y-1>=1) dfs2(x,y-1,s);
}

int main()
{
	
	ll k;
	cin>>n>>m;
	cin>>k;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>a[i][j]; 
	
	
	if(n==1&&m==1)
	{
		if(a[n][m]==k)
		cout<<"1"<<endl;
		else
		cout<<"0"<<endl;
	 } 
	 else
	 {
		MAX=max(n,m);
		
		dfs1(1,1,0);
	//	cout<<"??"<<endl;
		dfs2(n,m,k);
		
		cout<<ans<<endl;
	 }

 } 
```

