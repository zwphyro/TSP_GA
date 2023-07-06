//
// Created by Маргарита  on 06.07.2023.
//


#include "dialog.h"
#include "ui_Dialog.h"
#include<iostream>

Dialog::Dialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::Dialog) {
    ui->setupUi(this);


    this->showFullScreen();
    ui->graphicsView->setGeometry(0,0,width(),height());
    ui->tabWidget->setGeometry(0,0,width(),height());
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);





}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::drawPlot(const std::vector<int> elements) {


    std::cout<<"in plot\n";
    int n = elements.size();
    if(n == 0 || n == 1){
        return;
    }
    int custom_width = width()/n;
    int koef = *max_element(std::begin(elements), std::end(elements))/height();


    for(int i = 0; i < n-1; i++){
        scene->addLine(i*custom_width,height() - elements[i]/koef, (i+1)*custom_width, height() - elements[i+1]/koef);
    }
}
