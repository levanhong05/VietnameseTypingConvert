#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include "converter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnUni2Telex_clicked()
{
    QString path = ui->txtFileName->text();

    if (path != "") {
        QFile file(path);

        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }

        QTextStream in(&file);
        in.setCodec("UTF-8");

        QFile outFile(path.mid(0, path.lastIndexOf("/") + 1) + "promts_uni2telex.txt");
        outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);

        QTextStream out(&outFile);
        out.setCodec("UTF-8");

        QString line = "";
        Converter *convert = new Converter();

        ui->plainTextEdit->clear();

        while (!in.atEnd()) {
            line = in.readLine();

            QString result = convert->convertUnicode2Telex(line);

            out << result << endl;
            ui->plainTextEdit->appendPlainText(result + "\n");
        }

        QMessageBox::information(this, tr("Convert Data"), tr("Convert data successfully."));
    }
}

void MainWindow::on_btnUni2VNI_clicked()
{
    QString path = ui->txtFileName->text();

    if (path != "") {
        QFile file(path);

        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }

        QTextStream in(&file);
        in.setCodec("UTF-8");

        QFile outFile(path.mid(0, path.lastIndexOf("/") + 1) + "promts_uni2vni.txt");
        outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);

        QTextStream out(&outFile);
        out.setCodec("UTF-8");

        QString line = "";
        Converter *convert = new Converter();

        ui->plainTextEdit->clear();

        while (!in.atEnd()) {
            line = in.readLine();

            QString result = convert->convertUnicode2VNI(line);

            out << result << endl;
            ui->plainTextEdit->appendPlainText(result + "\n");
        }

        QMessageBox::information(this, tr("Convert Data"), tr("Convert data successfully."));
    }
}

void MainWindow::on_btnTelex2VNI_clicked()
{
    QString path = ui->txtFileName->text();

    if (path != "") {
        QFile file(path);

        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }

        QTextStream in(&file);
        in.setCodec("UTF-8");

        QFile outFile(path.mid(0, path.lastIndexOf("/") + 1) + "promts_telex2vni.txt");
        outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);

        QTextStream out(&outFile);
        out.setCodec("UTF-8");

        QString line = "";
        Converter *convert = new Converter();

        ui->plainTextEdit->clear();

        while (!in.atEnd()) {
            line = in.readLine();

            QString result = convert->convertTelex2VNI(line);

            out << result << endl;
            ui->plainTextEdit->appendPlainText(result + "\n");
        }

        QMessageBox::information(this, tr("Convert Data"), tr("Convert data successfully."));
    }
}

void MainWindow::on_btnTelex2Uni_clicked()
{
    QString path = ui->txtFileName->text();

    if (path != "") {
        QFile file(path);

        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }

        QTextStream in(&file);
        in.setCodec("UTF-8");

        QFile outFile(path.mid(0, path.lastIndexOf("/") + 1) + "promts_telex2uni.txt");
        outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);

        QTextStream out(&outFile);
        out.setCodec("UTF-8");

        QString line = "";
        Converter *convert = new Converter();

        ui->plainTextEdit->clear();

        while (!in.atEnd()) {
            line = in.readLine();

            QString result = convert->convertTelex2Unicode(line);

            out << result << endl;
            ui->plainTextEdit->appendPlainText(result + "\n");
        }

        QMessageBox::information(this, tr("Convert Data"), tr("Convert data successfully."));
    }
}

void MainWindow::on_btnVNI2Uni_clicked()
{
    QString path = ui->txtFileName->text();

    if (path != "") {
        QFile file(path);

        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }

        QTextStream in(&file);
        in.setCodec("UTF-8");

        QFile outFile(path.mid(0, path.lastIndexOf("/") + 1) + "promts_vni2uni.txt");
        outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);

        QTextStream out(&outFile);
        out.setCodec("UTF-8");

        QString line = "";
        Converter *convert = new Converter();

        ui->plainTextEdit->clear();

        while (!in.atEnd()) {
            line = in.readLine();

            QString result = convert->convertVNI2Unicode(line);

            out << result << endl;
            ui->plainTextEdit->appendPlainText(result + "\n");
        }

        QMessageBox::information(this, tr("Convert Data"), tr("Convert data successfully."));
    }
}

void MainWindow::on_btnVNI2Telex_clicked()
{
    QString path = ui->txtFileName->text();

    if (path != "") {
        QFile file(path);

        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }

        QTextStream in(&file);
        in.setCodec("UTF-8");

        QFile outFile(path.mid(0, path.lastIndexOf("/") + 1) + "promts_vni2telex.txt");
        outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);

        QTextStream out(&outFile);
        out.setCodec("UTF-8");

        QString line = "";
        Converter *convert = new Converter();

        ui->plainTextEdit->clear();

        while (!in.atEnd()) {
            line = in.readLine();

            QString result = convert->convertVNI2Telex(line);

            out << result << endl;
            ui->plainTextEdit->appendPlainText(result + "\n");
        }

        QMessageBox::information(this, tr("Convert Data"), tr("Convert data successfully."));
    }
}

void MainWindow::on_btnBrowse_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Promts Data"), QString("D:\\Pratice\\SLP\\Thuc_hanh_2\\vivos"), tr("Text File (*.txt)"));

    if (filePath == "") {
        return;
    }

    if (QFile::exists(filePath)) {
        ui->txtFileName->setText(filePath);
    }
}
