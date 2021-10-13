#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"calculate.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void callprintl1();
    void addnodel1(float a,int b);
    void callprintl2();
    void addnodel2(float a,int b);
    void callprintl3();
    void addnodel3(float a,int b);
    void clearl1();
    void clearl2();
    void clearl3();
    List list1;		//创建链表对象
    List list2;
    List listsum;
    bool operate=true;
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
