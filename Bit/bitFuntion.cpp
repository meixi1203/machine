//�����Ƶ����
#if 0
#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;
int main()
{
	unsigned int  a =1;//unsigned int ����СֵΪ0
	bitset<32>bit(-a);
	
     cout << bit<<endl;
	return 0;
}
#endif
#if 0
#include<stdio.h>
//����N!�Ķ����Ʊ�ʾ���λ1��λ��
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
// ���������ķ����ж�һ���������Ƿ���2�ķ���
//ֻ���ж�n & (n-1)�Ľ���Ƿ�Ϊ0���ж��Ƿ���2�ķ���

int judge(int n)  
{  
	return n&(n-1)==0 ? 1:0;  
}  
//�ж�һ�����ǻ�������ż��*************************
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
/*��������Ψһ�ظ���Ԫ�� һ�������к���1001��Ԫ�أ������1,2,3
...1000��һ���ظ�������ֻ��Ψһһ�������ظ��ģ�������ֻ����һ�Ρ�
Ҫ�����һ���㷨�ҳ�����ظ�������Ҫ��ÿ������Ԫ��ֻ�ܷ���һ�Σ�
���ø����洢�ռ䡣
�ⷨһ��
��򵥵ķ����ǣ������1...1000�ĺͣ��ù�ʽ��n(n+1)/2��sum1��
Ȼ�����arr[0]...arr[1000]�ĺ�sum2����sum2-sum1������Ҫ��Ľ����
�÷���ֻ�ñ�������һ�μ��ɡ�
�ⷨ����
������bit-map���Ƚ�bit-map����λ���Ϊ1��Ȼ������ѭ��һ�飬
���ν�ÿ��Ԫ�ض���bit-map�������ӦλΪ0������Ϊ1�������ӦλΪ1
�����������Ҫ��Ľ�����÷���Ҳֻ�ñ�������һ�Ρ����ǣ���Ŀ��Ҫ��
�ø����洢�ռ䣬������ʹ����bit-mapΪ�����洢�ռ䣬��Ȼ������Ҫ��	�����÷�����˼���ǲ���ġ����ҵ�������ķ�Χ�ǳ���ʱ���ýⷨһ������
��ʱ���ܻ���������ýⷨȴ�ǲ����ѡ��
�ⷨ����
������ʵ��ú�˵˵�ⷨ�����÷����������Ͽ����ģ����ú�����Ҳͦ����˼��
���������ҷ���һ�¡���Ҫ�����˹�ʽ��a ^ b ^ a = b���������£�	  
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
//��������1�ĸ���
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
int CountTwo(int n)//Ч�ʽϵ�
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
int CountThree( int n)//Ч�����
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
//32λ��������X�ж��ٸ���0000 0000 0000 0000 0000 0000 0000 1000
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
//�������
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
