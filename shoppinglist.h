#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QStringList>
#include <QUrl>

#include "shoppingitem.h"

/*

Refs:
[1] property
https://doc.qt.io/qt-5/qtqml-cppintegration-exposecppattributes.html
[2]

[3]

*/


class ShoppingList : public QObject
{
    Q_OBJECT
    // A "property" is a class data member with an associated read function and optional write function [1].
    Q_PROPERTY(QUrl filePath READ getFilePath WRITE setFilePath)
    Q_PROPERTY(QString tableContent READ getTableContents)


public:
    ShoppingList(QObject *parent = 0);
    ~ShoppingList();

    void addShoppingItem(ShoppingItem shoppingItem);

    QString getElementSeparator();

    QString getTableContents();

    void setFilePath(QUrl filePath);
    QUrl getFilePath();

private:
    void loadTextFile(QString filePath);

    QString m_filePathString;
    QUrl m_filePathUrl;
    QVector<ShoppingItem> m_shoppingList;
    QStringList m_stringList;

    QString m_elementSeparator;
};

#endif // SHOPPINGLIST_H
