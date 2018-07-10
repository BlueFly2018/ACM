# B. Keyboard Layouts 

> #### B. Keyboard Layouts
>
> #### time limit per test：1 second 
>
> #### memory limit per test：256 megabytes 
>
> #### input
>
> #### output



> There  are two popular keyboard layouts in Berland, they differ only in  letters positions. All the other keys are the same. In Berland they use  alphabet with 26 letters which coincides with English alphabet.
>
> You are given two strings consisting of 26 distinct letters each: all keys of the first and the second layouts in the same order. 
>
> You  are also given some text consisting of small and capital English  letters and digits. It is known that it was typed in the first layout,  but the writer intended to type it in the second layout. Print the text  if the same keys were pressed in the second layout.
>
> Since all keys  but letters are the same in both layouts, the capitalization of the  letters should remain the same, as well as all other characters.
>
> Input
>
> The first line contains a string of length 26 consisting of distinct lowercase English letters. This is the first layout.
>
> The second line contains a string of length 26 consisting of distinct lowercase English letters. This is the second layout.
>
> The third line contains a non-empty string *s* consisting of lowercase and uppercase English letters and digits. This is the text typed in the first layout. The length of *s* does not exceed 1000.
>
> Output
>
> Print the text if the same keys were pressed in the second layout.
>
> Examples
>
> Copy
>
> ```
> qwertyuiopasdfghjklzxcvbnm
> veamhjsgqocnrbfxdtwkylupzi
> TwccpQZAvb2017
> ```
>
> Copy
>
> ```
> HelloVKCup2017
> ```
>
> Copy
>
> ```
> mnbvcxzlkjhgfdsapoiuytrewq
> asdfghjklqwertyuiopzxcvbnm
> 7abaCABAABAcaba7
> ```
>
> Copy
>
> ```
> 7uduGUDUUDUgudu7
> ```

题意：

给你两组26个字母；再给你一组无序的字符串 （按照第二组），输出第一组的对应的字符串，，没有对应的直接输出



```c++
//qwertyuiopasdfghjklzxcvbnm
//veamhjsgqocnrbfxdtwkylupzi
//TwccpQZAvb2017
//HelloVKCup2017
#include<stdio.h>
#include<string.h>
char a[50];
char b[50];

int main()
{
	char c[1500];
	scanf("%s%s",a,b);
	scanf("%s",&c);
	int t[50];//用来标记两组的对应关系
	for(int i=0;i<26;i++)
	{
		t[a[i]-'a']=b[i]-a[i];//对应的关系
	}
	int l=strlen(c);
	
//	printf("%d????\n",l);
	for(int i=0;i<l;i++)
	{
		if(('A'<=c[i]&&'Z'>=c[i]))
		{
			printf("%c",c[i]+t[c[i]-'A']);
			continue;
		}
		if(('a'<=c[i]&&'z'>=c[i]))
		{
			printf("%c",c[i]+t[c[i]-'a']);
			continue;
		}
		
		printf("%c",c[i]);
	}
	
	printf("\n");
	return 0;
}

```







