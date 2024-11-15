#include "bookwriter.h"

void BookWriter::saveBook(const Book &book, const QString &fileName)
{
    QFile file(fileName);

    // Open the file for writing
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        // Write the book details to the file
        out << "Title: " << book.getTitle() << "\n";
        out << "Authors: " << book.getAuthors().join(", ") << "\n";
        out << "ISBN: " << book.getIsbn() << "\n";
        out << "Publication Date: " << book.getPublicationDate().toString("yyyy-MM-dd") << "\n";

        file.close();
    } else {
        // Handle file open failure
        qWarning("Could not open file for writing.");
    }
}
