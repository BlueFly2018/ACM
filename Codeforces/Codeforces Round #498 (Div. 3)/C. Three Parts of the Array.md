# C. Three Parts of the Array

### 题目链接：http://codeforces.com/contest/1006/problem/C  

### 题目要求：给你n个数，让你分成三组（顺序不变），一个组可以没有数，使得第一组和第三组和相等；问你第一组最大值是多少？



### 题目思路：1,3两个组每次给比较小的那一个组添加一个数，当相等时更新 最大和就好，顺便给其中一个组添加一个数，继续循环，直到n个数用完；

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
int a[202020];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long sum1=a[0],sum3=a[n-1];
	int l=0,r=0;
	long long sum=0;
	while(l+r<n-1)
	{
		if(sum1==sum3)
		{
			sum=sum1;
			l++;
			sum1+=a[l]; 
		}
		
		
		if(sum1>sum3)
		{
			r++;
			sum3+=a[n-1-r];
		 } 
		 
		 if(sum1<sum3)
		{
			l++;
			sum1+=a[l];
		}
		
	}
	cout<<sum<<endl;
	return 0;
 } 
```

