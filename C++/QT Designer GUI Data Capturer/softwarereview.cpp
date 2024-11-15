#include "softwarereview.h"

SoftwareReview::SoftwareReview(const QString& name, const QDate& date, bool recommended)
    : m_name(name), m_date(date), m_recommended(recommended) {}
QString SoftwareReview::getName() const {
    return m_name;
}
QDate SoftwareReview::getDate() const {
    return m_date;
}
bool SoftwareReview::isRecommended() const {
    return m_recommended;
}
