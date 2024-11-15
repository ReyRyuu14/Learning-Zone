#ifndef BOOKINPUT_H
#define BOOKINPUT_H

#include <QWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include "book.h"
#include "bookwriter.h"

class BookInput : public QWidget
{
    Q_OBJECT

public:
    explicit BookInput(QWidget *parent = nullptr);

private slots:
    void saveBook();
    void handleCreateBook();

private:
    QMenuBar *menuBar;
    QAction *saveAction;

    QLineEdit *titleInput;
    QLineEdit *authorsInput;
    QLineEdit *isbnInput;
    QDateEdit *publicationDateInput;
    QPushButton *createBookButton;

    Book currentBook;
    BookWriter bookWriter;

    void setupUi();
};

#endif // BOOKINPUT_H
