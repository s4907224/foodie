#include <QApplication>
#include "gui/fudie_widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FudieWidget mainwindow;
    mainwindow.show();
    return a.exec();
}
