#include <QFile>
#include <QTextStream>


#include "shoppinglist.h"

ShoppingList::ShoppingList(QObject *parent) :
    QObject(parent),
    m_elementSeparator("___")
{

}

ShoppingList::~ShoppingList()
{

}

QString ShoppingList::getTableContents()
{
    if (m_stringList.size()>0)
    {
        QString hala= m_stringList.at(0);
        return hala;
    }
    else
    {
        return QString ("bad!");
    }
}

void ShoppingList::setFilePath(QUrl filePath)
{
    m_filePathUrl = filePath;
    m_filePathString = filePath.toString(QUrl::RemoveScheme);
    loadTextFile(m_filePathString);
}

QUrl ShoppingList::getFilePath()
{
    return m_filePathUrl;
}

void ShoppingList::loadTextFile(QString filePath)
{
    m_stringList.clear();

    QFile textFile(filePath);
    if (!textFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream textStream(&textFile);
    while (true)
    {
        QString line=textStream.readLine();
        if (line.isNull()==true)
        {
            break;
        }
        else
        {
            m_stringList.append(line);

            QStringList list;
            list=line.split(m_elementSeparator);

            // Fill the vector of shopping items:
            /*
            ShoppingItem shoppingItem;
            shoppingItem.setName(list[0]);
            shoppingItem.setPrice(list[1].toDouble());
            shoppingItem.setSumSpent(list[2].toDouble());
            shoppingItem.setBalance(list[3].toDouble());
            shoppingItem.setWithdrawal(list[4].toDouble());
            shoppingItem.setDate(QDate::fromString(list[5],"dd.mm,yyyy"));

            m_shoppingList.append(shoppingItem);
            */
        }
    }
}

QString ShoppingList::getElementSeparator()
{
    return m_elementSeparator;
}


void ShoppingList::addShoppingItem(ShoppingItem shoppingItem)
{

}
