//直接定义静态对象
/*
单例类定义的时候就进行实例化。
因为main函数执行之前，
全局作用域的类成员静态变量m_Instance已经初始化，
故没有多线程的问题。
*/
/*
优点：
实现简单，多线程安全。
缺点：
a. 如果存在多个单例对象且这几个单例对象相互依赖，
可能会出现程序崩溃的危险。
原因:
对编译器来说，
静态成员变量的初始化顺序和析构顺序是一个未定义的行为;
具体分析在懒汉模式中也讲到了。
b. 在程序开始时，就创建类的实例，
如果Singleton对象产生很昂贵，而本身有很少使用，
这种方式单从资源利用效率的角度来讲，比懒汉式单例类稍差些。
但从反应时间角度来讲，则比懒汉式单例类稍好些。

使用条件：
a. 当肯定不会有构造和析构依赖关系的情况。
b. 想避免频繁加锁时的性能消耗
*/
//代码实例（线程安全）
//.h文件
class Singleton
{
public:
  static Singleton& GetInstance();
private:
  Singleton(){}
  Singleton(const Singleton&);
  Singleton& operator= (const Singleton&);
private:
  static Singleton m_Instance;
};
//CPP文件
Singleton Singleton::m_Instance;//类外定义-不要忘记写
Singleton& Singleton::GetInstance()
{
   return m_Instance;
}
//函数调用
Singleton& instance = Singleton::GetInstance();