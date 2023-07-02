#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->pushButton_add_edge,SIGNAL(clicked()),
            this, SLOT(on_pushButton_add_edge_clicked));



    connect(ui->pushButton_generate_add,SIGNAL(clicked()),
            this, SLOT(on_pushButton_generate_add_clicked));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_add_edge_clicked() {
    list.push_back(std::pair(ui->spinBox_distance_between_cities->value(),
                   std::pair(ui->spinBox_arrival_city->value(),ui->spinBox_departure_city->value())));


}

void MainWindow::on_pushButton_generate_add_clicked(){
    const int n = ui->spinBox_enter_city_add_2->value();
    std::cout << n;
    graph_t.resize(n);
    for(int i = 0; i < n; i++){
        graph_t[i].resize(n,INT_MAX);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << graph_t[i][j] << " ";
        }
        std::cout<<"\n";
    }

    for(int i = 0; i < list.size(); i++){
        if(list[i].second.first < n && list[i].second.second < n) {
            graph_t[list[i].second.first][list[i].second.second] = list[i].first;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << graph_t[i][j] << " ";
        }
        std::cout<<"\n";
    }



}
