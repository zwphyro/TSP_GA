#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include<iostream>
#include <QVBoxLayout>
#include "../algorithm/Algorithm.h"
#include "./controller/ControllerUI.h"
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
    void onFileChoose();
    void onGraphGenerateAdd();
    void onGraphGenerateFile();
    void onGraphGenerateRandom();
    void testSlot();
    void onSaveClicked();


private:
    Ui::MainWindow *ui;
    std::vector<std::pair<int,std::pair<int,int>>> list_edge;
    std::vector<std::vector<int>> graph_t;
    QVBoxLayout *layout;
    Algorithm* ui_slave = nullptr;
    ControllerUI controllerUi;

    void initConnectTabFile();
    void initConnectTabAddVertex();
    void initConnectTabRandom();
    void initConnectBlockControl();
};
#endif // MAINWINDOW_H
