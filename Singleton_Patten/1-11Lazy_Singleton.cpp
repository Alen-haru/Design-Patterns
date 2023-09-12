//代码实例（线程安全）
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
     class CGarbo     
    {    
    public: 
        //删除单例的唯一实例   
        /*
        a. 在单例类内部定义专有的嵌套类；
        b. 在单例类内定义私有的专门用于释放的静态成员；
        c. 利用程序在结束时析构全局变量的特性，选择最终的释放时机。
        */
        ~CGarbo()    
        {    
            if(Singleton::value_)    
                delete Singleton::value_;    
        }    
    };    
    static CGarbo Garbo;    
    Singleton();
    ~Singleton();
    static T* value_;
};
template<typename T>
T* Singleton<T>::value_ = NULL;