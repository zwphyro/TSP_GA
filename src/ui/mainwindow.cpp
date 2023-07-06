#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qcustomplot.h>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    layout = new QVBoxLayout(this);
    ui->scrollAreaWidgetContents->setLayout(layout);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    initConnectTabFile();
    initConnectBlockControl();
    initConnectTabAddVertex();
    initConnectTabRandom();
    initConnectRadioButton();

    connect(ui->pushButton_save, SIGNAL(clicked()), this, SLOT(onSaveClicked()));
    //connect(ui->pushButton_plot)

    ui->scrollArea_list_of_edge->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea_list_of_edge->setWidgetResizable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onPushButtonAddEdgeClicked()
{

    int index = controllerUi.check.addEdge(list_edge, ui->spinBox_distance_between_cities->value(),
                                           ui->spinBox_departure_city->value(),
                                           ui->spinBox_arrival_city->value(),
                                           ui->spinBox_enter_city_add->value());

    if (index == -2)
    {
        QMessageBox::warning(this, "Внимание", "Не существует города с данным индексом");
        return;
    }

    if (index != -1)
    {
        QLayoutItem *item;
        item = layout->takeAt(index);
        delete item->widget();
        delete item;
    }
    QString added_line = QString::number(ui->spinBox_departure_city->value()) + " -> "
                         + QString::number(ui->spinBox_arrival_city->value()) + ": weight = "
                         + QString::number(ui->spinBox_distance_between_cities->value());
    QLabel *label_added = new QLabel(added_line);
    layout->addWidget(label_added);

    for (int i = 0; i < list_edge.size(); i++)
    {
        std::cout << list_edge[i].second.first << list_edge[i].second.second << list_edge[i].first;
    }
    std::cout << "\n";


}


void MainWindow::onFileChoose()
{
    QString str = QFileDialog::getOpenFileName(0, "Выбор папки", "", "*txt");
    ui->label_chosen_file->setText(str);
}

void MainWindow::initConnectTabFile()
{
    connect(ui->pushButton_choose_file, SIGNAL(clicked()),
            this, SLOT(onFileChoose()));
    connect(ui->pushButton_generate_file, SIGNAL(clicked()),
            this, SLOT(onGraphGenerateFile()));
}

void MainWindow::initConnectTabAddVertex()
{
    connect(ui->pushButton_generate_add, SIGNAL(clicked()),
            this, SLOT(onGraphGenerateAdd()));

    connect(ui->pushButton_add_edge, SIGNAL(clicked()),
            this, SLOT(onPushButtonAddEdgeClicked()));
}

void MainWindow::initConnectTabRandom()
{
    connect(ui->pushButton_full_rnd, SIGNAL(clicked()),
            this, SLOT(onFullRandomClicked()));

    connect(ui->pushButton_generate_rnd, SIGNAL(clicked()),
            this, SLOT(onGraphGenerateRandom()));
}

void MainWindow::initConnectBlockControl()
{
    connect(ui->pushButton_skip, SIGNAL(clicked()),
            this, SLOT(onSkipClicked()));

    connect(ui->pushButton_start, SIGNAL(clicked()),
            this, SLOT(onStartClicked()));

    connect(ui->pushButton_step_back, SIGNAL(clicked()),
            this, SLOT(onPrevClicked()));

    connect(ui->pushButton_step_forward, SIGNAL(clicked()),
            this, SLOT(onNextClicked()));
}

void MainWindow::initConnectRadioButton(){
    connect(ui->radioButton_full_population, SIGNAL(clicked()), this, SLOT(radioButtonClicked()));
    connect(ui->radioButton_best_individual, SIGNAL(clicked()), this, SLOT(radioButtonClicked()));
    connect(ui->radioButton_worst_individual, SIGNAL(clicked()), this, SLOT(radioButtonClicked()));
    connect(ui->radioButton_mutation_standart,SIGNAL(clicked()),this,SLOT(onMutationRadioButtonClicked()));
    connect(ui->radioButton_mutation_mix,SIGNAL(clicked()),this,SLOT(onMutationRadioButtonClicked()));
    connect(ui->radioButton_mutation_reverse,SIGNAL(clicked()),this,SLOT(onMutationRadioButtonClicked()));
}

void MainWindow::onGraphGenerateAdd()
{
    if (!controllerUi.initAdd(list_edge, ui->spinBox_enter_city_add->value()))
    {
        QMessageBox::warning(this, "Внимание", "Граф не очень, но мы поправили");
    }

    list_edge.resize(0);
    if (layout != NULL)
    {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != NULL)
        {
            delete item->widget();
            delete item;
        }
    }

    drawGraph();
}

void MainWindow::onGraphGenerateRandom()
{
    if (!controllerUi.initRandom(ui->spinBox_enter_city_rnd->value()))
    {
        QMessageBox::warning(this, "Внимание", "Граф не очень, но мы поправили");
    }
    drawGraph();
}

void MainWindow::onFullRandomClicked() {
    if (!controllerUi.initRandom(0))
    {
        QMessageBox::warning(this, "Внимание", "Граф не очень, но мы поправили");
    }
    drawGraph();
}
void MainWindow::onGraphGenerateFile()
{
    if (!controllerUi.initFile(ui->label_chosen_file->text().toStdString()))
    {
        QMessageBox::warning(this, "Внимание", "Граф не очень, но мы поправили");
    }
    drawGraph();
}

void MainWindow::radioButtonClicked()
{
    if (ui_slave == nullptr)//nothing to draw
        return;
    chooseWhatToDraw();
}

void MainWindow::onMutationRadioButtonClicked(){
    if(ui->radioButton_mutation_standart->isChecked()){
        controllerUi.settings.mutation = 1;
        return;
    }
    if(ui->radioButton_mutation_reverse->isChecked()){
        controllerUi.settings.mutation = 2;
        return;
    }
    if(ui->radioButton_mutation_mix->isChecked()){
        controllerUi.settings.mutation = 3;
        return;
    }

}

void MainWindow::onSaveClicked()
{
    controllerUi.settings.count_crossover = ui->spinBox_user_count_crossingover->value();
    controllerUi.settings.probability = ui->doubleSpinBox_p_mutation->value();
    controllerUi.settings.population_size = ui->spinBox_user_count_population->value();


    if (controllerUi.settings.count_crossover != 1 && controllerUi.settings.count_crossover != 2 ||
        controllerUi.settings.probability > 1.0 && controllerUi.settings.probability < 0.0 ||
        controllerUi.settings.population_size <= 0
            )
    {
        QMessageBox::warning(this, "Внимание", "Настройки не очень, но мы поправили");
        controllerUi.settings.count_crossover = 1;
        controllerUi.settings.probability = 1.0;
        controllerUi.settings.population_size = 10;
    }

    QString str = "Your data: cross_dot = " + QString::number(controllerUi.settings.count_crossover)
                  + ", population_size = " + QString::number(controllerUi.settings.population_size)
                  + ", probability = " + QString::number(controllerUi.settings.probability);
    ui->label_settings->setText(str);
}


void MainWindow::onStartClicked()
{
    // std::cout << "start\n";

    if (ui_slave != nullptr)
    {
        delete ui_slave;
    }
    if (controllerUi.getGraph().size() == 0)
    {
        QMessageBox::warning(this, "Внимание", "Граф не задан");
        return;
    }
    ui_slave = new Algorithm(controllerUi.getGraph(),
                             controllerUi.settings);

    chooseWhatToDraw();
}

void MainWindow::onNextClicked()
{
    std::cout << "next\n";
    if (ui_slave != nullptr)
    {
        std::cout << "not null\n";
        if (ui_slave->switchToNextPopulation() == 0)
        {
            std::cout << "next exist\n";

            chooseWhatToDraw();
        }
    }


}

void MainWindow::onPrevClicked()
{
    //std::cout<<"prev\n";
    if (ui_slave)
    {
        //check;
        if (ui_slave->switchToPreviousPopulation() == 0)
        {
            chooseWhatToDraw();
        }
    }

}

void MainWindow::onSkipClicked()
{
    //std::cout<<"skip\n";

    if (ui_slave)
    {
        //check;
        ui_slave->switchToLastPopulation();
    }
    chooseWhatToDraw();
}


void MainWindow::drawGraph()
{

    if (!list_point)
        delete list_point;


    scene->clear();

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);


    unsigned n = controllerUi.getGraph().size();
    list_point = new Point[n];
    double angle = 0;
    unsigned main_radius = 120;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << controllerUi.getGraph()[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        list_point[i].x = main_radius * cos(angle * 3.14 / 180);
        list_point[i].y = main_radius * sin(angle * 3.14 / 180);
        angle = angle + 360.0 / n;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            //std::cout<<ui_slave->graph[i][j];
            if (controllerUi.getGraph()[i][j] != 0 && controllerUi.getGraph()[i][j] != INT_MAX)
            {
                scene->addLine(list_point[i].x + CONST_SHIFT_LINE, list_point[i].y + CONST_SHIFT_LINE,
                               list_point[j].x + CONST_SHIFT_LINE, list_point[j].y + CONST_SHIFT_LINE);

            }
        }
    }


    drawPoints(n);

}

void MainWindow::drawPoints(int n)
{
    unsigned point_radius = 40;
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    for (int i = 0; i < n; i++)
    {
        scene->addEllipse(list_point[i].x, list_point[i].y, point_radius, point_radius,
                          outlinePen, Qt::white);
        text = scene->addText(QString::number(i));
        text->setPos(list_point[i].x + CONST_SHIFT_TEXT, list_point[i].y + CONST_SHIFT_TEXT);
    }
}


void MainWindow::drawIndividual()
{

    scene->clear();
    if (!ui_slave)
        return;
    //scene->update();


    int n = controllerUi.getGraph().size();
    if (!list_point)
    {
        //error mes
        return;
    }

    QPen outlinePen(Qt::red);
    outlinePen.setWidth(2);


    if (ui->radioButton_best_individual->isChecked())
    {
        for (int i = 0; i < n - 1; i++)
        {
            int first_element = ui_slave->getCurrentPopulation().getBestIndividual().first[i];
            int second_element = ui_slave->getCurrentPopulation().getBestIndividual().first[i + 1];

            scene->addLine(list_point[first_element].x + CONST_SHIFT_LINE,
                           list_point[first_element].y + CONST_SHIFT_LINE,
                           list_point[second_element].x + CONST_SHIFT_LINE,
                           list_point[second_element].y + CONST_SHIFT_LINE,
                           outlinePen);
            scene->addText(QString::number(controllerUi.getGraph()[first_element][second_element]))
                    ->setPos((list_point[first_element].x + list_point[second_element].x) / 2,
                             (list_point[first_element].y + list_point[second_element].y) / 2);
        }

        int start_element = ui_slave->getCurrentPopulation().getBestIndividual().first[0];
        int end_element = ui_slave->getCurrentPopulation().getBestIndividual().first[n - 1];

        scene->addLine(list_point[start_element].x + CONST_SHIFT_LINE,
                       list_point[start_element].y + CONST_SHIFT_LINE,
                       list_point[end_element].x + CONST_SHIFT_LINE,
                       list_point[end_element].y + CONST_SHIFT_LINE,
                       outlinePen);
        scene->addText(QString::number(controllerUi.getGraph()[start_element][end_element]))
                ->setPos((list_point[start_element].x + list_point[end_element].x) / 2,
                         (list_point[start_element].y + list_point[end_element].y) / 2);

    } else
    {

        for (int i = 0; i < n - 1; i++)
        {
            int first_element = ui_slave->getCurrentPopulation().getWorstIndividual().first[i];
            int second_element = ui_slave->getCurrentPopulation().getWorstIndividual().first[i + 1];

            scene->addLine(list_point[first_element].x + CONST_SHIFT_LINE,
                           list_point[first_element].y + CONST_SHIFT_LINE,
                           list_point[second_element].x + CONST_SHIFT_LINE,
                           list_point[second_element].y + CONST_SHIFT_LINE,
                           outlinePen);
            scene->addText(QString::number(controllerUi.getGraph()[first_element][second_element]))
                    ->setPos((list_point[first_element].x + list_point[second_element].x) / 2,
                             (list_point[first_element].y + list_point[second_element].y) / 2);
        }

        int start_element = ui_slave->getCurrentPopulation().getWorstIndividual().first[0];
        int end_element = ui_slave->getCurrentPopulation().getWorstIndividual().first[n - 1];

        scene->addLine(list_point[start_element].x + CONST_SHIFT_LINE,
                       list_point[start_element].y + CONST_SHIFT_LINE,
                       list_point[end_element].x + CONST_SHIFT_LINE,
                       list_point[end_element].y + CONST_SHIFT_LINE,
                       outlinePen);
        scene->addText(QString::number(controllerUi.getGraph()[start_element][end_element]))
                ->setPos((list_point[start_element].x + list_point[end_element].x) / 2,
                         (list_point[start_element].y + list_point[end_element].y) / 2);

    }

    drawPoints(n);


}

void MainWindow::drawPopulation()
{
    scene->clear();

    if (!ui_slave)
        return;
    int N = ui_slave->getCurrentPopulation().size();

    for (int i = 0; i < N; i++)
    {
        QString str = QString::number(i + 1) + ") ";
        for (int j = 0; j < controllerUi.getGraph().size(); j++)
        {

            str += QString::number(ui_slave->getCurrentPopulation().getIndividuals()[i][j]);
            if (j != controllerUi.getGraph().size() - 1)
                str += " -> ";
            else
                str += ": ";
        }
        str += QString::number(ui_slave->getCurrentPopulation().getFitnessValues()[i]);
        scene->addText(str)->setPos(-CONST_SCENE_WIDTH, 30 * i - CONST_SCENE_HEIGHT);

    }

}

void MainWindow::chooseWhatToDraw()
{

    std::cout << "choose draw type\n";

    if (ui->radioButton_best_individual->isChecked())
    {
        std::cout << "choosen best\n";
        drawIndividual();
    } else if (ui->radioButton_worst_individual->isChecked())
    {
        std::cout << "choosen worst\n";
        drawIndividual();
    } else if (ui->radioButton_full_population->isChecked())
    {
        std::cout << "choosen full\n";
        drawPopulation();
    } else
    {
        QMessageBox::warning(this, "Внимание", "Вы не выбрали что выводить");
    }

}


