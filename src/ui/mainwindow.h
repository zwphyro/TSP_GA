#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include<iostream>
#include <QVBoxLayout>
#include "../algorithm/Algorithm.h"
#include "./controller/ControllerUI.h"
#include <math.h>
//#include "PaintWidget.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#define CONST_SHIFT_LINE 20
#define CONST_SHIFT_TEXT 10
#define CONST_SCENE_WIDTH 230
#define CONST_SCENE_HEIGHT 150


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


/*
 * struct to paint on GraphicsScene
 * */
struct Point{
    int x;
    int y;
};


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
    void radioButtonClicked();
    void onSaveClicked();

    void onStartClicked();
    void onNextClicked();
    void onPrevClicked();
    void onSkipClicked();




private:
    Ui::MainWindow *ui;
    std::vector<std::pair<int,std::pair<int,int>>> list_edge;
    std::vector<std::vector<int>> graph_t;
    QVBoxLayout *layout;
    Algorithm* ui_slave = nullptr;
    ControllerUI controllerUi;
    Point *list_point = nullptr;
    QGraphicsScene *scene;
    QGraphicsTextItem *text;


    void initConnectTabFile();
    void initConnectTabAddVertex();
    void initConnectTabRandom();
    void initConnectBlockControl();
    void drawGraph();
    void drawIndividual();
    void drawPopulation();
    void chooseWhatToDraw();
    void drawPoints(int n);


};
#endif // MAINWINDOW_H
