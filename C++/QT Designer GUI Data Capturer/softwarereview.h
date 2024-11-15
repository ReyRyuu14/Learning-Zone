#ifndef SOFTWAREREVIEW_H
#define SOFTWAREREVIEW_H
#include <QString>
#include <QDate>

class SoftwareReview {
public:
    SoftwareReview(const QString& name, const QDate& date, bool recommended);
    QString getName() const;
    QDate getDate() const;
    bool isRecommended() const;
private:
    QString m_name;
    QDate m_date;
    bool m_recommended;
};
#endif
