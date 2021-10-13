#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("一元稀疏多项式计算器");
    w.show();
    return a.exec();
}
