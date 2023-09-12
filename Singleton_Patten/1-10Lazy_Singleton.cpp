//静态指针 + 用到时初始化
//代码实例（线程不安全）
//破坏了唯一性
//内存泄漏
template<typename T>
class Singleton
{
public:
static T& getInstance()
{
    if (!value_)
    {
        value_ = new T();
    }
    return *value_;
}
private:
    Singleton();
    ~Singleton();
    static T* value_;
};
template<typename T>
T* Singleton<T>::value_ = NULL;