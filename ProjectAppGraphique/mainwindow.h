#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_sha256_clicked();

    void on_btn_rsa_clicked();

    void on_btn_aes_clicked();

    void on_dechiffreRSA_clicked();

    void on_chiffreRSA_clicked();

    void on_chiffreAES_clicked();

    void on_dechiffreAES_clicked();

    void on_generationclef_clicked();

    void on_keyrsa_clicked();

    void on_keyaes_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
