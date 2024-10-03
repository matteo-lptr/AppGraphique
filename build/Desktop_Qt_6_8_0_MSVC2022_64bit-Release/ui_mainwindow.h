/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *keyrsa;
    QPushButton *btn_sha256;
    QPushButton *keyaes;
    QLabel *label;
    QPushButton *chiffreRSA;
    QPushButton *btn_aes;
    QPushButton *dechiffreRSA;
    QPushButton *generationclef;
    QPushButton *chiffreAES;
    QPushButton *dechiffreAES;
    QPushButton *btn_rsa;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1300, 771);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        keyrsa = new QPushButton(centralwidget);
        keyrsa->setObjectName("keyrsa");
        keyrsa->setGeometry(QRect(660, 140, 111, 41));
        keyrsa->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(32, 91, 83);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        btn_sha256 = new QPushButton(centralwidget);
        btn_sha256->setObjectName("btn_sha256");
        btn_sha256->setGeometry(QRect(210, 120, 201, 41));
        btn_sha256->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(32, 91, 83);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        keyaes = new QPushButton(centralwidget);
        keyaes->setObjectName("keyaes");
        keyaes->setGeometry(QRect(780, 140, 111, 41));
        keyaes->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(32, 91, 83);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1081, 621));
        label->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-image: url(:/mapload.jpg);"));
        chiffreRSA = new QPushButton(centralwidget);
        chiffreRSA->setObjectName("chiffreRSA");
        chiffreRSA->setGeometry(QRect(360, 270, 241, 41));
        chiffreRSA->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(32, 91, 83);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        btn_aes = new QPushButton(centralwidget);
        btn_aes->setObjectName("btn_aes");
        btn_aes->setGeometry(QRect(80, 430, 201, 41));
        btn_aes->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(32, 91, 83);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        dechiffreRSA = new QPushButton(centralwidget);
        dechiffreRSA->setObjectName("dechiffreRSA");
        dechiffreRSA->setGeometry(QRect(360, 320, 241, 41));
        dechiffreRSA->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(32, 91, 83);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        generationclef = new QPushButton(centralwidget);
        generationclef->setObjectName("generationclef");
        generationclef->setGeometry(QRect(690, 80, 171, 41));
        generationclef->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(32, 91, 83);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        chiffreAES = new QPushButton(centralwidget);
        chiffreAES->setObjectName("chiffreAES");
        chiffreAES->setGeometry(QRect(360, 410, 241, 41));
        chiffreAES->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(32, 91, 83);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        dechiffreAES = new QPushButton(centralwidget);
        dechiffreAES->setObjectName("dechiffreAES");
        dechiffreAES->setGeometry(QRect(360, 460, 241, 41));
        dechiffreAES->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(32, 91, 83);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        btn_rsa = new QPushButton(centralwidget);
        btn_rsa->setObjectName("btn_rsa");
        btn_rsa->setGeometry(QRect(80, 300, 201, 41));
        btn_rsa->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(32, 91, 83);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1300, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        keyrsa->setText(QCoreApplication::translate("MainWindow", "RSA", nullptr));
        btn_sha256->setText(QCoreApplication::translate("MainWindow", "Hashage - SHA256", nullptr));
        keyaes->setText(QCoreApplication::translate("MainWindow", "AES", nullptr));
        label->setText(QString());
        chiffreRSA->setText(QCoreApplication::translate("MainWindow", "Chiffrer avec clef public existante", nullptr));
        btn_aes->setText(QCoreApplication::translate("MainWindow", "Chiffrement - AES", nullptr));
        dechiffreRSA->setText(QCoreApplication::translate("MainWindow", "Dechiffrer avec clef priv\303\251 existante", nullptr));
        generationclef->setText(QCoreApplication::translate("MainWindow", "Generation clefs", nullptr));
        chiffreAES->setText(QCoreApplication::translate("MainWindow", "Chiffrer  avec clef secr\303\250te  existante", nullptr));
        dechiffreAES->setText(QCoreApplication::translate("MainWindow", "Dechiffrer avec clef secr\303\250te existante", nullptr));
        btn_rsa->setText(QCoreApplication::translate("MainWindow", "Chiffrement - RSA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
