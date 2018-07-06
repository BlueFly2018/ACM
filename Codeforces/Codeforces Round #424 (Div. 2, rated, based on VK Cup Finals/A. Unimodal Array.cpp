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
	while(a[i]<a[i+1])
	i++;
	
	while(a[i]==a[i+1])
	i++;
	
	for(;i<n-1;i++)
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
