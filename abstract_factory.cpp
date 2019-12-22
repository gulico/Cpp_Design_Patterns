/** 
 * 抽象工厂模式
 * output:
 * ProductA1
 * ProductB1
 * ProductA2
 * ProductB2
 **/
#include<iostream>
using namespace std;

class AbstractProductA{//抽象产品A，比如冰箱
public:
    virtual ~AbstractProductA(){}
    virtual void operation() = 0;//=0是指形式上的作用，告诉编译系统“这是纯虚函数”
};

class AbstractProductB{//抽象产品B，比如电视
public:
    virtual ~AbstractProductB(){}
    virtual void operation() = 0;//=0是指形式上的作用，告诉编译系统“这是纯虚函数”
};

class ProductA1:public AbstractProductA{//具体产品A，由工厂1生产
public:
    void operation(){
        cout<<"ProductA1"<<endl;
    }
};

class ProductA2:public AbstractProductA{//具体产品A，由工厂2生产
public:
    void operation(){
        cout<<"ProductA2"<<endl;
    }
};

class ProductB1:public AbstractProductB{//具体产品B，由工厂1生产
public:
    void operation(){
        cout<<"ProductB1"<<endl;
    }
};

class ProductB2:public AbstractProductB{//具体产品B，由工厂2生产
public:
    void operation(){
        cout<<"ProductB2"<<endl;
    }
};

class AbstractFactory{//抽象工厂
public:
    virtual ~AbstractFactory(){}
    virtual AbstractProductA* createProductA() = 0;//生产产品a
    virtual AbstractProductB* createProductB() = 0;//生产产品b
};

class Factory1:public AbstractFactory{// 具体工厂1
public:
    AbstractProductA* createProductA(){
        return new ProductA1();
    }
    AbstractProductB* createProductB(){
        return new ProductB1();
    }
};

class Factory2:public AbstractFactory{// 具体工厂2
public:
    AbstractProductA* createProductA(){
        return new ProductA2();
    }
    AbstractProductB* createProductB(){
        return new ProductB2();
    }
};

int main(){
    AbstractFactory *f1 = new Factory1();
    AbstractFactory *f2 = new Factory2();
    AbstractProductA *pa1 = f1->createProductA();
    pa1->operation();
    AbstractProductB *pb1 = f1->createProductB();
    pb1->operation();
    AbstractProductA *pa2 = f2->createProductA();
    pa2->operation();
    AbstractProductB *pb2 = f2->createProductB();
    pb2->operation();

    delete pa1;
    delete pa2;
    delete pb1;
    delete pb2;
    delete f1;
    delete f2;
    return 0;
}


