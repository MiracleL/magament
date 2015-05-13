#ifndef LINK_H
#define LINK_H
#include<string>
using namespace std;
template<typename E>
class link
{
public:
    E element;   //存储item
    int number;  // 存储数量
    string  category;
    link *next;
    link(E &a, link *nextval)
    {
        element=a;
        next=nextval;
    }
    link(link *nextval)
    {
        next=nextval;
    }
    link(const E &a,int b,const string c,link *nextval)
    {
        element=a;
        number=b;
        category=c;
        next=nextval;
    }
};

#endif // LINK_H
