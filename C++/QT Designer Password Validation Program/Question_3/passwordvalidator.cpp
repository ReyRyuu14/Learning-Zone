#include "PasswordValidator.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>

PasswordValidator::PasswordValidator(QWidget *parent)
    : QWidget(parent),
    passwordInput(new QLineEdit(this)),
    rule1CheckBox(new QCheckBox("Use Rule 1", this)),
    rule2CheckBox(new QCheckBox("Use Rule 2", this)),
    rule3CheckBox(new QCheckBox("Use Rule 3", this)),
    resultLabel(new QLabel(this))
{
    QPushButton *validateButton = new QPushButton("Validate Password", this);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(passwordInput);
    layout->addWidget(rule1CheckBox);
    layout->addWidget(rule2CheckBox);
    layout->addWidget(rule3CheckBox);
    layout->addWidget(validateButton);
    layout->addWidget(resultLabel);
    setLayout(layout);

    connect(validateButton, &QPushButton::clicked, this, &PasswordValidator::validatePassword);
}

void PasswordValidator::validatePassword()
{
    QString password = passwordInput->text();
    bool isValid = false;

    if (rule1CheckBox->isChecked()) {
        isValid = validateRule1(password);
    }
    if (rule2CheckBox->isChecked()) {
        isValid = isValid && validateRule2(password);
    }
    if (rule3CheckBox->isChecked()) {
        isValid = isValid && validateRule3(password);
    }

    resultLabel->setText(isValid ? "Password is valid." : "Password is invalid.");
}

bool PasswordValidator::validateRule1(const QString &password)
{
    if (password.length() < 5) {
        return false;
    }
    return !password.contains(' ');
}


bool PasswordValidator::validateRule2(const QString &password)
{
    if (password.length() != 5) {
        return false;
    }
    QChar thirdChar = password.at(2);
    return (thirdChar.isDigit() || (thirdChar >= 'a' && thirdChar <= 'f') || (thirdChar >= 'A' && thirdChar <= 'F'));
}
bool PasswordValidator::validateRule3(const QString &password)
{
    if (password.length() < 4 || password.length() > 6) {
        return false;
    }
    if (password[0] == '0') {
        return false;
    }
    QRegularExpression re("^[0-9]+$");
    QRegularExpressionMatch match = re.match(password);
    return match.hasMatch();
}
