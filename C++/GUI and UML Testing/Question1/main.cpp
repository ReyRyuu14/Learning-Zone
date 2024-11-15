#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QString>

QString createUsername(const QString& fullName) {
    QString username;
    QStringList fullNameList = fullName.split(" ");
    QString firstName = fullNameList[0];
    QString lastName = fullNameList.last();
    QString userSurname = lastName.left(4).toLower();
    QString userFirstName = firstName.left(1).toUpper();

    username = userFirstName + userSurname;

    if (username.length() < 5) {
        int remainingLength = 5 - username.length();
        if (firstName.length() >= remainingLength) {
            username += firstName.left(remainingLength).toLower();
        } else {
            username += firstName.toLower();
            remainingLength -= firstName.length();
            for (int i = 0; i < remainingLength; ++i) {
                username += "0";
            }
        }
    }

    return username;
}

QString createPassword(const QString& fullName) {
    QString password;
    QString Char = fullName.simplified().remove(" ");

    for (int i = 0; i < 5; ++i) {
        int randomIndex = rand() % Char.length();
        password += Char[randomIndex];
    }

    return password;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QString fullName = QInputDialog::getText(0, "Full Name", "Enter your full name:");

    QString username = createUsername(fullName);
    QString password = createPassword(fullName);

    QMessageBox::information(0, "Username and Password", "Username: " + username + "\nPassword: " + password);

    return app.exec();
}
