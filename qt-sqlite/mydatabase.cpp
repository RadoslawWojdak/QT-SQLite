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
    if (!query.exec("CREATE TABLE IF NOT EXISTS clients(id INTEGER PRIMARY KEY, name VARCHAR(25), surname VARCHAR(45), age TINYINT UNSIGNED)"))
        ShowErrorMessage("Error: The table of clients was not created");

    this->close();
}

void MyDataBase::ShowErrorMessage(QString text) const
{
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.exec();
}

void MyDataBase::AddNewClient(QString name, QString surname, quint8 age)
{
    if(!this->open())
        ShowErrorMessage("Error: The database file can not be created/opened");

    QSqlQuery query;
    query.prepare("INSERT INTO clients(name, surname, age) VALUES(?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(surname);
    query.addBindValue(age);

    if (!query.exec())
        ShowErrorMessage("Error: The table of clients was not updated");

    this->close();
}

void MyDataBase::DeleteClient(int id)
{
    if(!this->open())
        ShowErrorMessage("Error: The database file can not be created/opened");

    QSqlQuery query;
    query.prepare("DELETE FROM clients WHERE clients.id LIKE ?");
    query.addBindValue(id);

    if (!query.exec())
        ShowErrorMessage("Error: The records have not been deleted");

    this->close();
}


QSqlTableModel* MyDataBase::GetTableModel()
{
    if(!this->open())
        ShowErrorMessage("Error: The database file can not be created/opened");

    QSqlTableModel* model = new QSqlTableModel(NULL, *this);
    model->setTable("clients");
    model->select();

    this->close();

    return model;
}
