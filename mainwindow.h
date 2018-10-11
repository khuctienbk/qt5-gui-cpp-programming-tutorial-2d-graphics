#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnHypocloid_clicked();

    void on_btnCycloid_clicked();

    void on_btnAstroid_clicked();

    void on_btnHuygens_clicked();

    void on_btnLine_clicked();

    void on_spinScale_valueChanged(double scale);

    void on_spinIntervalLength_valueChanged(double intervalLenth);

    void on_spinStepCount_valueChanged(int stepCount);

    void on_btnBackground_clicked();

    void on_btnLineColor_clicked();

    void on_btnCircle_clicked();

    void on_btnEllipse_clicked();

    void on_btnFancy_clicked();

    void on_btnStarfish_clicked();

    void on_spinStepCount_valueChanged(const QString &arg1);

private:
    void update_ui();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
