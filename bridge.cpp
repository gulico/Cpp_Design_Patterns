/**
 * 桥接模式
 * 例子：现需要提供大中小3种型号的画笔，能够绘制5种不同颜色
 * 而如果使用毛笔的话，
 * 只需要3种型号的毛笔，外加5个颜料盒，
 * 用3+5=8个类就可以实现15支蜡笔的功能。
 * **/
#include<iostream>
using namespace std;

class color{//实现类结构
public:
    ~color(){};
    virtual void getcolor(){};
};

class red:public color{//具体实现类
public:
    void getcolor(){
        cout<<"red"<<endl;
    };
};

class green:public color{
public:
    void getcolor(){
        cout<<"green"<<endl;
    };
};

class pen{//抽象类
protected:
    color* m_color;
public:
    ~pen(){
        delete m_color;
    };
    virtual void setcolor(color* newcolor){};
    virtual void draw(){};
};

class smallpen:public pen{//扩充抽象类
public:
    smallpen(color* newcolor){
        this->m_color = newcolor;
    }
    void setcolor(color* newcolor){
        this->m_color = newcolor;
    }
    void draw(){
        cout<<"smallpen with";
        this->m_color->getcolor();
        cout<<" color"<<endl;
    }
};

class bigpen:public pen{//扩充抽象类
public:
    bigpen(color* newcolor){
        this->m_color = newcolor;
    }
    void setcolor(color* newcolor){
        this->m_color = newcolor;
    }
    void draw(){
        cout<<"bigpen with";
        this->m_color->getcolor();
        cout<<" color"<<endl;
    }
};

int main(){
    pen* p1 = new smallpen(new red());
    p1->draw();
    pen* p2 = new bigpen(new green());
    
    p2->draw();

    delete p1;
    delete p2;
    return 0;
}