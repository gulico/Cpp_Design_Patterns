#include <iostream>
#include <mutex>
using namespace std;

mutex              g_mutex;     // 用到的全局锁

class lazySingleton{//懒汉式单例模式
private:
    lazySingleton(){};//私有构造函数
    static lazySingleton* instance;
public:
    lazySingleton* getInstance(){
        if(instance == NULL){
            instance = new lazySingleton();
        }
        return instance;
    }
};

class eagerSingleton{//饿汉式单例模式
private:
    eagerSingleton(){//私有构造函数
        instance = new eagerSingleton();
    };
    static eagerSingleton* instance;
public:
    eagerSingleton* getInstance(){
        if(instance == NULL){
            instance = new eagerSingleton();
        }
        return instance;
    }
};

//多线程，加锁
class multithreadLazySingleton{//懒汉式单例模式
private:
    multithreadLazySingleton(){};//私有构造函数
    static multithreadLazySingleton* instance;
public:
    multithreadLazySingleton* getInstance(){
        if(instance == NULL){
            lock_guard<std::mutex> lock(g_mutex);      // 加锁，离开{}作用域后锁释放
            if(instance == NULL){
                instance = new multithreadLazySingleton();
            }
        }
        return instance;
    }
};