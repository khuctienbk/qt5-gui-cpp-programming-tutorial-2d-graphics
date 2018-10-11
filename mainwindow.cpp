#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->spinScale->setValue(this->ui->renderArea->scale());
    this->ui->spinIntervalLength->setValue(this->ui->renderArea->intervalLength());
    this->ui->spinStepCount->setValue(this->ui->renderArea->stepCount());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui()
{
    this->ui->spinScale->setValue(this->ui->renderArea->scale());
    this->ui->spinIntervalLength->setValue(this->ui->renderArea->intervalLength());
    this->ui->spinStepCount->setValue(this->ui->renderArea->stepCount());
}


void MainWindow::on_btnHypocloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);

    update_ui();

}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);

    update_ui();
}

void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Asteroid);

    update_ui();}

void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);

    update_ui();
}

void MainWindow::on_btnLine_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);

    update_ui();
}

void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);
}

void MainWindow::on_spinIntervalLength_valueChanged(double intervalLength)
{
    this->ui->renderArea->setIntervalLength(intervalLength);
}

void MainWindow::on_spinStepCount_valueChanged(int stepCount)
{
    this->ui->renderArea->setStepCount(stepCount);
}

void MainWindow::on_btnBackground_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderArea->backgroundColor(), this, "Select color");
    ui->renderArea->setBackgroundColor(color);

}

void MainWindow::on_btnLineColor_clicked()
{
    QColor shapeColor = QColorDialog::getColor(ui->renderArea->shapeColor(), this, "Select color");
    ui->renderArea->setShapeColor(shapeColor);
}

void MainWindow::on_btnCircle_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Circle);

    update_ui();
}

void MainWindow::on_btnEllipse_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Elipse);

    update_ui();
}

void MainWindow::on_btnFancy_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Fancy);

    update_ui();
}

void MainWindow::on_btnStarfish_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Starfish);

    update_ui();
}

