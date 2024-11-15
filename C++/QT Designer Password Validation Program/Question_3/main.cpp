#include <QApplication>
#include "PasswordValidator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PasswordValidator window;
    window.show();

    return app.exec();
}
