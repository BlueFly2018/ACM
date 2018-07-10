# A. Unimodal Array



> ### A. Unimodal Array
>
> time limit per test：1 second
> memory limit per test：256 megabytes
> input：standard input
>
> output：standard output





> Array of integers is unimodal, if:
>
> -  it is strictly increasing in the beginning; 
> -  after that it is constant; 
> -  after that it is strictly decreasing. 
>
> The first block (increasing) and the last block (decreasing) may be absent. It is allowed that both of this blocks are absent.
>
> For example, the following three arrays are unimodal: [5, 7, 11, 11, 2, 1], [4, 4, 2], [7], but the following three are not unimodal: [5, 5, 6, 6, 1], [1, 2, 1, 2], [4, 5, 5, 6].
>
> Write a program that checks if an array is unimodal.
>
> Input
>
> The first line contains integer *n* (1 ≤ *n* ≤ 100) — the number of elements in the array.
>
> The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 1 000) — the elements of the array.
>
> Output
>
> Print "YES" if the given array is unimodal. Otherwise, print "NO".
>
> You can output each letter in any case (upper or lower).
>
> Examples
>
> Copy
>
> ```
> 6
> 1 5 5 5 4 2
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
> 5
> 10 20 30 20 10
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
> 4
> 1 2 1 2
> ```
>
> Copy
>
> ```
> NO
> ```
>
> Copy
>
> ```
> 7
> 3 3 3 3 3 3 3
> ```
>
> Copy
>
> ```
> YES
> ```
>
> Note
>
> In the first example the array is unimodal, because it is strictly increasing in the beginning (from position 1 to position 2, inclusively), that it is constant (from position 2 to position 4, inclusively) and then it is strictly decreasing (from position 4 to position 6, inclusively).
>
>   
>
> 大体意思就是给你一组数，这组数是否符合：前半部分严格单调递增，后半部分严格单调递减，可以只存在递增或递减的情况；
>
> 原题链接：http://codeforces.com/contest/831/problem/A

```c++
#include<stdio.h>
int a[150];
int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int flag=1;
	
	
	int i=0;
	while(a[i]<a[i+1])//判断递增
	i++;
	
	while(a[i]==a[i+1])//判断中间相等的部分；
	i++;
	
	for(;i<n-1;i++)//判断递减
	{
		if(a[i+1]>=a[i])
		{
			flag=0;
			break;
		}
	}
	
	if(flag==0)
	{
		printf("NO\n");
	}
	else
	printf("YES\n");
	
	
	return 0;
	
 } 
```

