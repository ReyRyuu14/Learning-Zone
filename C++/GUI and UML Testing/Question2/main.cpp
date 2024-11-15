#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <iostream>
#include "Product.h"

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);

    Product product("", 0.0);
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    QString productName;
    double productPrice;
    qout << "Enter product details:\n";
    qout << "Name: ";
    qout.flush();
    productName = qin.readLine().trimmed();
    qout << "Price: ";
    qout.flush();
    qin >> productPrice;
    qin.readLine();

    product = Product(productName, productPrice);

    QString supplierName, supplierEmail, isManufacturerStr;
    qout << "Enter supplier details:\n";
    qout << "Name: ";
    qout.flush();
    supplierName = qin.readLine().trimmed();
    qout << "Email: ";
    qout.flush();
    supplierEmail = qin.readLine().trimmed();
    qout << "Is Manufacturer (true/false): ";
    qout.flush();
    isManufacturerStr = qin.readLine().trimmed();

    product.setSupplier(supplierName, supplierEmail, (isManufacturerStr == "true"));

    qout << "\nManufacturer Name: " << product.getManufacturerName() << '\n';
    qout << "\nProduct Details:\n";
    qout << product.toString(false) << '\n';
    qout << "\nProduct Details with Supplier:\n";
    qout << product.toString(true) << '\n';

    return a.exec();
}
