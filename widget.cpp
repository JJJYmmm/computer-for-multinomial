#include "widget.h"
#include "ui_widget.h"
#include"calculate.h"
#include"qdebug.h"
#include"qwidget.h"
#include<qmessagebox.h>
#include<QStatusBar>
#include<qstatusbar.h>
#include<qmovie.h>
#include<qradiobutton.h>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QStatusBar *stBar =new QStatusBar(this);
    stBar->showMessage("by HJ");
    ui->setupUi(this);
    list1.CreatList();	//初始化链表
    list2.CreatList();
    listsum.CreatList();
    connect(ui->btn,&QPushButton::clicked,[=](){
        float a;
        int b;
        a=ui->lineEdit->text().toFloat();
        b=ui->lineEdit_2->text().toInt();
        this->addnodel1(a,b);
        this->addnodel3(a,b);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    });
    connect(ui->btn_4,&QPushButton::clicked,[=](){
        int b;
        float a;
        a=ui->lineEdit_7->text().toFloat();
        b=ui->lineEdit_8->text().toInt();
        this->addnodel2(a,b);
        if(this->operate == true)
            this->addnodel3(a,b);
        else
            this->addnodel3(-a,b);
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
    });
    connect(ui->btn2,&QPushButton::clicked,[=](){
        this->callprintl1();
    });
    connect(ui->btn2_4,&QPushButton::clicked,[=](){
        this->callprintl2();
    });
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->callprintl3();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        this->clearl1();
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        this->clearl2();
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        this->clearl3();
    });

    QMovie *movie1;
    movie1= new QMovie(":/res.gif");
    ui->label_3->setMovie(movie1);
    movie1->start();

    connect(ui->radioButton_2,&QRadioButton::clicked,[=](){
       this->operate = true;
    });
    connect(ui->radioButton,&QRadioButton::clicked,[=](){
       this->operate = false;
    });

    ui->radioButton_2->setChecked(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::callprintl1()
{
    this->list1.PrintList();
}

void Widget::addnodel1(float a,int b)
{
    list1.AddNode(a,b);
}

void Widget::callprintl2()
{
    this->list2.PrintList();
}

void Widget::addnodel2(float a,int b)
{
    list2.AddNode(a,b);
}

void Widget::callprintl3()
{
    this->listsum.PrintList();
}

void Widget::addnodel3(float a,int b)
{
    listsum.AddNode(a,b);
}

void Widget::clearl1()
{
    list1.CreatList();
    QMessageBox::information(NULL, "CLEAR", "List cleared");
}
void Widget::clearl2()
{
    list2.CreatList();
    QMessageBox::information(NULL, "CLEAR", "List cleared");
}
void Widget::clearl3()
{
    listsum.CreatList();
    QMessageBox::information(NULL, "CLEAR", "List cleared");
}

