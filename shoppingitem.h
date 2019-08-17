#ifndef SHOPPINGITEM_H
#define SHOPPINGITEM_H


#include <QObject>
#include <QString>
#include <QDate>
#include <QTime>

class ShoppingItem : public QObject
        // From [1]: The easiest way to use a class in QML is to derive it from QObject class
{
    Q_OBJECT
    Q_PROPERTY(QString m_name) //macro declares a property that could be accessed from QML.
public:
    explicit ShoppingItem(QObject *parent=0); // From [1].
    ~ShoppingItem();

    void setName(QString name);
    void setPrice(double price);
    void setSumSpent(double sumSpent);
    void setBalance(double balance);
    void setWithdrawal(double withdrawal);
    void setDate(QDate date);
    void setTime(QTime time);

    QString m_name;
    double m_price;
    double m_sumSpent;
    double m_balance;
    double m_withdrawal;
    QDate m_date;
    QTime m_time;

};
#endif // SHOPPINGITEM_H
