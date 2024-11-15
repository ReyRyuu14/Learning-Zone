#include "mainwindow.h"
#include <QFileDialog>
#include <QTextCursor>
#include <QRegularExpression>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QMenuBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Search");
    QTextEdit *textEdit = new QTextEdit;
    setCentralWidget(textEdit);

    QMenuBar *menuBar = new QMenuBar;
    QMenu *fileMenu = menuBar->addMenu(tr("&File"));
    QAction *openAction = new QAction(tr("&Open"), this);
    fileMenu->addAction(openAction);
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);

    setMenuBar(menuBar);
}
MainWindow::~MainWindow()
{
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load"), QString(), tr("Load Files (*.txt)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QString content = file.readAll();
            QTextEdit *textEdit = qobject_cast<QTextEdit*>(centralWidget());
            textEdit->setPlainText(content);
            highlightText(content);
        }
    }
}

void MainWindow::highlightText(const QString& text)
{
    QTextEdit *textEdit = qobject_cast<QTextEdit*>(centralWidget());
    QTextDocument *document = textEdit->document();
    QTextCursor cursor(document);
    QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
    QRegularExpression phoneRegex("\\b(?:\\(?\\d{3}\\)?[-.\\s]?)?\\d{3}[-.\\s]?\\d{4}\\b");
    cursor.beginEditBlock();
    QTextCharFormat emailFormat;
    emailFormat.setForeground(Qt::blue);
    QTextCharFormat phoneFormat;
    phoneFormat.setForeground(Qt::green);
    while (!cursor.isNull() && !cursor.atEnd()) {
        cursor = document->find(emailRegex, cursor);
        if (!cursor.isNull()) {
            cursor.mergeCharFormat(emailFormat);
            cursor.movePosition(QTextCursor::EndOfBlock);
        }
    }
    cursor.setPosition(0);
    while (!cursor.isNull() && !cursor.atEnd()) {
        cursor = document->find(phoneRegex, cursor);
        if (!cursor.isNull()) {
            cursor.mergeCharFormat(phoneFormat);
            cursor.movePosition(QTextCursor::EndOfBlock);
        }
    }
    cursor.endEditBlock();
}
