#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"linklist.h"
#include"queue.h"
#include<QString>
#include"string"
#include<iostream>
#include<QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ADD_clicked()
{
    QString s,item;
    int number;
    ui->textBrowser_4->clear();
    s=ui->comboBox->currentText();
    item=ui->textEdit_name->toPlainText();
    number=ui->spinBox_number->value();
    if(s=="Food")
    {
        int i=0;
        link<string> *temp=food.head->next;
        for(i=0;i<food.cnt;i++)
        {
            if(item.toStdString()==temp->element)
            {
                temp->number+=number;
                break;
            }
            temp=temp->next;
        }
        if(i==food.cnt)
        food.append(item.toStdString(),number,s.toStdString());
    }
    else if(s=="Vegetable")
    {
        int i=0;
        link<string> *temp=vege.head->next;
        for(i=0;i<vege.cnt;i++)
        {
            if(item.toStdString()==temp->element)
            {
                temp->number+=number;
                break;
            }
            temp=temp->next;
        }
        if(i==vege.cnt)
        vege.append(item.toStdString(),number,s.toStdString());
    }
    else if(s=="Cloth")
    {
        int i=0;
        link<string> *temp=cloth.head->next;
        for(i=0;i<cloth.cnt;i++)
        {
            if(item.toStdString()==temp->element)
            {
                temp->number+=number;
                break;
            }
            temp=temp->next;
        }
        if(i==cloth.cnt)
        cloth.append(item.toStdString(),number,s.toStdString());
    }
    ui->textBrowser_4->setText("The data is already saved");
    ui->textEdit_name->clear();
    ui->spinBox_number->clear();
    ui->textBrowser_1->clear();
}


void MainWindow::on_Display_clicked()
{
    ui->textBrowser_1->clear();
    link<string> *temp=food.head->next;  //head.next是指向第一个元素

    for(int i=0;i<food.cnt;i++)
    {
         ui->textBrowser_1->append(QString::fromStdString(temp->category));
         //ui->textBrowser_1->append("   ");
         ui->textBrowser_1->append(QString::fromStdString(temp->element));
         //ui->textBrowser_1->append("   ");
         ui->textBrowser_1->append(QString::number(temp->number));
         ui->textBrowser_1->append("\n");
         temp=temp->next;
    }

    temp=vege.head->next;
    for(int i=0;i<vege.cnt;i++)
    {
         ui->textBrowser_1->append(QString::fromStdString(temp->category));
         //ui->textBrowser_1->append("   ");
         ui->textBrowser_1->append(QString::fromStdString(temp->element));
         //ui->textBrowser_1->append("   ");
         ui->textBrowser_1->append(QString::number(temp->number));
         ui->textBrowser_1->append("\n");
         temp=temp->next;
    }
    temp=cloth.head->next;
    for(int i=0;i<cloth.cnt;i++)
    {
         ui->textBrowser_1->append(QString::fromStdString(temp->category));
         //ui->textBrowser_1->append("   ");
         ui->textBrowser_1->append(QString::fromStdString(temp->element));
         //ui->textBrowser_1->append("   ");
         ui->textBrowser_1->append(QString::number(temp->number));
         ui->textBrowser_1->append("\n");
         temp=temp->next;
    }

}


void MainWindow::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    ui->comboBox_item->clear();
    if(arg1=="Food")
    {
        food.curr=food.head->next;
        QStringList item;
        for(int i=0;i<food.cnt;i++)
        {
            item<<QString::fromStdString(food.curr->element);
            food.curr=food.curr->next;
        }
        ui->comboBox_item->addItems(item);
    }


    if(arg1=="Vegetable")
    {
        vege.curr=vege.head->next;
        QStringList item;
        for(int i=0;i<vege.cnt;i++)
        {
            item<<QString::fromStdString(vege.curr->element);
            vege.curr=vege.curr->next;
        }
        ui->comboBox_item->addItems(item);
    }


    if(arg1=="Cloth")
    {
        cloth.curr=cloth.head->next;
        QStringList item;
        for(int i=0;i<cloth.cnt;i++)
        {
            item<<QString::fromStdString(cloth.curr->element);
            cloth.curr=cloth.curr->next;
        }
        ui->comboBox_item->addItems(item);
    }
}

void MainWindow::on_buttonBox_accepted()
{
    QMessageBox msg,msg1;
    msg.setText("Are you sure!");
    msg.setStandardButtons(QMessageBox::Yes|
                           QMessageBox::Cancel);
    int ret=msg.exec();
    if(ret==QMessageBox::Yes)
    {
        int number=ui->spinBox_2->value();
        QString item=ui->comboBox_item->currentText();
        if(ui->comboBox_3->currentText()=="Food")
        {
            food.curr=food.head->next;
            for(int i=0;i<food.cnt;i++)
            {
                if(item.toStdString()==food.curr->element)
                {
                    if(number>food.curr->number)
                    {
                        msg1.setText("The inventory is not enough");
                        msg1.exec();
                    }
                    else
                    {
                        food.curr->number-=number;
                        link<string> *temp=new link<string>(food.curr->element,number,food.curr->category
                                                            ,NULL);

                        good.enqueue(temp);


                        ui->textBrowser_1->clear();
                        ui->Display->click();
                        delete temp;

                    }
                    break;
                }
                food.curr=food.curr->next;
            }
        }


        else if(ui->comboBox_3->currentText()=="Vegetable")
        {
            vege.curr=vege.head->next;
            for(int i=0;i<vege.cnt;i++)
            {
                if(item.toStdString()==vege.curr->element)
                {
                    if(number>vege.curr->number)
                    {
                        msg1.setText("The inventory is not enough");
                        msg1.exec();
                    }
                    else
                    {
                        vege.curr->number-=number;
                        link<string> *temp=new link<string>(vege.curr->element,number,vege.curr->category
                                                            ,NULL);
                        good.enqueue(temp);

                        ui->textBrowser_1->clear();
                        ui->Display->click();
                        delete temp;

                    }
                 break;
                }
                vege.curr=vege.curr->next;
            }
        }


        else if(ui->comboBox_3->currentText()=="Cloth")
        {
            cloth.curr=cloth.head->next;
            for(int i=0;i<cloth.cnt;i++)
            {
                if(item.toStdString()==cloth.curr->element)
                {
                    if(number>cloth.curr->number)
                    {
                        msg1.setText("The inventory is not enough");
                        msg1.exec();
                    }
                    else
                    {
                        cloth.curr->number-=number;
                        link<string> *temp=new link<string>(cloth.curr->element,number,cloth.curr->category
                                                            ,NULL);
                        good.enqueue(temp);

                        ui->textBrowser_1->clear();
                        ui->Display->click();
                        delete temp;

                    }
                    break;
                }
                cloth.curr=cloth.curr->next;
            }

        }
    }

}

void MainWindow::on_buttonBox_rejected()
{
    ui->comboBox_item->clear();
    ui->spinBox_number->clear();
}

void MainWindow::on_pushButton_dis_clicked()
{
    ui->textBrowser_dis->clear();
     link<string> *temp;

     for(temp=good.front;temp!=good.rear;temp=temp->next)
     {
         ui->textBrowser_dis->append(QString::fromStdString(temp->next->category));
         ui->textBrowser_dis->append(QString::fromStdString(temp->next->element));
         ui->textBrowser_dis->append(QString::number(temp->next->number));
     }

}



void MainWindow::on_pushButton_clicked()         //出列
{
    link<string> *temp=good.dequeue();
    ui->pushButton_dis->click();
    good1.enqueue(temp);

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser_3->clear();
    link<string> *temp;

    for(temp=good1.front;temp!=good1.rear;temp=temp->next)
    {
        ui->textBrowser_3->append(QString::fromStdString(temp->next->category));
        ui->textBrowser_3->append(QString::fromStdString(temp->next->element));
        ui->textBrowser_3->append(QString::number(temp->next->number));
    }
}
