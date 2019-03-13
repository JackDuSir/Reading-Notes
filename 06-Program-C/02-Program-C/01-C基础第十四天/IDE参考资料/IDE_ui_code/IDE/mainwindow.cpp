#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#define cout qDebug()

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

//新建按钮的处理函数
void MainWindow::on_actionNew_triggered()
{
    cout << "test button";

    //通过代码操作编辑区控件，给其设置内容
    ui->textEdit->setText("hello qt");
}
