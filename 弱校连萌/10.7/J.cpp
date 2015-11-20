#include<iostream>
using namespace std;
class A
{
    public:
        virtual void print()
        {
            cout<<"This is A"<<endl;
        }
};
 
class B : public A
{
public:
    virtual void print()
    {
        cout<<"This is B"<<endl;
    }
};
 
int main()
{
    //为了在以后便于区分，我这段main()代码叫做main1
    A a;
    B b;
    A *p = &b;
    p->print();
    p = &a;
    p->print();
    return 0;
}