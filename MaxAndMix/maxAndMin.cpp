//一次遍历求最小值与次小值
#if 0
#include <iostream>
using namespace std;
void Fun(int array[],int n)
{

	int Min=array[0];
	int Min_Sec=array[1];
	for (int i=1; i<n; i++)
	{
		if (Min>array[i])
		{
			Min_Sec=Min;
			Min=array[i];
		}
		else if (Min_Sec>array[i])
		{
			Min_Sec=array[i];
		}
		
	}
	cout << "Min: "<<Min<<endl;
	cout << "Min_Sec "<<Min_Sec<<endl;
}
void main()
{
	int array[]={3,5,8,2,10,9};
	Fun(array,sizeof(array)/sizeof(array[0]));

}
#endif
//一次遍历求最大值与次大值
#if 0
#include <iostream>
using namespace std;

void Fun(int array[],int n)
{

	int Max=array[0];
	int Max_Sec=array[1];
	for (int i=1; i<n; i++)
	{
		if (Max<array[i])
		{
			Max_Sec=Max;
			Max=array[i];
		}
		else if (Max_Sec<array[i])
		{
			Max_Sec=array[i];
		}
		
	}
	cout << "Max: "<<Max<<endl;
	cout << "Max_Sec "<<Max_Sec<<endl;
}

void main()
{
	int array[]={3,5,8,2,10,9};
	Fun(array,sizeof(array)/sizeof(array[0]));
		
}
#endif
#if 0
#include<iostream>
using namespace std;
int  i=0;
int Fun(int i)
{
	static int a=2;
	a++;
	return i+a;
}
void main()
{
	int k=5;
	{
	   int i=2;
	   k+=Fun(i);

	}
	k+=Fun(i);
	cout << k << endl;
	
}
#endif
#if 0
#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SYSTEM_INFO  sysInfo;
	OSVERSIONINFOEX osvi;
	
	GetSystemInfo(&sysInfo);
	
	printf("OemId : %u\n", sysInfo.dwOemId);
	printf("处理器架构 : %u\n", sysInfo.wProcessorArchitecture);
	printf("页面大小 : %u\n", sysInfo.dwPageSize);
	printf("应用程序最小地址 : %u\n", sysInfo.lpMinimumApplicationAddress);
	printf("应用程序最大地址 : %u\n", sysInfo.lpMaximumApplicationAddress);
	printf("处理器掩码 : %u\n", sysInfo.dwActiveProcessorMask);
	printf("处理器数量 : %u\n", sysInfo.dwNumberOfProcessors);
	printf("处理器类型 : %u\n", sysInfo.dwProcessorType);
	printf("虚拟内存分配粒度 : %u\n", sysInfo.dwAllocationGranularity);
	printf("处理器级别 : %u\n", sysInfo.wProcessorLevel);
	printf("处理器版本 : %u\n", sysInfo.wProcessorRevision);
	
	/*osvi.dwOSVersionInfoSize=sizeof(osvi);
	if (GetVersionEx((LPOSVERSIONINFOW)&osvi))
	{
		printf("Version     : %u.%u\n", osvi.dwMajorVersion, osvi.dwMinorVersion);
		printf("Build       : %u\n", osvi.dwBuildNumber);
		printf("Service Pack: %u.%u\n", osvi.wServicePackMajor, osvi.wServicePackMinor);
	}*/
	return 0;   
}
 /*int 1main()
{
	int a=1;
	int b=2;
	int c=a++++b;
	cout<<c<<endl;
	return 0;
}
*/
#endif
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
class print
{
	public:
	
		void operator()(const T& elem)
		{
			cout << elem << " ";
		}
		
		
};
void  main()
{
	int ia[6]={1,2,3,4,5,6};
	vector<int> iv(ia,ia+6);
	for_each(iv.begin(),iv.end(),print<int>());
}
#endif
#if 0
#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;


void  main()
{
	int ia[6]={1,2,3,4,5,6};
	queue<int, list<int> >iv;
	iv.push(1);
	iv.push(2);
	iv.push(3);
	while (!iv.empty())
	{
		cout << iv.size() << " ";
		iv.pop();
		cout<<	iv.front()<<endl;
	
	}

}
#endif
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void  main()
{
	int ia[9]={0,1,2,3,4,8,9,3,5};
	vector<int>ivec(ia,ia+9);
	make_heap(ivec.begin(),ivec.end());
	
	for (int i=0; i<ivec.size(); i++)
	{
		cout << ivec[i] << " ";
	}
	cout<<endl;
	ivec.push_back(7);
	push_heap(ivec.begin(),ivec.end());
	for ( i=0; i<ivec.size(); i++)
	{
		cout << ivec[i] << " "; 
	}
    cout<<endl;
	pop_heap(ivec.begin(),ivec.end());
	cout << ivec.back() << endl;
	ivec.pop_back();
	for ( i=0; i<ivec.size(); i++)
	{
		cout << ivec[i] << " ";
	}
    cout<<endl;
	sort_heap(ivec.begin(),ivec.end());
	for ( i=0; i<ivec.size(); i++)
	{
		cout << ivec[i] << " ";
	}
    cout<<endl;
		
}
#endif
#if 0
#include <iostream>
#include <queue>
#include <algorithm>
using namespace  std;
int main()
{
    int ia[9]={0,1,2,3,4,8,9,3,5};
	priority_queue <int>ipq(ia,ia+9);
	cout <<ipq.size()<< endl;
    while (!ipq.empty())
    {
		cout << ipq.top()<<endl;
		ipq.pop();
    }
	return 0;

}
#endif


#if 0
#include <iostream>
#include <set>
#include <algorithm>
using namespace  std;
int main()
{
    int ia[]={0,1,2,3,4};
	set<int> iset(ia,ia+5);
	cout << iset.size()<<" "<<iset.count(3)<<endl;
	set<int>::iterator iter=iset.begin();
	iter=find(iset.begin(),iset.end(),4);
	if (iter!=iset.end())
	{
		cout << "Yes"<<endl;
	}
	set<int>::iterator iter1;
    iter1=iset.find(4);
	if (iter1!=iset.end())
	{
		cout << "Yes"<<endl;
	}

    return 0;
	
}
#endif
#if 0
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace  std;
int main()
{
   map<string,int>simap;
   simap[string("meixi")]=1;
   simap[string("jerry")]=2;
   simap[string("jason")]=3;
   simap[string("jimmy")]=4;
   pair<string,int> ispair("davida",5);
   simap.insert(ispair);
   map<string,int>::iterator iter=simap.begin();
   for (; iter!=simap.end();iter++)
   {
	   cout<<iter->first<<" "<<iter->second<<endl;
   }
    return 0;
	
}
#endif





