# A. Romaji

> A. Romaji
>
> time limit per test
>
> memory limit per test
>
> input
>
> output
>
> Vitya has just started learning Berlanese language. It is known that Berlanese uses the Latin alphabet. Vowel letters are "a", "o", "u", "i", and "e". Other letters are consonant.
>
> In  Berlanese, there has to be a vowel after every consonant, but there can  be any letter after any vowel. The only exception is a consonant "n"; after this letter, there can be any letter (not only a vowel) or there can be no letter at all. For example, the words "harakiri", "yupie", "man", and "nbo" are Berlanese while the words "horse", "king", "my", and "nz" are not.
>
> Help Vitya find out if a word s
>
>  is Berlanese.
>
> Input
>
> The first line of the input contains the string s
>
> |s|
>
> 1≤|s|≤100
>
> ) lowercase Latin letters.
>
> Output
>
> Print "YES" (without quotes) if there is a vowel after every consonant except "n", otherwise print "NO".
>
> You can print each letter in any case (upper or lower).
>
> Examples
>
> input
>
> ```
> sumimasen
> ```
>
> output
>
> ```
> YES
> ```
>
> input
>
> ```
> ninja
> ```
>
> output
>
> ```
> YES
> ```
>
> input
>
> ```
> codeforces
> ```
>
> output
>
> ```
> NO
> ```
>
> Note
>
> In the first and second samples, a vowel goes after each consonant except "n", so the word is Berlanese.
>
> In the third sample, the consonant "c" goes after the consonant "r", and the consonant "s" stands on the end, so the word is not Berlanese.
>
>   
>
> 题意：Berlanese 语言 有一个规律 辅音字母后面必须是一个元音字母，但是  n    除外；
>
> 例如："harakiri", "yupie", "man" 都是berlanese 语言  ；
>
> 元音字母有："a","e","i","o","u"
>
> 题解：水题 ，直接模拟一下就好
>
> 原题链接：http://codeforces.com/contest/1008/problem/A











```c++
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	
	string c="aouien";
	
	cin>>s;
	
	int flag=1;
	
	int slen=s.size();
	
	for(int i=0;i<slen;i++)
	{
		int flag1=0;
		for(int j=0;j<6;j++)  //是否是元音或 n
		{
			if(s[i]==c[j])
			{
				flag1=1;
				break;
			}
			
		}
		
		if(flag1==0)
		{
			i++;
			int flag2=0;
			for(int j=0;j<5;j++)//是否是元音
			{
				if(s[i]==c[j])
				{
					flag2=1;
					break;
				}
				
			}
			if(flag2==0)
			{
				flag=0;
				break;
			}
		}
	}
	if(flag)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	return 0;
 } 
```

