#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//按钮处理函数
void Widget::on_pushButton_clicked()
{
    //设置行编辑的内容
    ui->lineEdit->setText("hello qt");

    //获取行编辑的内容
    QString str = ui->lineEdit->text();

    //把行编辑的内容设置给标签
    ui->label->setText(str);
}
