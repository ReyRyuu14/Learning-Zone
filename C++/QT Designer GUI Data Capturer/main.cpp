#include <QApplication>
#include "reviewwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ReviewWindow w;
    w.show();
    return a.exec();
}
