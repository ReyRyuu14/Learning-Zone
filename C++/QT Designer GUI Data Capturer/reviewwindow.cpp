#include "reviewwindow.h"
#include <QLabel>
#include <QDebug>

ReviewWindow::ReviewWindow(QWidget *parent) :
    QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    QLabel *messageLabel = new QLabel("Please Add The Necessary Data And Press Add");
    messageLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(messageLabel);

    QGridLayout *inputLayout = new QGridLayout;
    QLabel *nameLabel = new QLabel("Name : ");
    nameLineEdit = new QLineEdit;
    inputLayout->addWidget(nameLabel, 0, 0);
    inputLayout->addWidget(nameLineEdit, 0, 1);

    QLabel *dateLabel = new QLabel("Date : ");
    dateEdit = new QDateEdit;
    inputLayout->addWidget(dateLabel, 1, 0);
    inputLayout->addWidget(dateEdit, 1, 1);

    recommendedCheckBox = new QCheckBox("Recommended ");
    inputLayout->addWidget(recommendedCheckBox, 2, 0, 1, 2);

    addButton = new QPushButton("Add ");
    connect(addButton, &QPushButton::clicked, this, &ReviewWindow::on_addButton_clicked);
    inputLayout->addWidget(addButton, 3, 0, 1, 2);

    displayButton = new QPushButton("Display ");
    connect(displayButton, &QPushButton::clicked, this, &ReviewWindow::on_displayButton_clicked);
    inputLayout->addWidget(displayButton, 4, 0, 1, 2);

    mainLayout->addLayout(inputLayout);
    mainLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
}
ReviewWindow::~ReviewWindow() {
}
void ReviewWindow::on_addButton_clicked() {
    QString name = nameLineEdit->text();
    QDate date = dateEdit->date();
    bool recommended = recommendedCheckBox->isChecked();
    SoftwareReview review(name, date, recommended);
    m_reviews.push_back(review);
    qDebug() << "Data Addedd: " << name << ", Date submitted: " << date.toString("yyyy-MM-dd") << ", Recomended: " << recommended;
}
void ReviewWindow::on_displayButton_clicked() {
    qDebug() << "All Added Reviews: ";
    for (const auto& review : m_reviews) {
        qDebug() << "Name: " << review.getName() << ", Date: " << review.getDate().toString("yyyy-MM-dd") << ", Recomended: " << review.isRecommended();
    }
}
