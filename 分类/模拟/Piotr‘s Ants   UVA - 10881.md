# Piotr‘s Ants   UVA - 10881

### 题目链接：https://vjudge.net/problem/UVA-10881



### 题目大意：一根长度为L厘米的木棍上有n只蚂蚁，每只蚂蚁要么向左爬，要么向右爬，速度为1 cm/s .当两只蚂蚁相撞时，二者同时掉头（点头时间忽略不计）。给出每只蚂蚁的初始位置和朝向，计算T秒后的每只蚂蚁地位置；



### 解题思路：有几点：

### 1.相撞可以看做是相互穿了过去；

### 2.每只蚂蚁的相对位置是一直不变的（就是这只蚂蚁从左向右数是第几只蚂蚁它一直就是第几只）；

### 3.所以直接模拟就好了；





### 代码：

```c++
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int M=10000+10;
struct Ant{
	int seat;
	string s;
	int v;
	int flag;//相撞
	int flag1;//掉下去
}a[M];

int cmp(Ant m,Ant n)
{
	return m.seat<n.seat;
}

int b[M];
int c[M];//记录蚂蚁的输入的顺序；
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=1;k<=T;k++)
	{
		int l,t,n;
		cin>>l>>t>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].seat>>a[i].s;
			
			a[i].v=i;
			a[i].flag=0;
			a[i].flag1=0;
			
		}
		
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		c[a[i].v]=i;
		
		for(int i=0;i<n;i++)
		{
			if(a[i].s=="R")
			{
				a[i].seat+=t;
				
			}
			if(a[i].s=="L")
			{
				a[i].seat-=t;
			}
		}
		sort(a,a+n,cmp);
		
		for(int i=0;i<n;i++)
		{
			if(a[i].seat < 0 || a[i].seat > l)
			{
				a[i].flag1=1;
				
			}
		}
		
		for(int i=0;i<n-1;i++)		//注意范围,小心RE
		{
			
			if(a[i].seat == a[i+1].seat)
			{
				a[i].flag=1;
				a[i+1].flag=1;
			}
			
			
		}
		

		printf("Case #%d:\n",k);
		for(int j=0;j<n;j++)
		{
			int i=c[j];
			if(a[i].flag1)
			printf("Fell off\n");
			else
			if(a[i].flag)
			printf("%d Turning\n",a[i].seat);
			else
			{
				cout<<a[i].seat<<" "<<a[i].s<<endl;
			}
		}
		cout<<endl;
	}
}
```



#### PS：这个就是一道模拟题，但是就是输出的时候，顺序一直不对；后来看ＡＣ代码，学会了用一个数组存储相对顺序；



