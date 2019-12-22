/**
 * 组合模式
 * 这里bug有点多，orz修不好
**/
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
/**
 * Component抽象基类，为组合中的对象声明接口,
 * 声明了类共有接口的缺省行为(如这里的Add,Remove,GetChild函数),
 * 声明一个接口函数可以访问Component的子组件.
**/

class Component{//抽象构件
public:
    ~Component(){};
    //纯虚函数，只提供接口，没有默认的实现
    virtual void operation() = 0;

    // 虚函数,提供接口,有默认的实现就是什么都不做
    virtual void add(Component* c){};
    virtual void remove(Component* c){};
    virtual Component* getchild(int i){};
};

class leaf:public Component{
public:
    string name;
    void operation(){
        //cout<<"leaf::operation"<<endl;
    };
    leaf(string newname) : name(newname){};
};

class composite:public Component{
public:
    vector<Component*> child;
    void add(Component* c){
        this->child.push_back(c);
    }
    void remove(Component* c){
        this->child.erase(&c);
    }
    void operation(){
        vector<Component*>::iterator it = this->child.begin();
        for(; it != this->child.end() ; it++){
            (*it)->operation();
        }
    }
    Component* getchild(int i){
        if(i<0||i>this->child.size()){
            return NULL;
        }
        return this->child[i];
    }

};

int main(){
    return 0;
}