//二进制的输出
#if 0
#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;
int main()
{
	unsigned int  a =1;//unsigned int 的最小值为0
	bitset<32>bit(-a);
	
     cout << bit<<endl;
	return 0;
}
#endif
#if 0
#include<stdio.h>
//求算N!的二进制表示最低位1的位置
int location(int n)  
{  
	int low=0;  
	while(n)  
	{  
		low+=n>>1;  
		n>>=1;  
	}  
	return low;  
}
// 用最简便最快的方法判断一个正整数是否是2的方幂
//只需判断n & (n-1)的结果是否为0来判断是否是2的方幂

int judge(int n)  
{  
	return n&(n-1)==0 ? 1:0;  
}  
//判断一个数是基数还是偶数*************************
int Judge(int a)
{
	return a & 0x1;
} 
void main()
{
	int a=5;
	printf("%d\n",location(a));
	printf("%d\n",judge(a));
	printf("%d\n",Judge(a));
}
#endif
#if 0
#include <stdio.h>
/*求数组中唯一重复的元素 一个数组中含有1001个元素，存放了1,2,3
...1000和一个重复的数。只有唯一一个数是重复的，其它均只出现一次。
要求设计一个算法找出这个重复的数，要求：每个数组元素只能访问一次，
不用辅助存储空间。
解法一：
最简单的方法是，先求出1...1000的和（用公式：n(n+1)/2）sum1，
然后求出arr[0]...arr[1000]的和sum2，（sum2-sum1）便是要求的结果。
该方法只用遍历数组一次即可。
解法二：
可以用bit-map，先将bit-map所有位标记为1，然后将数组循环一遍，
依次将每个元素读入bit-map，如果对应位为0，则标记为1，如果对应位为1
，则该数便是要求的结果。该方法也只用遍历数组一次。但是，题目中要求不
用辅助存储空间，而这里使用了bit-map为辅助存储空间，显然不符合要求，	不过该方法的思想是不错的。而且当该数组的范围非常大时，用解法一进行求
和时可能会溢出，而该解法却是不错的选择。
解法三：
本文其实想好好说说解法三，该方法是在网上看到的，觉得很巧妙也挺有意思，
在这里跟大家分享一下。主要利用了公式：a ^ b ^ a = b。代码如下：	  
*/
int findRepeat( int arr[], int len) 
{ 
	int res = arr[0];
	for (int i = 1; i < len; i++) 
	{ 
		res ^= i; 
		res ^= arr[i]; 
	} 
	return res; 
} 
int main() 
{ 
	int arr[3] = {1, 2, 1}; 
	printf("The repeat number is : %d\n",findRepeat(arr, 3));
	return 0; 
} 
#endif
//二进制中1的个数
#if  0
#include<stdio.h>
int CountOne(int n)
{
	int count=0;
	while(n!=0)
	{
		count+=n & 0x001;
		n=n>>1;
	}
	return count;
}
int CountTwo(int n)//效率较低
{
	int count=0;
	while(n!=0)
	{
		if (n%2 == 1)
		{
			count++;
		}
		n=n/2;
	}
	return count;
}
int CountThree( int n)//效率最高
{
	int count=1;
	while(n=n & n-1)
	{
		
		count++;	
	}
	return count;
}
int main()
{
	int i=0;
	//scanf("%d",&i);
	printf("%d\n",CountThree(8));

}
#endif
//32位二进制数X有多少个零0000 0000 0000 0000 0000 0000 0000 1000
#if 0
#include <stdio.h>
int fun(unsigned int x)
{
	int n=0;
	while((x+1))
	{
		n++;
		x=x|(x+1);
	}
	return n;
}
void main()
{
	printf("%d\n",fun(8));

	int k=100;
	printf("%d",k&0xf) ;
}
#endif
//两数相加
#if 0
#include <iostream>
using namespace  std;
int Add(int num1, int num2)
{
	int carry=0;
	int sum=0;
   	while (num2)
	{	
		
		sum=num1^num2;
		carry=(num1&num2)<<1;
		num1=sum;
		num2=carry;
	} 
   return num1;
}
void main()
{
	cout << Add(16,16) <<endl;
}

#endif
