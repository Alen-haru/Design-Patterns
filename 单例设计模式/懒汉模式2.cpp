//代码实例（线程不安全）
template<typename T>
class Singleton
{
public:
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