//代码实例（线程安全）
/*
对于析构的顺序，
我们可以用一个容器来管理它，根据单例之间的依赖关系释放实例，
对所有的实例的析构顺序进行排序，之后调用各个单例实例的析构方法，
如果出现了循环依赖关系，就给出异常，并输出循环依赖环。
*/
#include <string>
#include <iostream>
using namespace std;
class Log
{
public:
    static Log* GetInstance()
    {
        static Log oLog;
        return &oLog;
    }

    void Output(string strLog)
    {
        cout<<strLog<<(*m_pInt)<<endl;
    }
private:
    Log():m_pInt(new int(3))
    {
    }
    ~Log()
    {cout<<"~Log"<<endl;
        delete m_pInt;
        m_pInt = NULL;
    }
    int* m_pInt;
};

class Context
{
public:
    static Context* GetInstance()
    {
        static Context oContext;
        return &oContext;
    }
    ~Context()
    {
        Log::GetInstance()->Output(__FUNCTION__);
    }

    void fun()
    {
        Log::GetInstance()->Output(__FUNCTION__);
    }
private:
    Context(){}
    Context(const Context& context);
};

int main(int argc, char* argv[])
{
    Context::GetInstance()->fun();
    return 0;
}