# Number Sequence（KMP板子）

### 题目链接：[HDU - 1711 ](https://vjudge.net/problem/18357/origin) 



```c++
#include<stdio.h>
#include<string.h>
int a[1000005],b[10005],next[10005];
int m,n;
void get_next(int *t,int *next)
{
	int i=0,j=-1;
	next[0]=-1;
	while(i<n)
	{
		if(j==-1||t[i]==t[j])
		{
			i++;
			j++;
			next[i]=j;
		}
		else
		j=next[j];
	}
}
int index_kmp(int *s,int *t,int pos)
{
	int i=pos,j=0;
	while(i<m&&j<n)
	{
		if(j==-1||s[i]==t[j])
		{
			i++;
			j++;
			
		}
		else{
			j=next[j];
		}
	}
	if(j>=n)
	return i-n+1;
	else
	return -1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		get_next(b,next);
		printf("%d\n",index_kmp(a,b,0));
	}
 } 
```

