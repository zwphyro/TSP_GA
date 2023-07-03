/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_add_vertex;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_add;
    QHBoxLayout *horizontalLayout_add_enter_city;
    QLabel *label_enter_city_add_2;
    QSpinBox *spinBox_enter_city_add;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_add_enter_edge;
    QSpinBox *spinBox_departure_city;
    QSpinBox *spinBox_arrival_city;
    QSpinBox *spinBox_distance_between_cities;
    QPushButton *pushButton_add_edge;
    QPushButton *pushButton_generate_add;
    QWidget *widget;
    QScrollArea *scrollArea_list_of_edge;
    QWidget *scrollAreaWidgetContents;
    QWidget *tab_random;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_random;
    QPushButton *pushButton_full_rnd;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_enter_city_rnd;
    QSpinBox *spinBox_enter_city_rnd;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_generate_rnd;
    QWidget *tab_file;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_file;
    QHBoxLayout *horizontalLayout_choose_file;
    QPushButton *pushButton_choose_file;
    QLabel *label_chosen_file;
    QPushButton *pushButton_generate_file;
    QWidget *tab_settings;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBox_user_count_crossingover;
    QSpinBox *spinBox_user_count_population;
    QDoubleSpinBox *doubleSpinBox_p_mutation;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QRadioButton *radioButton_roulette;
    QRadioButton *radioButton_outbreeding;
    QFrame *frame_algorithm_demonstartion;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_control;
    QPushButton *pushButton_start;
    QPushButton *pushButton_step_forward;
    QPushButton *pushButton_step_back;
    QPushButton *pushButton_skip;
    QLabel *label_4;
    QRadioButton *radioButton_best_individual;
    QRadioButton *radioButton_full_population;
    QRadioButton *radioButton_worst_individual;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(801, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 801, 201));
        tab_add_vertex = new QWidget();
        tab_add_vertex->setObjectName(QString::fromUtf8("tab_add_vertex"));
        verticalLayoutWidget_3 = new QWidget(tab_add_vertex);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(20, 0, 280, 161));
        verticalLayout_add = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_add->setObjectName(QString::fromUtf8("verticalLayout_add"));
        verticalLayout_add->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_add_enter_city = new QHBoxLayout();
        horizontalLayout_add_enter_city->setObjectName(QString::fromUtf8("horizontalLayout_add_enter_city"));
        label_enter_city_add_2 = new QLabel(verticalLayoutWidget_3);
        label_enter_city_add_2->setObjectName(QString::fromUtf8("label_enter_city_add_2"));

        horizontalLayout_add_enter_city->addWidget(label_enter_city_add_2);

        spinBox_enter_city_add = new QSpinBox(verticalLayoutWidget_3);
        spinBox_enter_city_add->setObjectName(QString::fromUtf8("spinBox_enter_city_add"));
        spinBox_enter_city_add->setMaximum(100000);

        horizontalLayout_add_enter_city->addWidget(spinBox_enter_city_add);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_add_enter_city->addItem(horizontalSpacer_2);


        verticalLayout_add->addLayout(horizontalLayout_add_enter_city);

        horizontalLayout_add_enter_edge = new QHBoxLayout();
        horizontalLayout_add_enter_edge->setObjectName(QString::fromUtf8("horizontalLayout_add_enter_edge"));
        spinBox_departure_city = new QSpinBox(verticalLayoutWidget_3);
        spinBox_departure_city->setObjectName(QString::fromUtf8("spinBox_departure_city"));

        horizontalLayout_add_enter_edge->addWidget(spinBox_departure_city);

        spinBox_arrival_city = new QSpinBox(verticalLayoutWidget_3);
        spinBox_arrival_city->setObjectName(QString::fromUtf8("spinBox_arrival_city"));

        horizontalLayout_add_enter_edge->addWidget(spinBox_arrival_city);

        spinBox_distance_between_cities = new QSpinBox(verticalLayoutWidget_3);
        spinBox_distance_between_cities->setObjectName(QString::fromUtf8("spinBox_distance_between_cities"));

        horizontalLayout_add_enter_edge->addWidget(spinBox_distance_between_cities);

        pushButton_add_edge = new QPushButton(verticalLayoutWidget_3);
        pushButton_add_edge->setObjectName(QString::fromUtf8("pushButton_add_edge"));

        horizontalLayout_add_enter_edge->addWidget(pushButton_add_edge);


        verticalLayout_add->addLayout(horizontalLayout_add_enter_edge);

        pushButton_generate_add = new QPushButton(verticalLayoutWidget_3);
        pushButton_generate_add->setObjectName(QString::fromUtf8("pushButton_generate_add"));

        verticalLayout_add->addWidget(pushButton_generate_add);

        widget = new QWidget(tab_add_vertex);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(370, 10, 411, 151));
        scrollArea_list_of_edge = new QScrollArea(widget);
        scrollArea_list_of_edge->setObjectName(QString::fromUtf8("scrollArea_list_of_edge"));
        scrollArea_list_of_edge->setGeometry(QRect(0, 0, 411, 151));
        scrollArea_list_of_edge->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_list_of_edge->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 393, 149));
        scrollArea_list_of_edge->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(tab_add_vertex, QString());
        tab_random = new QWidget();
        tab_random->setObjectName(QString::fromUtf8("tab_random"));
        verticalLayoutWidget_2 = new QWidget(tab_random);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 411, 161));
        verticalLayout_random = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_random->setObjectName(QString::fromUtf8("verticalLayout_random"));
        verticalLayout_random->setContentsMargins(0, 0, 0, 0);
        pushButton_full_rnd = new QPushButton(verticalLayoutWidget_2);
        pushButton_full_rnd->setObjectName(QString::fromUtf8("pushButton_full_rnd"));

        verticalLayout_random->addWidget(pushButton_full_rnd);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_random->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_enter_city_rnd = new QLabel(verticalLayoutWidget_2);
        label_enter_city_rnd->setObjectName(QString::fromUtf8("label_enter_city_rnd"));

        horizontalLayout_2->addWidget(label_enter_city_rnd);

        spinBox_enter_city_rnd = new QSpinBox(verticalLayoutWidget_2);
        spinBox_enter_city_rnd->setObjectName(QString::fromUtf8("spinBox_enter_city_rnd"));
        spinBox_enter_city_rnd->setMaximum(100000);

        horizontalLayout_2->addWidget(spinBox_enter_city_rnd);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_random->addLayout(horizontalLayout_2);

        pushButton_generate_rnd = new QPushButton(verticalLayoutWidget_2);
        pushButton_generate_rnd->setObjectName(QString::fromUtf8("pushButton_generate_rnd"));

        verticalLayout_random->addWidget(pushButton_generate_rnd);

        tabWidget->addTab(tab_random, QString());
        tab_file = new QWidget();
        tab_file->setObjectName(QString::fromUtf8("tab_file"));
        verticalLayoutWidget_4 = new QWidget(tab_file);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 0, 541, 121));
        verticalLayout_file = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_file->setObjectName(QString::fromUtf8("verticalLayout_file"));
        verticalLayout_file->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_choose_file = new QHBoxLayout();
        horizontalLayout_choose_file->setObjectName(QString::fromUtf8("horizontalLayout_choose_file"));
        pushButton_choose_file = new QPushButton(verticalLayoutWidget_4);
        pushButton_choose_file->setObjectName(QString::fromUtf8("pushButton_choose_file"));

        horizontalLayout_choose_file->addWidget(pushButton_choose_file);

        label_chosen_file = new QLabel(verticalLayoutWidget_4);
        label_chosen_file->setObjectName(QString::fromUtf8("label_chosen_file"));

        horizontalLayout_choose_file->addWidget(label_chosen_file);


        verticalLayout_file->addLayout(horizontalLayout_choose_file);

        pushButton_generate_file = new QPushButton(verticalLayoutWidget_4);
        pushButton_generate_file->setObjectName(QString::fromUtf8("pushButton_generate_file"));

        verticalLayout_file->addWidget(pushButton_generate_file);

        tabWidget->addTab(tab_file, QString());
        tab_settings = new QWidget();
        tab_settings->setObjectName(QString::fromUtf8("tab_settings"));
        verticalLayoutWidget_5 = new QWidget(tab_settings);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(20, 10, 271, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget_5);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_5 = new QLabel(verticalLayoutWidget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        verticalLayoutWidget_6 = new QWidget(tab_settings);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(310, 10, 58, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBox_user_count_crossingover = new QSpinBox(verticalLayoutWidget_6);
        spinBox_user_count_crossingover->setObjectName(QString::fromUtf8("spinBox_user_count_crossingover"));
        spinBox_user_count_crossingover->setMinimum(1);
        spinBox_user_count_crossingover->setMaximum(2);

        verticalLayout_2->addWidget(spinBox_user_count_crossingover);

        spinBox_user_count_population = new QSpinBox(verticalLayoutWidget_6);
        spinBox_user_count_population->setObjectName(QString::fromUtf8("spinBox_user_count_population"));

        verticalLayout_2->addWidget(spinBox_user_count_population);

        doubleSpinBox_p_mutation = new QDoubleSpinBox(verticalLayoutWidget_6);
        doubleSpinBox_p_mutation->setObjectName(QString::fromUtf8("doubleSpinBox_p_mutation"));
        doubleSpinBox_p_mutation->setMaximum(1.000000000000000);
        doubleSpinBox_p_mutation->setSingleStep(0.100000000000000);

        verticalLayout_2->addWidget(doubleSpinBox_p_mutation);

        verticalLayoutWidget_7 = new QWidget(tab_settings);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(400, 10, 241, 91));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(verticalLayoutWidget_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        radioButton_roulette = new QRadioButton(verticalLayoutWidget_7);
        radioButton_roulette->setObjectName(QString::fromUtf8("radioButton_roulette"));

        verticalLayout_3->addWidget(radioButton_roulette);

        radioButton_outbreeding = new QRadioButton(verticalLayoutWidget_7);
        radioButton_outbreeding->setObjectName(QString::fromUtf8("radioButton_outbreeding"));

        verticalLayout_3->addWidget(radioButton_outbreeding);

        tabWidget->addTab(tab_settings, QString());
        frame_algorithm_demonstartion = new QFrame(centralwidget);
        frame_algorithm_demonstartion->setObjectName(QString::fromUtf8("frame_algorithm_demonstartion"));
        frame_algorithm_demonstartion->setGeometry(QRect(20, 220, 461, 301));
        frame_algorithm_demonstartion->setFrameShape(QFrame::StyledPanel);
        frame_algorithm_demonstartion->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(500, 220, 291, 251));
        verticalLayout_control = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_control->setObjectName(QString::fromUtf8("verticalLayout_control"));
        verticalLayout_control->setContentsMargins(0, 0, 0, 0);
        pushButton_start = new QPushButton(verticalLayoutWidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));

        verticalLayout_control->addWidget(pushButton_start);

        pushButton_step_forward = new QPushButton(verticalLayoutWidget);
        pushButton_step_forward->setObjectName(QString::fromUtf8("pushButton_step_forward"));

        verticalLayout_control->addWidget(pushButton_step_forward);

        pushButton_step_back = new QPushButton(verticalLayoutWidget);
        pushButton_step_back->setObjectName(QString::fromUtf8("pushButton_step_back"));

        verticalLayout_control->addWidget(pushButton_step_back);

        pushButton_skip = new QPushButton(verticalLayoutWidget);
        pushButton_skip->setObjectName(QString::fromUtf8("pushButton_skip"));

        verticalLayout_control->addWidget(pushButton_skip);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_control->addWidget(label_4);

        radioButton_best_individual = new QRadioButton(verticalLayoutWidget);
        radioButton_best_individual->setObjectName(QString::fromUtf8("radioButton_best_individual"));

        verticalLayout_control->addWidget(radioButton_best_individual);

        radioButton_full_population = new QRadioButton(verticalLayoutWidget);
        radioButton_full_population->setObjectName(QString::fromUtf8("radioButton_full_population"));

        verticalLayout_control->addWidget(radioButton_full_population);

        radioButton_worst_individual = new QRadioButton(verticalLayoutWidget);
        radioButton_worst_individual->setObjectName(QString::fromUtf8("radioButton_worst_individual"));

        verticalLayout_control->addWidget(radioButton_worst_individual);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 801, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_add_edge, SIGNAL(clicked()), MainWindow, SLOT(show()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_enter_city_add_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\263\320\276\321\200\320\276\320\264\320\276\320\262", nullptr));
        pushButton_add_edge->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_generate_add->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_add_vertex), QCoreApplication::translate("MainWindow", "Add vertex", nullptr));
        pushButton_full_rnd->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\321\213\320\271 \321\200\320\260\320\275\320\264\320\276\320\274", nullptr));
        label_enter_city_rnd->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\263\320\276\321\200\320\276\320\264\320\276\320\262", nullptr));
        pushButton_generate_rnd->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_random), QCoreApplication::translate("MainWindow", "Random", nullptr));
        pushButton_choose_file->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        label_chosen_file->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\320\275\321\213\320\271 \321\204\320\260\320\271\320\273", nullptr));
        pushButton_generate_file->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_file), QCoreApplication::translate("MainWindow", "File", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273-\320\262\320\276 \321\202\320\276\321\207\320\265\320\272 \320\272\321\200\320\276\321\201\321\201\320\270\320\275\320\263\320\276\320\262\320\265\321\200\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\276\321\201\320\276\320\261\320\265\320\271 \320\262 \320\277\320\276\320\277\321\203\320\273\321\217\321\206\320\270\320\270", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\321\214 \320\274\321\203\321\202\320\260\321\206\320\270\320\270", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\274\320\265\321\202\320\276\320\264 \320\262\321\213\320\261\320\276\321\200\320\260 \321\200\320\276\320\264\320\270\321\202\320\265\320\273\320\265\320\271:", nullptr));
        radioButton_roulette->setText(QCoreApplication::translate("MainWindow", "\320\274\320\265\321\202\320\276\320\264 \321\200\321\203\320\273\320\265\321\202\320\272\320\270", nullptr));
        radioButton_outbreeding->setText(QCoreApplication::translate("MainWindow", "\320\260\321\203\321\202\320\261\321\200\320\270\320\264\320\270\320\275\320\263", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_settings), QCoreApplication::translate("MainWindow", "Settings", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        pushButton_step_forward->setText(QCoreApplication::translate("MainWindow", "->", nullptr));
        pushButton_step_back->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        pushButton_skip->setText(QCoreApplication::translate("MainWindow", "skip", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        radioButton_best_individual->setText(QCoreApplication::translate("MainWindow", "Best individual", nullptr));
        radioButton_full_population->setText(QCoreApplication::translate("MainWindow", "Full population", nullptr));
        radioButton_worst_individual->setText(QCoreApplication::translate("MainWindow", "Worst individual", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
