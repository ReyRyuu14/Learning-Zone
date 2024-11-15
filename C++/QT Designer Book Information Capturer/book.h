#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QStringList>
#include <QDate>

class Book {
private:
    QString title;
    QStringList authors;
    QString isbn;
    QDate publicationDate;

public:
    // Constructors
    Book();
    Book(const QString& t, const QStringList& a, const QString& i, const QDate& p);

    // Setters
    void setTitle(const QString& t);
    void setAuthors(const QStringList& a);
    void setIsbn(const QString& i);
    void setPublicationDate(const QDate& p);

    // Getters
    QString getTitle() const;
    QStringList getAuthors() const;
    QString getIsbn() const;
    QDate getPublicationDate() const;

    // Method for obtaining book information from user input
    void obtainBookInfo();
};

#endif
