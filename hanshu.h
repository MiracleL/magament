#ifndef HANSHU_H
#define HANSHU_H


#include"linklist.h"
#include"queue.h"
#include<QString>
using namespace std;

void add_clicked(linklist<string> &cloth1,QString &s,QString &item
                 ,int &number)

{
    int i=0;
    link<string> *temp=cloth1.head->next;
    for(i=0;i<cloth1.cnt;i++)
    {
        if(item.toStdString()==temp->element)
        {
            temp->number+=number;
            break;
        }
        temp=temp->next;
    }
    if(i==cloth1.cnt)
    cloth1.append(item.toStdString(),number,s.toStdString());
}
#endif // HANSHU_H
