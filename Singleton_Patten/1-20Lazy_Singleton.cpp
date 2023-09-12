//局部静态变量
//代码实例（线程不安全）
/*
如果存在多个单例对象的析构顺序有依赖时，可能会出现程序崩溃的危险。
原因：
由于静态成员是在第一次调用函数GetInstance时进行初始化，
调用构造函数的，因此构造函数的调用顺序时可以唯一确定了。
对于析构函数，我们只知道其调用顺序和构造函数的调用顺序相反，
但是如果几个Singleton类的析构函数之间也有依赖关系，
而且出现类似单例实例A的析构函数中使用了单例实例B，
但是程序析构时是先调用实例B的析构函数，
此时在A析构函数中使用B时就可能会崩溃。
*/
template<typename T>
class Singleton
{
public:
//不是原子操作
static T& getInstance() 
{
    static T instance;
    return instance;
}

private:
    Singleton(){};
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
};