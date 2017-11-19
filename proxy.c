 <设计模式>
 举例：
   假若你有一个工厂开始是生产手机的，但是它现在不想自己生产了，它把自己的东西交给了一家代工厂富士康去生产，那么便有了下面的代码去构建。
统一的抽象接口 IFactory

class IFactory 
{ 
public: 
  IFactory(){} 
  virtual void makeProduct() = 0; 
}; 
你的手机工厂

class PhoneFactory : IFactory 
{ 
public: 
  PhoneFactory(){} 
  void makeProduct() 
  { 
    cout<<"生产手机"<<endl; 
  } 
}; 
专门做代工的代理工厂富士康

class FoxconnProxy : IFactory 
{ 
public: 
  FoxconnProxy(IFactory* factory) 
  { 
    m_real = factory; 
  } 
  void makeProduct() 
  { 
    m_real->makeProduct(); 
  } 
private: 
  IFactory* m_real; 
}; 
客户端：

IFactory* factory = new PhoneFactory(); 
FoxconnProxy* proxy = new FoxconnProxy(factory); 
proxy->makeProduct(); 


//这里给出一个C++中智能指针的例子，自己代码重新实现了下：
// TestProxy.cpp : Defines the entry point for the console application.  
//  
  
#include "stdafx.h"  
#include <assert.h>  
  
#define KSAFE_DELETE(p) \  
    if (p)           \  
        {                \  
        delete p;    \  
        p = NULL;    \  
        }  
  
class KRefCount  
{  
public:  
    KRefCount():m_nCount(0){}  
  
public:  
    void AddRef(){m_nCount++;}  
    int Release(){return --m_nCount;}  
    void Reset(){m_nCount=0;}  
  
private:  
    int m_nCount;  
};  
  
template <typename T>  
class KSmartPtr  
{  
public:  
    KSmartPtr(void)  
        : m_pData(NULL)  
    {  
        m_pReference = new KRefCount();  
        m_pReference->AddRef();  
    }  
    KSmartPtr(T* pValue)  
        : m_pData(pValue)  
    {  
        m_pReference = new KRefCount();  
        m_pReference->AddRef();  
    }  
    KSmartPtr(const KSmartPtr<T>& sp)  
        : m_pData(sp.m_pData)  
        , m_pReference(sp.m_pReference)  
    {  
        m_pReference->AddRef();  
    }  
    ~KSmartPtr(void)  
    {  
        if (m_pReference && m_pReference->Release() == 0)  
        {  
            KSAFE_DELETE(m_pData);  
            KSAFE_DELETE(m_pReference);  
        }  
    }  
  
    inline T& operator*()  
    {  
        return *m_pData;  
    }  
    inline T* operator->()  
    {  
        return m_pData;  
    }  
    KSmartPtr<T>& operator=(const KSmartPtr<T>& sp)  
    {  
        if (this != &sp)  
        {  
            if (m_pReference && m_pReference->Release() == 0)  
            {  
                KSAFE_DELETE(m_pData);  
                KSAFE_DELETE(m_pReference);  
            }  
  
            m_pData = sp.m_pData;  
            m_pReference = sp.m_pReference;  
            m_pReference->AddRef();  
        }  
  
        return *this;  
    }  
    KSmartPtr<T>& operator=(T* pValue)  
    {  
        if (m_pReference && m_pReference->Release() == 0)  
        {  
            KSAFE_DELETE(m_pData);  
            KSAFE_DELETE(m_pReference);  
        }  
        m_pData = pValue;  
        m_pReference = new KRefCount;  
        m_pReference->AddRef();  
  
        return *this;  
    }  
  
    T* Get()  
    {  
        T* ptr = NULL;          
        ptr = m_pData;  
  
        return ptr;  
    }  
    void Attach(T* pObject)  
    {  
        if (m_pReference->Release() == 0)  
        {  
            KSAFE_DELETE(m_pData);  
            KSAFE_DELETE(m_pReference);  
        }  
  
        m_pData = pObject;  
        m_pReference = new KRefCount;  
        m_pReference->AddRef();  
    }  
  
    T* Detach()  
    {  
        T* ptr = NULL;  
  
        if (m_pData)  
        {             
            ptr = m_pData;  
            m_pData = NULL;  
            m_pReference->Reset();  
        }  
        return ptr;  
    }  
  
private:  
    KRefCount* m_pReference;  
    T* m_pData;  
};  

与其他模式的区别

1)适配器模式Adapter
适配器Adapter为它所适配的对象提供了一个不同的接口。相反，代理提供了与它的实体相同的接口。然而，用于访问保护的代理可能会拒绝执行实体会执行的操作，因此，它的接口实际上可能只是实体接口的一个子集。
2) 装饰器模式Decorator
尽管Decorator的实现部分与代理相似，但Decorator的目的不一样。Decorator为对象添加一个或多个功能，而代理则控制对对象的访问。 
总结

在软件系统中，加一个中间层是我们常用的解决方法，这方面Proxy模式给了我们很好的实现。
