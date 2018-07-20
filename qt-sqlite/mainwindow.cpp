#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->ageLineEdit->setValidator( new QIntValidator(0, 255, this) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    QString dbName = ui->dbNameLineEdit->text();
    if (dbName != "")
    {
        db = new MyDataBase(dbName);

        ui->stackedWidget->setCurrentWidget(ui->viewDatabaseWidget);

        refresh_tableView();
    }
}

void MainWindow::on_deleteButton_clicked()
{

}

void MainWindow::on_addButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString surname = ui->surnameLineEdit->text();
    quint8 age = ui->ageLineEdit->text().toUInt();

    db->AddNewClient(name, surname, age);

    refresh_tableView();
}

void MainWindow::refresh_tableView()
{
    QSqlTableModel* tableModel = db->GetTableModel();
    tableModel->setParent(this);

    ui->tableView->setModel(tableModel);
    ui->tableView->show();
}
