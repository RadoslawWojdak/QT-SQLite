#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

        QSqlTableModel* tableModel = db->GetTableModel();
        tableModel->setParent(this);

        ui->tableView->setModel(tableModel);
        ui->tableView->show();
    }
}

void MainWindow::on_deleteButton_clicked()
{

}

void MainWindow::on_addButton_clicked()
{

}
