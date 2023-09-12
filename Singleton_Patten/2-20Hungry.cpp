//静态指针 + 类外初始化时new空间实现
//代码实例（线程安全）
class Singleton
{
protected:
    Singleton(){}
private:
    static Singleton* p;
public:
    static Singleton* initance();
};
Singleton* Singleton::p = new Singleton;
Singleton* Singleton::initance()
{
    return p;
}