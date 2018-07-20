# A. Adjacent Replacements

### 题目链接：http://codeforces.com/contest/1006/problem/A  

### 解题思路：

#### 水题，把奇数不变，偶数减一加好了；

### 代码：

```c++
#include<stdio.h>
#include<iostream>
using namespace std;
int a[1010];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		if(a[i]&1)
		cout<<a[i]<<" ";
		else
		cout<<a[i]-1<<" ";	
	}	
		
 } 
```

