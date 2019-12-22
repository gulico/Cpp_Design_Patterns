#include<iostream>
using namespace std;

class AbstractProtype{//抽象原型类
public:
//其他一些关键功能
    ~AbstractProtype(){};
    virtual AbstractProtype* clone(){};
    virtual void Print(){};
};

class ProtypeA:public AbstractProtype{//具体原型类
public:
    AbstractProtype* clone(){
        return new ProtypeA(*this);
    }
    void Print(){
        cout<<"这是具体原型A"<<endl;
    }
};

class ProtypeB:public AbstractProtype{
public:
    AbstractProtype* clone(){
        return new ProtypeB(*this);
    }
    void Print(){
        cout<<"这是具体原型B"<<endl;
    }
};

int main(){
    AbstractProtype* prototype = new ProtypeA();
    AbstractProtype* copy = prototype->clone();
    prototype->Print();
    copy->Print();
    delete prototype;
    delete copy;
    return 0;
}
