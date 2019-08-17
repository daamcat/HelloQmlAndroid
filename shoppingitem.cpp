#include "shoppingitem.h"

ShoppingItem::ShoppingItem(QObject *parent) : QObject(parent)
{

}

ShoppingItem::~ShoppingItem()
{

}


void ShoppingItem::setName(QString name)
{
    m_name=name;
}
void ShoppingItem::setPrice(double price)
{
    m_price=price;
}
void ShoppingItem::setSumSpent(double sumSpent)
{
    m_sumSpent=sumSpent;
}
void ShoppingItem::setBalance(double balance)
{
    m_balance=balance;
}
void ShoppingItem::setWithdrawal(double withdrawal)
{
    m_withdrawal=withdrawal;
}
void ShoppingItem::setDate(QDate date)
{
    m_date=date;
}
void ShoppingItem::setTime(QTime time)
{
    m_time=time;
}
