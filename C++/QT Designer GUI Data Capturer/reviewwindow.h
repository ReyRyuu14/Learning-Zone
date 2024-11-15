#ifndef REVIEWWINDOW_H
#define REVIEWWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QDateEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <vector>
#include "softwarereview.h"

class ReviewWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit ReviewWindow(QWidget *parent = nullptr);
    ~ReviewWindow();
private slots:
    void on_addButton_clicked();
    void on_displayButton_clicked();
private:
    std::vector<SoftwareReview> m_reviews;
    QLineEdit *nameLineEdit;
    QDateEdit *dateEdit;
    QCheckBox *recommendedCheckBox;
    QPushButton *addButton;
    QPushButton *displayButton;
};
#endif
