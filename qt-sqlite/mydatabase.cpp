#include "mydatabase.h"

MyDataBase::MyDataBase(QString name) :
    QSqlDatabase (QSqlDatabase::addDatabase("QSQLITE"))
{
    QDir dbPath;
    QString path = dbPath.currentPath()+"/"+name+".sql";
    this->setDatabaseName(path);

    if(!this->open())
        ShowErrorMessage("Error: The database file can not be created/opened");

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS clients(id INTEGER PRIMARY KEY, name TEXT, surname TEXT, age INTEGER)"))
        ShowErrorMessage("Error: The table of clients was not created");

    this->close();
}

void MyDataBase::ShowErrorMessage(QString text) const
{
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.exec();
}