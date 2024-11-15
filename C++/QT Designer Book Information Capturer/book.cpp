#include "Book.h"
#include <iostream>
#include <QTextStream>

// Default Constructor
Book::Book() {}

// Parameterized Constructor
Book::Book(const QString& t, const QStringList& a, const QString& i, const QDate& p)
    : title(t), authors(a), isbn(i), publicationDate(p) {}

// Setters
void Book::setTitle(const QString& t) { title = t; }
void Book::setAuthors(const QStringList& a) { authors = a; }
void Book::setIsbn(const QString& i) { isbn = i; }
void Book::setPublicationDate(const QDate& p) { publicationDate = p; }

// Getters
QString Book::getTitle() const { return title; }
QStringList Book::getAuthors() const { return authors; }
QString Book::getIsbn() const { return isbn; }
QDate Book::getPublicationDate() const { return publicationDate; }

// Method to get book info from user via console (for testing purposes)
void Book::obtainBookInfo() {
    QTextStream qin(stdin);
    QString t, i;
    QStringList a;
    QDate p;

    // Get user input
    std::cout << "Enter book title: ";
    t = qin.readLine();

    std::cout << "Enter authors (comma separated): ";
    a = qin.readLine().split(',');

    std::cout << "Enter ISBN: ";
    i = qin.readLine();

    std::cout << "Enter publication date (yyyy-mm-dd): ";
    QString dateString = qin.readLine();
    p = QDate::fromString(dateString, "yyyy-MM-dd");

    setTitle(t);
    setAuthors(a);
    setIsbn(i);
    setPublicationDate(p);
}
