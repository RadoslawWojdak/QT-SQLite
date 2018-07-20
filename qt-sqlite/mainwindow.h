#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mydatabase.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    MyDataBase* db;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_deleteButton_clicked();

    void on_addButton_clicked();

    void refresh_tableView();

    void on_deleteLineEdit_returnPressed();

    void on_nameLineEdit_returnPressed();

    void on_surnameLineEdit_returnPressed();

    void on_ageLineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
