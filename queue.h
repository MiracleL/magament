#ifndef QUEUE_H
#define QUEUE_H
#include"link.h"

#include<assert.h>

template <typename E>
class queue
{
public:
    link<E> *front;
    link<E> *rear;
    int size;
public:
    queue()
    {
        front=rear=new link<E>(NULL);
        size=0;
    }
    ~queue()
    {
        clear();
        delete front;
    }
    void clear()
    {
        while(front->next!=NULL)
        {
            link<E> *temp=front->next;
            front->next=temp->next;
            delete temp;
        }
        rear=front;
        size=0;
    }

    void enqueue(E &it)
    {
        rear->next=new link<E>(it,NULL);
        rear=rear->next;
        size++;
    }

    void enqueue(link<E> *temp)
    {
        rear->next=new link<E>(temp->element,temp->number,temp->category
                               ,temp->next);
        rear=rear->next;
        size++;
    }

    link<E>* dequeue()
    {
        if(size==0)
            return NULL;         // 需要修改。。。。。。。。
        link<E> *temp=front->next;
        front->next=temp->next;
        if(rear==temp)
            rear=front;
        size--;
        return temp;
    }
    int length()
    {
        return size;
    }


};

#endif // QUEUE_H
