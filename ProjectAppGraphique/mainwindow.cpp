#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QInputDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>

#include "HashGestion.h"
#include "AesGestion.h"
#include "RsaGestion.h"

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
    ui->keyaes->setVisible(false);
    ui->keyrsa->setVisible(false);

    // Créer un widget central et un layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Créer un QLabel pour afficher l'image
    QLabel *imageLabel = new QLabel(this);

    // Charger l'image dans un QPixmap
    QPixmap pixmap(":/mapload.jpg");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_sha256_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner un fichier");
    if (!filePath.isEmpty()) {
        HashGestion lm;
        std::string hash = lm.CalculateSHA256(filePath.toStdString());
        std::cout << hash << std::endl;

        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(hash.c_str());
            file.close();
            QMessageBox::information(this, "Succès", "Hachage SHA256 effectué et sauvegardé");
        }
    }
}


void MainWindow::on_btn_rsa_clicked()
{
    ui->chiffreRSA->setVisible(true);
    ui->dechiffreRSA->setVisible(true);
    ui->chiffreAES->setVisible(false);
    ui->dechiffreAES->setVisible(false);
    ui->keyaes->setVisible(false);
    ui->keyrsa->setVisible(false);
}


void MainWindow::on_btn_aes_clicked()
{
    ui->chiffreAES->setVisible(true);
    ui->dechiffreAES->setVisible(true);
    ui->chiffreRSA->setVisible(false);
    ui->dechiffreRSA->setVisible(false);
    ui->keyaes->setVisible(false);
    ui->keyrsa->setVisible(false);
}

void MainWindow::on_chiffreRSA_clicked()
{
    QString publicKeyPath = QFileDialog::getOpenFileName(this, "Sélectionner la clé publique");
    QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner le fichier à chiffrer");
    QString outputPath = QFileDialog::getSaveFileName(this, "Sauvegarder le fichier chiffré");

    if (!publicKeyPath.isEmpty() && !filePath.isEmpty() && !outputPath.isEmpty()) {
        RsaGestion RSA;
        RSA.chargementClefs("RSAPublic.pem", "RSAPrive.pem");
        RSA.chiffrementFichier(filePath.toStdString(), outputPath.toStdString(), 2048);
        QMessageBox::information(this, "Succès", "Fichier chiffré avec RSA");
    }
}


void MainWindow::on_dechiffreRSA_clicked()
{
    QString privateKeyPath = QFileDialog::getOpenFileName(this, "Sélectionner la clé privée");
    QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner le fichier à déchiffrer");
    QString outputPath = QFileDialog::getSaveFileName(this, "Sauvegarder le fichier déchiffré");

    if (!privateKeyPath.isEmpty() && !filePath.isEmpty() && !outputPath.isEmpty()) {
        RsaGestion RSA;
        RSA.chargementClefs("RSAPublic.pem", "RSAPrive.pem");
        RSA.dechiffrementFichier(filePath.toStdString(), outputPath.toStdString(), 2048);
        QMessageBox::information(this, "Succès", "Fichier déchiffré avec RSA");
    }
}


void MainWindow::on_chiffreAES_clicked()
{
    QString keyPath = QFileDialog::getOpenFileName(this, "Sélectionner la clé secrète");
    QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner le fichier à chiffrer");
    QString outputPath = QFileDialog::getSaveFileName(this, "Sauvegarder le fichier chiffré");

    if (!keyPath.isEmpty() && !filePath.isEmpty() && !outputPath.isEmpty()) {
        AesGestion AES;
        AES.EncryptFileAES256(filePath.toStdString(), outputPath.toStdString());
        QMessageBox::information(this, "Succès", "Fichier chiffré avec AES");
    }
}


void MainWindow::on_dechiffreAES_clicked()
{
    QString keyPath = QFileDialog::getOpenFileName(this, "Sélectionner la clé secrète");
    QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner le fichier à déchiffrer");
    QString outputPath = QFileDialog::getSaveFileName(this, "Sauvegarder le fichier déchiffré");

    if (!keyPath.isEmpty() && !filePath.isEmpty() && !outputPath.isEmpty()) {
        AesGestion AES;
        AES.DecryptFileAES256(filePath.toStdString(), outputPath.toStdString());
        QMessageBox::information(this, "Succès", "Fichier déchiffré avec AES");
    }
}


void MainWindow::on_generationclef_clicked()
{
    ui->chiffreRSA->setVisible(false);
    ui->dechiffreRSA->setVisible(false);
    ui->chiffreAES->setVisible(false);
    ui->dechiffreAES->setVisible(false);
    ui->keyaes->setVisible(true);
    ui->keyrsa->setVisible(true);
}


void MainWindow::on_keyrsa_clicked()
{
    QString keyName = QInputDialog::getText(this, "Nom des clés", "Entrez un nom pour les clés :");
    if (keyName.isEmpty()) return;

    // Ouvre une boîte de dialogue pour que l'utilisateur choisisse un dossier
    QString savePath = QFileDialog::getExistingDirectory(
        this,  // Widget parent (généralement la fenêtre principale)
        "Choisir le dossier de sauvegarde",  // Titre de la boîte de dialogue
        QDir::homePath(),  // Chemin initial (ici, le dossier personnel de l'utilisateur)
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks  // Options
        );

    // Vérifie si l'utilisateur a annulé la sélection ou n'a pas choisi de dossier
    if (savePath.isEmpty()) {
        return;  // Si aucun dossier n'est sélectionné, on quitte la fonction
    }

    // Vérifie si le chemin se termine par un séparateur de dossier
    if (!savePath.endsWith(QDir::separator())) {
        // Si ce n'est pas le cas, on ajoute un séparateur
        savePath += QDir::separator();
    }

    // Génération des clés RSA
    RsaGestion RSA;
    QString rsaPublicKeyPath = savePath + keyName + "_RSA_public.pem";
    QString rsaPrivateKeyPath = savePath + keyName + "_RSA_private.pem";
    RSA.generationClef(rsaPublicKeyPath.toStdString(), rsaPrivateKeyPath.toStdString(), 2048);
    QMessageBox::information(this, "Succès", "Clés RSA générées :\nPublique : " + rsaPublicKeyPath + "\nPrivée : " + rsaPrivateKeyPath);
}


void MainWindow::on_keyaes_clicked()
{
    QString keyName = QInputDialog::getText(this, "Nom des clés", "Entrez un nom pour les clés :");
    if (keyName.isEmpty()) return;

    // Ouvre une boîte de dialogue pour que l'utilisateur choisisse un dossier
    QString savePath = QFileDialog::getExistingDirectory(
        this,  // Widget parent (généralement la fenêtre principale)
        "Choisir le dossier de sauvegarde",  // Titre de la boîte de dialogue
        QDir::currentPath() + "/BDD",  // Chemin initial
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks  // Options
        );

    // Vérifie si l'utilisateur a annulé la sélection ou n'a pas choisi de dossier
    if (savePath.isEmpty()) {
        return;  // Si aucun dossier n'est sélectionné, on quitte la fonction
    }

    // Vérifie si le chemin se termine par un séparateur de dossier
    if (!savePath.endsWith(QDir::separator())) {
        // Si ce n'est pas le cas, on ajoute un séparateur
        savePath += QDir::separator();
    }


    // Génération de la clé AES
    AesGestion AES;
    AES.GenerateAESKey();
    QString aesKeyPath = savePath + keyName + "_AES.key";
    AES.SaveAESKeyToFile(aesKeyPath.toStdString());
    QMessageBox::information(this, "Succès", "Clé AES générée et sauvegardée : " + aesKeyPath);
}

