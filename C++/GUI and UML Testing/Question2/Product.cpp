#include "Product.h"
#include "Vendor.h"

Product::Product(const QString& name, double price)
    : m_Name(name), m_Price(price), m_Supplier(nullptr) {
}

void Product::setSupplier(const QString& supplierName, const QString& supplierEmail, bool isManufacturer) {
    m_Supplier = new Vendor(supplierName, supplierEmail, isManufacturer);
}

QString Product::getManufacturerName() const {
    if (m_Supplier && m_Supplier->isManufacturer())
        return m_Supplier->getName();
    else
        return "Unknown";
}

QString Product::toString(bool supplierDetails) const {
    QString productDetails = "Product: Name=" + m_Name + ", Price=" + QString::number(m_Price);

    if (supplierDetails && m_Supplier)
        return m_Supplier->toString() + "\n" + productDetails;
    else
        return productDetails;
}
