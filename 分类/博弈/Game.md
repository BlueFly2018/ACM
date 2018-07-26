# Game

### 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=6312

### 题意：

​	每一个人每次都会选择一个数删除，并且删除他的所有因数

​	谁最后无数可删，谁就输了；



### 代码：

```c++
#include<stdio.h>
/*
	因为1是所有数的因数，所以先手可以选择让自己一定赢得那个数，如果没有就选择1来改变状态；
	所以先手一定赢； 

*/
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Yes\n");
	 } 
 }
```

