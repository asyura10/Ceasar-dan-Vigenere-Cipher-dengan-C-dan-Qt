#ifndef CAESARGUI_H
#define CAESARGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CaesarGUI; }
QT_END_NAMESPACE

class CaesarGUI : public QMainWindow
{
    Q_OBJECT

public:
    CaesarGUI(QWidget *parent = nullptr);
    ~CaesarGUI();

private slots:
    // =====================================
    // SISTEM NAVIGASI & LOGIN
    // =====================================
    void on_btnLogin_clicked();
    void on_btnLogOut_clicked();
    void on_btnGoCaesar_clicked();
    void on_btnGoVigenere_clicked();
    void on_btnBack1_clicked();
    void on_btnBack2_clicked();

    // =====================================
    // MODUL CAESAR CIPHER
    // =====================================
    void on_btnEnkripsi_clicked();
    void on_btnDekripsi_clicked();
    void on_btnSimpan_clicked();
    void on_btnBruteForce_clicked();

    // =====================================
    // MODUL VIGENERE CIPHER
    // =====================================
    void on_btnEnkripsiVig_clicked();
    void on_btnDekripsiVig_clicked();
    void on_btnSimpanVig_clicked();

private:
    Ui::CaesarGUI *ui;
};

#endif // CAESARGUI_H
