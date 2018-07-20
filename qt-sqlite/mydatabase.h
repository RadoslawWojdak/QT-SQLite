#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QMessageBox>
#include <QDir>

class MyDataBase :public QSqlDatabase
{
    void ShowErrorMessage(QString text) const;

public:
    MyDataBase(QString name);

    QSqlTableModel* GetTableModel();
};

#endif // MYDATABASE_H
