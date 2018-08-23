# Counting Arrays 

### 题目链接：http://codeforces.com/problemset/problem/893/E



### 题目大意：输入两个数 x ， y；把 x 的因子分成y个使得![img](https://odzkskevi.qnssl.com/80df1f0ecd58b93b3fdbc85be98e77e5?v=1533519768)成立.



### 思路：质因子分解 ；

#### 因为 X 的因子都可以由 x 的质因子相乘得到，所以这道题就转换成，质因子的分配问题；

#### 即：对于每个质因子，它有 k 个，把它分到y个位置的方案数t。又因为有n个质因子，把它们的方案数都乘起来即可。



#### 把K个球，放到y个不同的盒子里，允许放空的盒子；

#### 公式：C(k+y-1,y-1)；

##### 为什么公式是这样的呢？

##### 先考虑：把k个球,放到y 个不同盒子，不允许空盒子存在；有多少种情况呢？

##### 利用隔板法：把k个球分成y分，需要y-1个隔板 ，而k个球有k-1个空隙，所以 情况为：C(k-1,y-1);

##### 再回到允许空盒子存在的情况：首先我们假设先在每个盒子里放一个球，然后再往任意盒中放n个球，在这个前提下，问题就转化为共有(n+m)个球，要放到m个盒子中，不允许空盒的方案数，即C(n+m-1,m-1)。 ，

#### 因为这道题中可以允许负数的存在，所以要在一个数里选取偶数个数变为负数

**答案还要乘以C(y,0)+C(y,2)+C(y,4)+C(y,6)+...                              ③**

**这个问题是初中组合数的一个经典问题，**

**设(1+x)^y=C(y,0)*x^0+C(y,1)*x^1+...+C(y,y-1)*x^(y-1)+C(y,y)*x^y**

**当x=1时，C(y,0)+C(y,1)+...+C(y,y-1)+C(y,y)=2^y                       ①**

**当x=-1时，C(y,0)-C(y,1)+C(y,2)-C(y-3)+...=0                             ②**

**①+②=2*③**

**③式为2^(y-1)**





### 代码：

```c++
//注意：ll  和  int 的使用  因为精度的缺失会导致wa




#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int  mod = 1e9+7;			//注意是int

ll quick(ll n,ll k)
{
	ll ret=1;
	while(k)
	{
		if(k&1)
		{
			ret=ret*n%mod;
		}
		k>>=1;
		n=n*n%mod;
	}
	
	return ret;
}

ll C(ll a,ll b)
{
	ll c=min(a-b,b);
	
	ll A=1,B=1;
	for(ll i=1;i<=c;i++)
	{
		A=A*(a-i+1)%mod;
		B=B*i%mod;
	}
	
	ll B2=quick(B,mod-2);
	
	return (A*B2)%mod;
	
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		
		vector<int >vec;
		
		for(int i=2;i*i<=x;i++)
		{
			if(x%i==0)
			{
				int num=0;
				
				while(x%i==0)
				{
					num++;
					x/=i;
				}
				vec.push_back(num);
			}
		}
		if(x>1) vec.push_back(1);//x>1说明x是质数 
		int l=vec.size();
		ll ans=1;
		for(int i=0;i<l;i++)
		{
			ans=ans*C(y-1+vec[i],y-1)%mod;
		}
		
		ans=ans*quick(2,y-1)%mod;	//算上负的 
		

		
		printf("%lld\n",ans);
	 } 
	
}
```



​                         