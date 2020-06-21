#include<iostream>
using namespace std;

const int getValue(){
    int a = 15;
    return a;
}

class A{
public:
    A(){
        cout << "base intructor" << endl;
    }
    virtual ~A(){ cout << "base destructor" << endl;}

    void show(){cout <<"base show" << endl;}
};

class B: public A{
public:
    B() {cout << "B intructor" << endl;}
    ~B(){cout << "B destructor" << endl;}
    void show(){cout <<"B show" << endl;}
};

int main(){
    A* b = new B();
    b->show();
    delete b;
    return 0;
}