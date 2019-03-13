#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define WORDMAX 111104


struct dicts
{
    char * word;
    char * trans;
};
typedef struct dicts dic;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    dic *p;

};

#endif // MAINWINDOW_H
