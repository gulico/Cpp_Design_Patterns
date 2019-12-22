/** 
 * 简单工厂模式
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

class Factory{//工厂
public:
    AbstractProduct* createProduct(char product){
        AbstractProduct* p = NULL;
        switch (product)
        {
        case 'A':
            p = new ProductA();
            break;
        case 'B':
            p = new ProductB();
            break;
        default:
            break;
        }
        return p;
    }
};

int main(){
    Factory* f = new Factory();
    AbstractProduct* p1 = f->createProduct('A');
    AbstractProduct* p2 = f->createProduct('B');
    p1->operation();
    p2->operation();

    delete p1;
    delete p2;
    delete f;
    return 0;
}


