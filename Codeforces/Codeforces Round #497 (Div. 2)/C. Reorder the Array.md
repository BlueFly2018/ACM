# C. Reorder the Array 

> C. Reorder the Array
>
> time limit per test
>
> memory limit per test
>
> input
>
> output
>
> You  are given an array of integers. Vasya can permute (change order) its  integers. He wants to do it so that as many as possible integers will  become on a place where a smaller integer used to stand. Help Vasya find  the maximal number of such integers.
>
> For instance, if we are given an array [10,20,30,40]
>
> [20,40,10,30]
>
> 20>10
>
> 40>20
>
> 2
>
> . Read the note for the first example, there is one more demonstrative test case.
>
> Help  Vasya to permute integers in such way that the number of positions in a  new array, where integers are greater than in the original one, is  maximal.
>
> Input
>
> The first line contains a single integer n
>
> 1≤n≤105
>
> ) — the length of the array.
>
> The second line contains n
>
> a1,a2,…,an
>
> 1≤ai≤109
>
> ) — the elements of the array.
>
> Output
>
> Print  a single integer — the maximal number of the array's elements which  after a permutation will stand on the position where a smaller element  stood in the initial array.
>
> Examples
>
> input
>
> ```
> 7
> 10 1 1 1 5 5 3
> ```
>
> output
>
> ```
> 4
> ```
>
> input
>
> ```
> 5
> 1 1 1 1 1
> ```
>
> output
>
> ```
> 0
> ```
>
> Note
>
> In the first sample, one of the best permutations is [1,5,5,3,10,1,1]
>
> . On the positions from second to fifth the elements became larger, so the answer for this permutation is 4.
>
> In the second sample, there is no way to increase any element with a permutation, so the answer is 0.
>
> 题意：给你 n  个数  ，这一组数没有顺序，你可以操作这一组数的顺序，最终得出这一组数中比
>
> 以前位置数大的有 X 个，问最多X为多少个；
>
> 思路：可以 先排序再利用贪心，算出有多少个
>
> 原题链接：http://codeforces.com/contest/1008/problem/C

```c++
#include<bits/stdc++.h>

using namespace std;
int a[100100];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	sort(a,a+n);
	int num=0,begin=0,end=0;//begin 第一排的位置， end第二排的位置
	while(end!=n)//当第二排移动到最后结束循环
	{
		if(a[end]>a[begin])  //找到一个符合题意的
		{
			num++;
			end++;
			begin++;
		}
		else
		{
			end++;		//没找到第二排的向后移动
		}
	}
	
	cout<<num<<endl;
	
	return 0;
}
```

