# E. Military Problem 

### 题目链接：http://codeforces.com/contest/1006/problem/E

### 题目要求：给你 一棵树的n-1 个数 每个数代表  i+1的父节点，之后又有q 次操作，每次操作输入u，k ，代表以u为根节点的树按照深度遍历的方法，第k个数是什么？如果k超出树的节点树，输出“-1”；



### 解题思路：利用递归，把整棵树以深度遍历的方式存储在一个数组里；再利用一个数组记录num[i],以为根节点的树的节点数；



### 代码:

```c++
#include<bits/stdc++.h>

using namespace std;
int a[202020];
vector<int> tree[202020];
int b[202020];
int num[202020];
int ans=0;
int v[202020],s[202020];//按照题意每一个点肯定在一个固定的位置，用这两个数组记录一下； 
int dfs(int t)
{
	ans++;
	b[ans]=t;
	v[t]=ans;//位置在 t ,前面有 ans 个 点  
	s[ans]=t;//前面有 ans 个点，位置在t 
	num[t]=1;
	int l=tree[t].size();
	for(int i=0;i<l;i++)
	{
		num[t]+=dfs(tree[t][i]);
	}
	return num[t];
}
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		tree[a[i]].push_back(i);
	}
	dfs(1);
	while(q--)
	{
		int u,k;
		cin>>u>>k;
		if(k>num[u])
		cout<<"-1"<<endl;
		else
		cout<<s[v[u]+k-1]<<endl;
		/*不能用循环查找，会超时*/
//		for(int i=1;i<=n;i++)///
//		{
//			if(b[i]==u)
//			{
//				cout<<b[i+k-1]<<endl;
//				break;
//			}
//		}
	
		
		
	}

}
```

