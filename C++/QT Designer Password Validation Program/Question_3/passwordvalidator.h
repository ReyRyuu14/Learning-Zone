#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLabel>

class PasswordValidator : public QWidget
{
    Q_OBJECT

public:
    PasswordValidator(QWidget *parent = nullptr);

private slots:
    void validatePassword();

private:
    QLineEdit *passwordInput;
    QCheckBox *rule1CheckBox;
    QCheckBox *rule2CheckBox;
    QCheckBox *rule3CheckBox;
    QLabel *resultLabel;

    bool validateRule1(const QString &password);
    bool validateRule2(const QString &password);
    bool validateRule3(const QString &password);
};

#endif // PASSWORDVALIDATOR_H
