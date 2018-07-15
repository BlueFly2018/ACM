# B. Turn the Rectangles 

> B. Turn the Rectangles
>
> time limit per test
>
> memory limit per test
>
> input
>
> output
>
> There are n
>
> 90
>
>   degrees or leave it as it is. If you turn a rectangle, its width will  be height, and its height will be width. Notice that you can turn any  number of rectangles, you also can turn all or none of them. You can not change the order of the rectangles.
>
> Find  out if there is a way to make the rectangles go in order of  non-ascending height. In other words, after all the turns, a height of  every rectangle has to be not greater than the height of the previous  rectangle (if it is such). 
>
> Input
>
> The first line contains a single integer n
>
> 1≤n≤105
>
> ) — the number of rectangles.
>
> Each of the next n
>
> wi
>
> hi
>
> 1≤wi,hi≤109
>
> i
>
> -th rectangle.
>
> Output
>
> Print "YES" (without quotes) if there is a way to make the rectangles go in order of non-ascending height, otherwise print "NO".
>
> You can print each letter in any case (upper or lower).
>
> Examples
>
> Copy
>
> ```
> 3
> 3 4
> 4 6
> 3 5
> ```
>
> Copy
>
> ```
> YES
> ```
>
> Copy
>
> ```
> 2
> 3 4
> 5 5
> ```
>
> Copy
>
> ```
> NO
> ```
>
> Note
>
> In the first test, you can rotate the second and the third rectangles so that the heights will be [4, 4, 3].
>
> In the second test, there is no way the second rectangle will be not higher than the first one.
>
>   题意：给你  n  个矩形  这些矩形可以旋转 但是顺序不能改变，问你这些矩形的高度是否可以
>
> 以非递增的顺序排列(后面的高度不大于前面的高度)；
>
> 题解：贪心  每次都选符合题意中最大的做为高度
>
> 原题链接：http://codeforces.com/contest/1008/problem/B

```c++

#include<bits/stdc++.h>
using namespace std;
	int a[100100],b[100100];
int main()
{
	int n;
	
	cin>>n;
	int flag=1;
	long long m= 10000000000 ;
	for(int i=0;i<n;i++)
	{
	
		cin>>a[i]>>b[i];
			
			if(a[i]>b[i])
			{
				int t=a[i];
				a[i]=b[i];
				b[i]=t;
			}
	}	
	
	for(int i=0;i<n;i++)
	{
		if(m>=b[i])
		{
			m=b[i];
		}
		else
		if(m>=a[i])
		{
			m=a[i];
		}
		else
		{
			flag=0;
			break;
		}
	}
	
	if(flag==0)
	cout<<"NO"<<endl;
	else
	cout<<"YES"<<endl;
	return 0;
}
```



# 

# 

# 