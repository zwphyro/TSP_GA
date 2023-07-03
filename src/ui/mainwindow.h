#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include<iostream>
#include <QVBoxLayout>

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
    void onPushButtonAddEdgeClicked();
    void on_pushButton_generate_add_clicked();
    void onFileChoose();
    void onGraphGenerate();

private:
    Ui::MainWindow *ui;
    std::vector<std::pair<int,std::pair<int,int>>> list_edge;
    std::vector<std::vector<int>> graph_t;
    QVBoxLayout *layout;

    void initConnectTabFile();
    void initConnectTabAddVertex();
    void initConnectTabRandom();
    void initConnectBlockControl();
};
#endif // MAINWINDOW_H
