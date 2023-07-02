#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_add_edge_clicked();
    void on_pushButton_generate_add_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<std::pair<int,std::pair<int,int>>> list;
    std::vector<std::vector<int>> graph_t;
};
#endif // MAINWINDOW_H
