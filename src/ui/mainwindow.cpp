#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    layout = new QVBoxLayout(this);
    ui->scrollAreaWidgetContents->setLayout(layout);

//    connect(ui->pushButton_add_edge,SIGNAL(clicked()),
//            this, SLOT(on_pushButton_add_edge_clicked));
//    connect(ui->pushButton_generate_add,SIGNAL(clicked()),
//            this, SLOT(on_pushButton_generate_add_clicked));
//    connect(ui->pushButton_choose_file,SIGNAL(clicked()),
//            this, SLOT(onFileChoose()));

    initConnectTabFile();
    initConnectBlockControl();
    initConnectTabAddVertex();
    initConnectTabRandom();

    ui->scrollArea_list_of_edge->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea_list_of_edge->setWidgetResizable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onPushButtonAddEdgeClicked() {
    std::pair<int,std::pair<int,int>> element =
            std::pair(ui->spinBox_distance_between_cities->value(),
                      std::pair(ui->spinBox_departure_city->value(),ui->spinBox_arrival_city->value()));

    list_edge.push_back(element);
    QString added_line = QString::number(ui->spinBox_departure_city->value()) + " -> "
                         + QString::number(ui->spinBox_arrival_city->value()) + ": weight = "
                         + QString::number(ui->spinBox_distance_between_cities->value());

    QLabel *label_added = new QLabel(added_line);
    layout->addWidget(label_added);
}

void MainWindow::on_pushButton_generate_add_clicked(){
    const int n = ui->spinBox_enter_city_add->value();
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

    for(int i = 0; i < list_edge.size(); i++){
        if(list_edge[i].second.first < n && list_edge[i].second.second < n) {
            graph_t[list_edge[i].second.first][list_edge[i].second.second] = list_edge[i].first;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << graph_t[i][j] << " ";
        }
        std::cout<<"\n";
    }
}


void MainWindow::onFileChoose(){
    QString str = QFileDialog::getOpenFileName(0, "Выбор папки", "","*txt");
    ui->label_chosen_file->setText(str);
}

void MainWindow::initConnectTabFile(){
    connect(ui->pushButton_choose_file,SIGNAL(clicked()),
            this, SLOT(onFileChoose()));
    connect(ui->pushButton_generate_file,SIGNAL(clicked()),
            this,SLOT(onGraphGenerate()));
}
void MainWindow::initConnectTabAddVertex() {
    connect(ui->pushButton_generate_add,SIGNAL(clicked()),
            this,SLOT(onGraphGenerate()));

    connect(ui->pushButton_add_edge,SIGNAL(clicked()),
            this,SLOT(onPushButtonAddEdgeClicked()));
}

void MainWindow::initConnectTabRandom() {

    connect(ui->pushButton_full_rnd,SIGNAL(clicked()),
            this,SLOT(onGraphGenerate()));

    connect(ui->pushButton_generate_rnd,SIGNAL(clicked()),
            this,SLOT(onGraphGenerate()));
}

void MainWindow::initConnectBlockControl() {
    connect(ui->pushButton_skip,SIGNAL(clicked()),
            this,SLOT(onGraphGenerate()));

    connect(ui->pushButton_start,SIGNAL(clicked()),
            this,SLOT(onGraphGenerate()));

    connect(ui->pushButton_step_back,SIGNAL(clicked()),
            this,SLOT(onGraphGenerate()));

    connect(ui->pushButton_step_forward,SIGNAL(clicked()),
            this,SLOT(onGraphGenerate()));
}

void MainWindow::onGraphGenerate() {

    std::cout<<"work\n";
}


