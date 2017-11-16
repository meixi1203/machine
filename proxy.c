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
