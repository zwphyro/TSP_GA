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

    connect(ui->pushButton_save,SIGNAL(clicked()),this,SLOT(onSaveClicked()));

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



void MainWindow::onFileChoose(){
    QString str = QFileDialog::getOpenFileName(0, "Выбор папки", "","*txt");
    ui->label_chosen_file->setText(str);
}

void MainWindow::initConnectTabFile(){
    connect(ui->pushButton_choose_file,SIGNAL(clicked()),
            this, SLOT(onFileChoose()));
    connect(ui->pushButton_generate_file,SIGNAL(clicked()),
            this,SLOT(onGraphGenerateFile()));
}
void MainWindow::initConnectTabAddVertex() {
    connect(ui->pushButton_generate_add,SIGNAL(clicked()),
            this,SLOT(onGraphGenerateAdd()));

    connect(ui->pushButton_add_edge,SIGNAL(clicked()),
            this,SLOT(onPushButtonAddEdgeClicked()));
}

void MainWindow::initConnectTabRandom() {

    connect(ui->pushButton_full_rnd,SIGNAL(clicked()),
            this,SLOT(onGraphGenerateRandom()));

    connect(ui->pushButton_generate_rnd,SIGNAL(clicked()),
            this,SLOT(onGraphGenerateRandom()));
}

void MainWindow::initConnectBlockControl() {
    connect(ui->pushButton_skip,SIGNAL(clicked()),
            this,SLOT(testSlot()));

    connect(ui->pushButton_start,SIGNAL(clicked()),
            this,SLOT(testSlot()));

    connect(ui->pushButton_step_back,SIGNAL(clicked()),
            this,SLOT(testSlot()));

    connect(ui->pushButton_step_forward,SIGNAL(clicked()),
            this,SLOT(testSlot()));
}

void MainWindow::onGraphGenerateAdd() {
    if(ui_slave!= nullptr){
        delete ui_slave;
    }

    ui_slave = new Algorithm(controllerUi.initAdd(list_edge,ui->spinBox_enter_city_add->value()),
                             controllerUi.settings.population_size);
}
void MainWindow::onGraphGenerateRandom() {
    if(ui_slave!= nullptr){
        delete ui_slave;
    }
    ui_slave = new Algorithm(controllerUi.initRandom(ui->spinBox_enter_city_rnd->value()),
                             controllerUi.settings.population_size);

    //std::cout<<"work\n";
}
void MainWindow::onGraphGenerateFile() {

    if(ui_slave!= nullptr){
        delete ui_slave;
    }

    ui_slave = new Algorithm(controllerUi.initFile(ui->label_chosen_file->text().toStdString()),
                             controllerUi.settings.population_size);
}
void MainWindow::testSlot() {
    std::cout<<"hohohohohoho"<<"\n";
}


void MainWindow::onSaveClicked() {
    controllerUi.settings.count_crossover = ui->spinBox_user_count_crossingover->value();
    controllerUi.settings.probability = ui->doubleSpinBox_p_mutation->value();
    controllerUi.settings.population_size = ui->spinBox_user_count_population->value();
    //check


    QString str = "Your data: cross_dot = " + QString::number(controllerUi.settings.count_crossover)
            + ", population_size = " + QString::number(controllerUi.settings.population_size)
            + ", probability = " + QString::number(controllerUi.settings.probability);
    ui->label_settings->setText(str);
}


