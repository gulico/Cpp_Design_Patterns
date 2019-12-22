/** 
 * 工厂方法模式
 * output:
 * ProductA
 * ProductB
 **/
#include<iostream>
using namespace std;

class AbstractProduct{//抽象产品
public:
    virtual ~AbstractProduct(){}
    virtual void operation() = 0;//=0是指形式上的作用，告诉编译系统“这是纯虚函数”
};

class ProductA:public AbstractProduct{//具体产品A
public:
    void operation(){
        cout<<"ProductA"<<endl;
    }
};

class ProductB:public AbstractProduct{//具体产品B
public:
    void operation(){
        cout<<"ProductB"<<endl;
    }
};

class AbstractFactory{//抽象工厂
public:
    virtual ~AbstractFactory(){}
    virtual AbstractProduct* createProduct() = 0;//=0是指形式上的作用，告诉编译系统“这是纯虚函数”
};

class FactoryProductA:public AbstractFactory{// 具体工厂A
public:
    AbstractProduct* createProduct(){
        return new ProductA();
    }
};

class FactoryProductB:public AbstractFactory{// 具体工厂B
public:
    AbstractProduct* createProduct(){
        return new ProductB();
    }
};

int main(){
    AbstractFactory* f1 = new FactoryProductA();
    AbstractProduct* p1 = f1->createProduct();

    AbstractFactory* f2 = new FactoryProductB();
    AbstractProduct* p2 = f2->createProduct();
    p1->operation();
    p2->operation();

    delete p1;
    delete p2;
    delete f1;
    delete f2;
    return 0;
}


