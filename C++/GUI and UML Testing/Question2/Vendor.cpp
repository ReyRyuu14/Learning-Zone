#include "Vendor.h"

Vendor::Vendor(const QString& name, const QString& email, bool isManufacturer)
    : m_Name(name), m_Email(email), m_IsManufacturer(isManufacturer) {
}

QString Vendor::getName() const {
    return m_Name;
}

QString Vendor::getEmail() const {
    return m_Email;
}

bool Vendor::isManufacturer() const {
    return m_IsManufacturer;
}

QString Vendor::toString() const {
    return "Vendor: Name=" + m_Name + ", Email=" + m_Email + ", IsManufacturer=" + (m_IsManufacturer ? "true" : "false");
}
