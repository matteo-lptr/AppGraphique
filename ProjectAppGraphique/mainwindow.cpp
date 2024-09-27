#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "HashGestion.h"
#include "RSAGestion.h"
#include "AesGestion.h"
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->chiffreRSA->setVisible(false);
    ui->dechiffreRSA->setVisible(false);
    ui->chiffreAES->setVisible(false);
    ui->dechiffreAES->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_sha256_clicked()
{
    HashGestion SHA;
    cout << SHA.CalculateSHA256("c'est un chat") << endl;
}


void MainWindow::on_btn_rsa_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Files (*.*)"));
    ui->chiffreRSA->setVisible(true);
    ui->dechiffreRSA->setVisible(true);
}


void MainWindow::on_btn_aes_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Files (*.*)"));
    ui->chiffreAES->setVisible(true);
    ui->dechiffreAES->setVisible(true);
}

void MainWindow::on_chiffreRSA_clicked()
{
    RsaGestion RSA;
    RSA.generationClef("MatteoRSAPublic.pem", "MatteoRSAPrive.pem", 2048);
}


void MainWindow::on_dechiffreRSA_clicked()
{

}


void MainWindow::on_chiffreAES_clicked()
{
    AesGestion AES;
    AES.GenerateAESKey();
    AES.SaveAESKeyToFile("Key.txt");
}


void MainWindow::on_dechiffreAES_clicked()
{
    AesGestion AES;
}

