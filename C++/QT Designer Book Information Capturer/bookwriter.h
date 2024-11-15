#ifndef BOOKWRITER_H
#define BOOKWRITER_H

#include "book.h"
#include <QString>
#include <QFile>
#include <QTextStream>

class BookWriter
{
public:
    void saveBook(const Book &book, const QString &fileName);
};

#endif // BOOKWRITER_H
