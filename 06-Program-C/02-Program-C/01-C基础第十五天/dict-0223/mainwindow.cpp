#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    p = (dic*)malloc(sizeof(dic)* WORDMAX);

    //读取文件内容
    FILE * fp = fopen("D:\\dict.txt", "r");
    if (!fp)
        return;
    int i = 0;
    char buf[1024];
    while (!feof(fp))
    {
        memset(buf, 0, 1024);
        fgets(buf, 1024, fp);

        //格式化操作
        buf[strlen(buf) - 1] = '\0';
//        for (int i = strlen(buf); i > 0; i--)
//        {
//            if (buf[i] == '\n')
//            {
//                buf[i] = '\0';
//                break;
//            }
//        }


        //开辟堆空间
        p[i].word = (char *)malloc(strlen(buf) + 1);
        memset(p[i].word, 0, strlen(buf) + 1);
        strcpy(p[i].word, &buf[1]);//#abc\n

        memset(buf, 0, 1024);
        fgets(buf, 1024, fp);
        p[i].trans = (char*)malloc(strlen(buf) + 1);
        memset(p[i].trans, 0, strlen(buf) + 1);
        strcpy(p[i].trans, buf);
        i++;
    }


    fclose(fp);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    for (int i = 0; i < WORDMAX; i++)
    {
        free(p[i].word);
        free(p[i].trans);
    }
    free(p);

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString txt = ui->textEdit->toPlainText();
    QTextCodec * codec = QTextCodec::codecForName("GBK");
    if(txt.isEmpty())
    {
        ui->label->setText(codec->toUnicode("请输入单词！"));
        return;
    }
    char * buf = codec->fromUnicode(txt).data();

    for(int i=0;i<WORDMAX;i++)
    {
        if(!strcmp(buf,p[i].word))
        {
            ui->label->setText(codec->toUnicode(p[i].trans));
            return;
        }
    }
    ui->label->setText(codec->toUnicode(("未找到该单词的解释！")));

}
