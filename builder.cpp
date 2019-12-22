/**
 * 建造者模式：
 * 例子：KFC套餐 
 * 建造者模式可以用于描述KFC如何创建套餐：
 * 套餐是一个复杂对象，
 * 它一般包含主食（如汉堡、鸡肉卷等）
 * 和饮料（如果汁、可乐等）等组成部分，
 * 不同的套餐有不同的组成部分，
 * 而KFC的服务员可以根据顾客的要求，一步一步装配这些组成部分，构造一份完整的套餐，
 * 然后返回给顾客。
**/

#include<iostream>
#include<string>
using namespace std;

class Meal{//套餐的组成部分为：主食+饮料
public:
    string food = "";//主食
    string drink = "";//饮料 
};

class AbstractBuilder{//抽象建造者
public:
    Meal* meal = NULL;
    virtual void buildfood() = 0;
    virtual void builddrink() = 0;
    virtual Meal* getMeal() = 0;
    virtual ~AbstractBuilder(){}
};

class BuilderMealA:public AbstractBuilder{//建造套餐A
public:
    void buildfood(){
        meal->food = "汉堡";
    };
    
    void builddrink(){
        meal->drink = "果汁";
    };

    Meal* getMeal(){
        return meal;
    }
    ~BuilderMealA(){delete meal;}
};

class BuilderMealB:public AbstractBuilder{//建造套餐B
public:
    void buildfood(){
        meal->food = "鸡肉卷";
    };
    
    void builddrink(){
        meal->drink = "可乐";
    };
    Meal* getMeal(){
        return meal;
    }
    ~BuilderMealB(){delete meal;}
};

class DirctorKFCwaiter{//KFC服务员
public:
    AbstractBuilder* builder = NULL;
    DirctorKFCwaiter(AbstractBuilder* builder){
        this->builder = builder;
    }
    void setBuilder(AbstractBuilder* builder){
        this->builder = builder;
    }
    Meal* construct(){//建造流程是一样的
         builder->buildfood();//先装主食
         builder->builddrink();//后装饮料
         return builder->getMeal();
    }
};

int main(){
    Meal* mealA = NULL;
    Meal* mealB = NULL;
    AbstractBuilder* builder = new BuilderMealA();
    DirctorKFCwaiter* waiter = new DirctorKFCwaiter(builder);
    mealA = waiter->construct();
    cout<<"mealA的主食："<<mealA->food<<"，饮料："<<mealA->drink<<endl;
    delete builder;
    builder = NULL;

    builder = new BuilderMealB();
    waiter->setBuilder(builder);
    mealB = waiter->construct();
    cout<<"mealB的主食："<<mealB->food<<"，饮料："<<mealB->drink<<endl;
    delete builder;
    return 0;
}