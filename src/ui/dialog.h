//
// Created by Маргарита  on 06.07.2023.
//

#ifndef TSP_GA_DIALOG_H
#define TSP_GA_DIALOG_H

#include <QWidget>

#include <QDialog>
#include <QGraphicsScene>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog {
Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    ~Dialog() override;

    void drawPlot(const std::vector<int> elements);

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;

};


#endif //TSP_GA_DIALOG_H
