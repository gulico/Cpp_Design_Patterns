/**
 * 装饰者模式：
 * 不同咖啡加不同配料
 * output:
 * DarkRoast+Milk
 * 2.5
 * DarkRoast+Milk+Suger
 * 3
**/

#include<iostream>
using namespace std;

class Beverage{//饮料抽象构件
public:
    virtual string getDescription() = 0;  //饮料描述
    virtual float cost() = 0; //计算价格
};

class decorate:public Beverage{//装饰类
public:
    Beverage* m_coffee;
};

class DarkRoast:public Beverage{//具体某种咖啡1
public:
    string getDescription(){
        return "DarkRoast";
    }
    float cost(){
        return 1.5;
    }
};

class Espresso:public Beverage{//具体某种咖啡2
public:
    string getDescription(){
        return "Espresso";
    }
    float cost(){
        return 6.5;
    }
};

class Milk:public decorate{//具体装饰类:牛奶
public:
    Milk(){}
    Milk(Beverage* coffee){
        this->m_coffee = coffee;
    }
    string getDescription(){
        return this->m_coffee->getDescription()+"+Milk";
    }
    float cost(){
        return this->m_coffee->cost() + 1;
    }

};

class Suger:public decorate{//具体装饰类：糖
public:
    Suger(){}
    Suger(Beverage* coffee){
        this->m_coffee = coffee;
    }
    string getDescription(){
        return this->m_coffee->getDescription()+"+Suger";
    }
    float cost(){
        return this->m_coffee->cost() + 0.5;
    }

};

int main(){
    //深烘培+牛奶
    Beverage* coffee = new DarkRoast();
    decorate* milk = new Milk(coffee);
    cout<<milk->getDescription()<<endl;
    cout<<milk->cost()<<endl;

    //深烘培+牛奶的基础上再加糖
    decorate* suger = new Suger(milk);
    cout<<suger->getDescription()<<endl;
    cout<<suger->cost()<<endl;

    delete coffee;
    delete milk;
    delete suger;
    return 0;
}