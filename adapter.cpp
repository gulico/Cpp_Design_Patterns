/**
 * 适配器模型
 * 例子：
 * 仿生机器人 
 * 现需要设计一个可以模拟各种动物行为的机器人，
 * 在机器人中定义了一系列方法，如机器人叫喊方法cry()、机器人移动方法move()等。
 * 如果希望在不修改已有代码的基础上使得机器人能够像狗一样叫，像狗一样跑，
 * 使用适配器模式进行系统设计
 * output:
 * wang wang wang
 * run like a dog
 * **/

#include<iostream>
using namespace std;

class Robot{//target目标抽象类
public:
    virtual void cry(){};
    virtual void move(){};
    virtual ~Robot(){};
};

class dog{//适配者类
public:
    void wang(){
        cout<<"wang wang wang"<<endl;
    }
    void run(){
        cout<<"run like a dog"<<endl;
    }
};

class adapter:public Robot{
private:
    dog* m_dog;
public:
    adapter(dog* newdog){
        this->m_dog = newdog;
    }
    void cry(){
        m_dog->wang();
    }
    void move(){
        m_dog->run();
    }
};

int main(){
    dog* d = new dog();
    Robot* r = new adapter(d);
    r->cry();
    r->move();

    delete d;
    delete r;
    return 0;
}