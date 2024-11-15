#include "bookinput.h"
#include <QLabel>

BookInput::BookInput(QWidget *parent) : QWidget(parent)
{
    // Setup the UI components
    setupUi();
}

void BookInput::setupUi()
{
    // Create a layout for the widget
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Create the menu bar
    menuBar = new QMenuBar(this);
    QMenu *fileMenu = menuBar->addMenu("File");

    // Create the "Save" action
    saveAction = new QAction("Save", this);
    fileMenu->addAction(saveAction);

    // Connect the save action to the slot
    connect(saveAction, &QAction::triggered, this, &BookInput::saveBook);

    // Add the menu bar to the layout
    layout->setMenuBar(menuBar);

    // Create the form fields
    QLabel *titleLabel = new QLabel("Title:", this);
    titleInput = new QLineEdit(this);

    QLabel *authorsLabel = new QLabel("Authors (comma-separated):", this);
    authorsInput = new QLineEdit(this);

    QLabel *isbnLabel = new QLabel("ISBN:", this);
    isbnInput = new QLineEdit(this);

    QLabel *publicationDateLabel = new QLabel("Publication Date:", this);
    publicationDateInput = new QDateEdit(this);
    publicationDateInput->setDisplayFormat("yyyy-MM-dd");

    // Create the "Create Book" button
    createBookButton = new QPushButton("Create Book", this);

    // Connect the create button to the function that sets the Book instance
    connect(createBookButton, &QPushButton::clicked, this, &BookInput::handleCreateBook);

    // Add the form fields and button to the layout
    layout->addWidget(titleLabel);
    layout->addWidget(titleInput);
    layout->addWidget(authorsLabel);
    layout->addWidget(authorsInput);
    layout->addWidget(isbnLabel);
    layout->addWidget(isbnInput);
    layout->addWidget(publicationDateLabel);
    layout->addWidget(publicationDateInput);
    layout->addWidget(createBookButton);

    setLayout(layout);
}

void BookInput::handleCreateBook()
{
    // Get the data from the form fields and set it into the Book instance
    QString title = titleInput->text();
    QStringList authors = authorsInput->text().split(",");
    QString isbn = isbnInput->text();
    QDate publicationDate = publicationDateInput->date();

    currentBook.setTitle(title);
    currentBook.setAuthors(authors);
    currentBook.setIsbn(isbn);
    currentBook.setPublicationDate(publicationDate);
}

void BookInput::saveBook()
{
    // Open a QFileDialog for the user to choose where to save the book
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Book"), "", tr("Text Files (*.txt);;All Files (*)"));

    // Check if the user selected a file
    if (!fileName.isEmpty()) {
        // Save the current book details into the file
        bookWriter.saveBook(currentBook, fileName);
    }
}
