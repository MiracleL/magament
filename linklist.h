#ifndef LINKLIST_H
#define LINKLIST_H
#include<string>
#include"link.h"
using namespace std;
template <typename E>

class linklist
{
public:
    link <E>*head;
    link <E>*tail;
    link <E>*curr;
    int cnt;
    void init()
    {
        curr=tail=head=new link<E>(NULL);
        cnt=0;
    }
    void removeall();

public:
    linklist()
    {
        init();
    }
    ~linklist()
    {
        init();
        delete head;
    }

    void print();
    void clear()
    {
        removeall();
        init();
    }
    void insert(const E &it)
    {
        if(cnt==0)
        {
            curr=head=tail=new link<E>(it,NULL);
        }
        else
        {
            curr->next=new link<E>(it, curr->next);
            if(tail=curr)
            {
                tail=curr->next;
            }
        }

    }
    void append(const E &it,int b,const string c)
    {
        tail=tail->next=new link<E>(it,b,c,NULL);
        cnt++;
    }
    link<E>* remove()
    {
        if(cnt==0)
            return NULL;
        link<E>* temp=curr->next;
        if(tail=curr->next)
            tail=curr;
        curr->next=curr->next->next;
        cnt--;
        return temp;
    }
    void next()
    {
        if(curr!=tail)
            curr=curr->next;
    }
    void prev()
    {
        if(curr==head)
            return NULL;
        link<E> *temp=head;
        while(temp->next!=curr)
            temp=temp->next;
        curr=temp;
    }
    int length()
    {
        return cnt;
    }
    void movetostart()
    {
        curr=head;
    }
};

#endif // LINKLIST_H
