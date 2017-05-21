#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnUni2Telex_clicked();

    void on_btnUni2VNI_clicked();

    void on_btnTelex2VNI_clicked();

    void on_btnTelex2Uni_clicked();

    void on_btnVNI2Uni_clicked();

    void on_btnVNI2Telex_clicked();

    void on_btnBrowse_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
