#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include "Vendor.h"

class Product {
private:
    QString m_Name;
    double m_Price;
    Vendor* m_Supplier;

public:
    Product(const QString& name, double price);

    void setSupplier(const QString& supplierName, const QString& supplierEmail, bool isManufacturer);
    QString getManufacturerName() const;
    QString toString(bool supplierDetails) const;
};

#endif // PRODUCT_H
