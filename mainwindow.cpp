#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"linklist.h"
#include"queue.h"
#include<QString>
#include"string"
#include<iostream>
#include<QMessageBox>
#include"hanshu.h"

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
        add_clicked(food,s,item,number);
    }
    else if(s=="Vegetable")
    {
        add_clicked(vege,s,item,number);
    }
    else if(s=="Cloth")
    {
        add_clicked(cloth,s,item,number);
    }
    else if(s=="Cloth2")
    {
       add_clicked(cloth2,s,item,number);
    }
    else if(s=="Cloth3")
    {
        add_clicked(cloth3,s,item,number);
    }


    ui->textBrowser_4->setText("The data is already saved");
    ui->textEdit_name->clear();
    ui->spinBox_number->clear();
    ui->textBrowser_1->clear();
}

void MainWindow::display_f(link<string> *temp,linklist<string> &cloth2)
{
    for(int i=0;i<cloth2.cnt;i++)
    {
         ui->textBrowser_1->append(QString::fromStdString(temp->category));
         ui->textBrowser_1->append(QString::fromStdString(temp->element));
         ui->textBrowser_1->append(QString::number(temp->number));
         ui->textBrowser_1->append("\n");
         temp=temp->next;
    }
}

void MainWindow::on_Display_clicked()
{
    ui->textBrowser_1->clear();
    link<string> *temp=food.head->next;  //head.next是指向第一个元素
    display_f(temp,food);
    temp=vege.head->next;
    display_f(temp,vege);
    temp=cloth.head->next;
    display_f(temp,cloth);
    temp=cloth2.head->next;
    display_f(temp,cloth2);
    temp=cloth3.head->next;
    display_f(temp,cloth3);

}

void MainWindow::display_co(linklist<string> &cloth1)
{
    cloth1.curr=cloth1.head->next;
    QStringList item;
    for(int i=0;i<cloth1.cnt;i++)
    {
        item<<QString::fromStdString(cloth1.curr->element);
        cloth1.curr=cloth1.curr->next;
    }
    ui->comboBox_item->addItems(item);
}


void MainWindow::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    ui->comboBox_item->clear();
    if(arg1=="Food")
    {
        display_co(food);
    }


    if(arg1=="Vegetable")
    {
        display_co(vege);
    }


    if(arg1=="Cloth")
    {
        display_co(cloth);
    }

    if(arg1=="CLoth2")
    {
        display_co(cloth2);
    }

    if(arg1=="Cloth3")
    {
        display_co(cloth3);
    }
}

void MainWindow::ship_good(linklist<string> &cloth1,int &number,QString &item)
{
    QMessageBox msg1;
    cloth1.curr=cloth1.head->next;
    for(int i=0;i<cloth1.cnt;i++)
    {
        if(item.toStdString()==cloth1.curr->element)
        {
            if(number>cloth1.curr->number)
            {
                msg1.setText("The inventory is not enough");
                msg1.exec();
            }
            else
            {
                cloth1.curr->number-=number;
                link<string> *temp=new link<string>(cloth1.curr->element,number,cloth1.curr->category
                                                    ,NULL);

                good.enqueue(temp);


                ui->textBrowser_1->clear();
                ui->Display->click();
                delete temp;

            }
            break;
        }
        cloth1.curr=cloth1.curr->next;
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
           ship_good(food,number,item);
        }


        else if(ui->comboBox_3->currentText()=="Vegetable")
        {
            ship_good(vege,number,item);
        }
        else if(ui->comboBox_3->currentText()=="Cloth")
        {
            ship_good(cloth,number,item);
        }
        else if(ui->comboBox_3->currentText()=="Cloth2")
        {
            ship_good(cloth2,number,item);
        }
        else if(ui->comboBox_3->currentText()=="Cloth3")
        {
            ship_good(cloth3,number,item);
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
