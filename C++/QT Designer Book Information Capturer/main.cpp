#include <QApplication>
#include "BookInput.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    BookInput window;
    window.setWindowTitle("Book Input");
    window.show();

    return app.exec();
}
