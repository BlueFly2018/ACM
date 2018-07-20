# B. Polycarp's Practice

### 题目链接：http://codeforces.com/contest/1006/problem/B  

### 题目要求：

#### 给你n个数分成k组（不能破坏顺序），输出每组最大值之和，与每个组的数量

### 解题思路：

#### 将n个数从大到小排序，题目要求最大之和，肯定是新序列的前k个之和；

#### 每组的个数可以开始的时候就记录每个数的位置，每一组都一最大的这个数结尾；注意最后一组要加上最大数的后面的数；

### 代码：

```c++
#include<bits/stdc++.h>

using namespace std;
struct node{
	int value;
	int seat;
}a[2020];
int b[2020];
int cmp(node a,node b)
{
	if(a.value==b.value)
	return a.seat>b.seat;
	return a.value>b.value;
}
int main()
{
	int n,k;
	cin>>n>>k;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i].value;
		a[i].seat=i;
	}
	
	sort(a,a+n,cmp);
	int sum=0;
	for(int i=0;i<k;i++)
	{
		b[i]=a[i].seat;
		sum+=a[i].value;
	}
	sort(b,b+k);
	cout<<sum<<endl;
	for(int i=0;i<k;i++)
	{	
		if(k==1)	//只有一组
		cout<<n-b[i-1]<<" ";
		else
		if(i==0)	//第一组
		cout<<b[i]+1<<" ";
		else
		if(i==k-1)	//最后一组
		cout<<n-1-b[i-1]<<" ";
		else		//中间的组
		
		cout<<b[i]-b[i-1]<<" ";
	}
	return 0;
}
```

