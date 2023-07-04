#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    layout = new QVBoxLayout(this);
    ui->scrollAreaWidgetContents->setLayout(layout);

    //paint = new PaintWidget(ui->widget_algorithm_demonstartion);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


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
            this,SLOT(onStartClicked()));

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
    drawGraph();
}
void MainWindow::onGraphGenerateRandom() {
    if(ui_slave!= nullptr){
        delete ui_slave;
    }
    ui_slave = new Algorithm(controllerUi.initRandom(ui->spinBox_enter_city_rnd->value()),
                             controllerUi.settings.population_size);

    drawGraph();

}
void MainWindow::onGraphGenerateFile() {

    if(ui_slave!= nullptr){
        delete ui_slave;
    }

    ui_slave = new Algorithm(controllerUi.initFile(ui->label_chosen_file->text().toStdString()),
                             controllerUi.settings.population_size);



    drawGraph();
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



void MainWindow::drawGraph(){

    scene->clear();

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);


    unsigned n = ui_slave->graph.size();
    Point *list_point = new Point[n];
    double angle = 0;
    unsigned main_radius = 120;
    unsigned point_radius = 40;


    for(int i = 0; i < n; i++){
        list_point[i].x = main_radius*cos(angle*3.14/180);
        list_point[i].y = main_radius*sin(angle*3.14/180);
        angle = angle + 360.0/n;
    }

    for(int i = 0; i < n; i++){
        for(int j = i ; j < n; j++){
            //std::cout<<ui_slave->graph[i][j];
            if(ui_slave->graph[i][j]!=0 && ui_slave->graph[i][j]!=INT_MAX){
                scene->addLine(list_point[i].x + CONST_SHIFT_LINE,list_point[i].y + CONST_SHIFT_LINE,
                               list_point[j].x + CONST_SHIFT_LINE,list_point[j].y + CONST_SHIFT_LINE);
            }
        }
    }

    for(int i = 0; i < n; i++){
        scene -> addEllipse(list_point[i].x,list_point[i].y ,point_radius, point_radius,
                            outlinePen, Qt::white);
        text = scene ->addText(QString::number(i));
        text->setPos(list_point[i].x + CONST_SHIFT_TEXT,list_point[i].y + CONST_SHIFT_TEXT);
    }

    //rectangle = scene->addRect(100, 0, 80, 100, outlinePen, blueBrush);

}

void MainWindow::onStartClicked() {


}