#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "HashGestion.h"
#include "RSAGestion.h"
#include "AesGestion.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_sha256_clicked()
{

}


void MainWindow::on_btn_rsa_clicked()
{

}


void MainWindow::on_btn_aes_clicked()
{

}

