#ifndef VENDOR_H
#define VENDOR_H

#include <QString>

class Vendor {
private:
    QString m_Name;
    QString m_Email;
    bool m_IsManufacturer;

public:
    Vendor(const QString& name, const QString& email, bool isManufacturer);

    QString getName() const;
    QString getEmail() const;
    bool isManufacturer() const;
    QString toString() const;
};

#endif // VENDOR_H
