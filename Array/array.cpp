/////////
#if 0
#include <stdio.h>
#include <string.h>
	void main()
{
	char arr[] = {4, 3, 9, 9, 2, 0, 1, 5};
	char *str = arr;
	printf("%d,%d,%d\n",sizeof(arr),sizeof(str),strlen(str) );
	// 数字0 会转成字符，就是'\0' 
}

#endif
//求子数组和的最大值
#if 0
#include <iostream>
using namespace std;  
int maxSubSum(int *array, int length) 
{  
	int nAll = array[length -1];  
	int nStart = array[length-1];  
	int i;  
	for( i = length-2; i>=0; i--) 
	{  
		if(nStart < 0)  
		{
			nStart = 0;  
		}
		nStart += array[i];  
		if(nStart > nAll) //若当前子数组之和大于nAll，则更新nAll  
		{
			nAll = nStart;  
		}
	}  
	return nAll;  
}  
int Max(int a,int b)
{
	return a>b?a:b;
}
//求子数组的最大值
void ChildSun(int *a,int n)
{
	int i=0;
	int temp=0;
	int maxsum=0;
	for (i; i<n; i++)
	{
		if (temp+a[i]< 0)
		{
			temp=0;
		}
		else
		{
			temp+=a[i];
			maxsum=Max(temp,maxsum);
		}
	}
	printf("Max sub sum = %d\n",maxsum);
}
int main()
{  
	int a[7] = {-2,5,3,-6,4,-8,6};  
	int maxSub = maxSubSum(a,7);  
	printf("Max sub sum = %d\n",maxSub);  
	ChildSun(a,7);
}  
#endif 
#if 0
#include <stdio.h>
//递归求数组元素之和
int SumArry(int *a,int n)
{
	return n==0 ? 0:SumArry(a,n-1)+a[n-1];
}
//求两个数组中的公共元素
void Comm(int *a,int *b,int n)
{
	int i=0;
	int k=0;
	while (i<n && k<n)
	{
		if (a[i]<b[k])
		{
			i++;
		}
		else if (a[i]==b[k])
		{	
			printf("%d\n",a[i]);
			i++;
			k++;
		} 
		else
		{
			k++;
		}
	}
}
//求两个数组中满足给定和的数对，即对a中元素i和b中元素j，满足i + j = d(d已知)
void FixedSum(int *a,int *b,int n,int d)
{
	int i=0;
	int k=n-1;
	while (i<n && k>=0)
	{
		if (a[i]+b[k]<d)
		{
			i++;
		}
		else if (a[i]+b[k]==d)
		{
			printf("%d+%d=d\n",a[i],b[k]);
			i++;
			k--;
		} 
		else
		{
			k--;
		}

	}
}///////////////////////////////////////////////////////
//子数组的最大乘积
int Max(int a,int b)
{
	return a>b ? a:b;
}
int Min(int a,int b)
{
	return a<b ? a:b;

}
void FixedMul(int *a,int n)
{
	int maxium=1;
	int minium=1;
	int temp=1;
	int k=0;
	int i=0;
	for (; i<n; i++)
	{
		if (a[i]>0)
		{
			maxium*=a[i];
			minium=Min(minium*a[i],1);
		}
		else if (a[i]==0)
		{
			maxium=1;
			minium=1;
		}
		else
		{
			temp=maxium;
			maxium=Max(minium*a[i],1);
			minium*=a[i];
		}
		k=Max(maxium,k);
	}
	printf("子数组的最大乘积为：%d\n",k);

}
///////////////////////////////////////////////////////
//就地逆序数组
void Reverse1(int *a,int n)
{
	int left=0;
	int right=n-1;
	int temp=0;
	int i=0;
	while(left<right)
	{
		temp=a[left];
		a[left++]=a[right];
		a[right--]=temp;
	}
	for (;i<n; i++)
	{
		printf("%d,",a[i]);
	}
}
///////////////////////////////////////////////////
//将buffer中start和end之间的元素逆序
void Reverse( int buffer[], int start, int end )
{
	int temp=0;
	while ( start < end )
	{
		temp = buffer[ start ] ;
		buffer[ start++ ] = buffer[ end ] ;
		buffer[ end-- ] = temp ;
	}
}

// 将含有n个元素的数组buffer右移k位
void Shift( int buffer[], int n, int k )
{
	k %= n ;

	Reverse( buffer, 0, n - k - 1) ;
	Reverse( buffer, n - k, n - 1 ) ;
	Reverse( buffer, 0, n - 1 ) ;

}
///////////////////////////////////////////////////////////
//快速找出一个数组中的最大数、第二大数。
void GetSecondMaxNumber(int *arr , int n)  
{  
	int i , max , second_max;  
	max = arr[0];  
	second_max = 0x80000000;  
	for(i = 1 ; i < n ; ++i)  
	{  
		if(arr[i] > max)  
		{  
			second_max = max;  
			max = arr[i];  
		}  
		else  
		{  
			if(arr[i] > second_max)  
				second_max = arr[i];  
		}  
	}  
	printf("max=%d,second_max=%d\n",max,second_max)  ;
}  
//求数组中两个元素差的最大值
void  max_difference(int *arr , int n)  
{  	  
	if(arr == NULL || n < 2)    // 非法输入  
		return ;  
	int max = arr[0];  
	int maxDiff = arr[0] - arr[1]; 
	int i;
	
	for( i = 2 ; i < n ; ++i)  
	{  
		if(arr[i-1] > max)  
			max = arr[i-1];  
		if(max - arr[i] > maxDiff)  
			maxDiff = max - arr[i];  
	}  
	printf("数组中两个元素差的最大值:%d\n",maxDiff);
}  
void main()
{
	int a[5]={1,2,-5,6,8};
	int b[5]={2,6,9,7,10};
	printf("数组个元素之和为：%d\n",SumArry(a,(sizeof(a)/sizeof(int))));
	printf("\\\\\\\\\\\\\\\\\\\n");
	Comm(a,b, 5);
	printf("\\\\\\\\\\\\\\\\\\\n");
	FixedSum(a,b,5,8);
	printf("\\\\\\\\\\\\\\\\\\\n");
	FixedMul(a,5);
	printf("\\\\\\\\\\\\\\\\\\\n");
	Reverse1(a,5);
	printf("\\\\\\\\\\\\\\\\\\\n");
	GetSecondMaxNumber(a , 5);
	printf("\\\\\\\\\\\\\\\\\\\n");
	max_difference(a,5);  
	Shift( a,5,2);
	printf("\\\\\\\\\\\\\\\\\\\n");
}
#endif
//有关数组内存大小
#if 0
#include<stdio.h>
void main () 
{
	int a[5]={1,2,3,4,5};
	int i,j,k,n,*p,*p1,*p2;
	i=sizeof(&a);
	j=sizeof(a);
	k=sizeof(&a+1);
	n=sizeof(a+1);
	p=a;
	p1=a+1;
	printf("%p,%p,%p\n",p1,p,p1-p);
	p=(int *)(&a);
	p1=(int *)(&a+1);
	printf("%p,%p,%p\n",p1,p,p1-p);
	printf("%d,%d,%d,%d\n",i,j,k,n);
	printf("%p,%p\n",&a,&a[0]);
}
#endif
///////先定义的变量地址大
//vc++6.0可以输出结果vs2012输出随机值
#if 0
#include<stdio.h>
void main()
{

	int a=0;
	int arr[5]={1,2,3,4,5};
	int b=6;
	printf("%d\n%d\n",arr[-1],arr[5]);	
}
#endif
