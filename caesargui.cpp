#include "caesargui.h"
#include "./ui_caesargui.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <string>

// =====================================
// 1. CONSTRUCTOR (PENGATURAN AWAL)
// =====================================
CaesarGUI::CaesarGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CaesarGUI)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
}

CaesarGUI::~CaesarGUI()
{
    delete ui;
}

// =====================================
// 2. SISTEM NAVIGASI & LOGIN
// =====================================
void CaesarGUI::on_btnLogin_clicked() {
    if(ui->linePass->text() == "poltekssn") {
        ui->stackedWidget->setCurrentIndex(1); // Masuk Dashboard
        ui->linePass->clear(); // Bersihkan password
    } else {
        QMessageBox::warning(this, "Akses Ditolak", "Sandi Salah, Taruna!");
        ui->linePass->clear();
    }
}

void CaesarGUI::on_btnLogOut_clicked() {
    ui->stackedWidget->setCurrentIndex(0); // Balik ke Login
}

void CaesarGUI::on_btnGoCaesar_clicked() {
    ui->stackedWidget->setCurrentIndex(3); // Buka Caesar
}

void CaesarGUI::on_btnGoVigenere_clicked() {
    ui->stackedWidget->setCurrentIndex(2); // Buka Vigenere
}

void CaesarGUI::on_btnBack1_clicked() {
    ui->stackedWidget->setCurrentIndex(1); // Caesar -> Dashboard
}

void CaesarGUI::on_btnBack2_clicked() {
    ui->stackedWidget->setCurrentIndex(1); // Vigenere -> Dashboard
}

// =====================================
// 3. MODUL CAESAR CIPHER (Page 2)
// =====================================
void CaesarGUI::on_btnEnkripsi_clicked() {
    QString teks = ui->lineEditPesan->text();
    int kunci = ui->spinBoxKunci->value();
    if (teks.isEmpty()) {
        QMessageBox::warning(this, "Peringatan", "Pesan tidak boleh kosong!");
        return;
    }

    std::string hasil = "";
    std::string strTeks = teks.toStdString();
    for (char c : strTeks) {
        if (isupper(c)) hasil += char(int(c + kunci - 65) % 26 + 65);
        else if (islower(c)) hasil += char(int(c + kunci - 97) % 26 + 97);
        else hasil += c;
    }
    ui->textEditHasil->setPlainText("Hasil Enkripsi:\n" + QString::fromStdString(hasil));
}

void CaesarGUI::on_btnDekripsi_clicked() {
    QString teks = ui->lineEditPesan->text();
    int kunci = ui->spinBoxKunci->value();
    if (teks.isEmpty()) return;

    std::string hasil = "";
    std::string strTeks = teks.toStdString();
    for (char c : strTeks) {
        if (isupper(c)) hasil += char((c - 65 - kunci + 26) % 26 + 65);
        else if (islower(c)) hasil += char((c - 97 - kunci + 26) % 26 + 97);
        else hasil += c;
    }
    ui->textEditHasil->setPlainText("Hasil Dekripsi:\n" + QString::fromStdString(hasil));
}

void CaesarGUI::on_btnSimpan_clicked() {
    QString teksHasil = ui->textEditHasil->toPlainText();
    if (teksHasil.isEmpty()) return;

    QString fileName = QFileDialog::getSaveFileName(this, "Simpan Hasil", "C:/", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "=== LAPORAN HASIL ANALISIS SIBER ===\n";
            out << "Petugas: Said Irfan Halim & Keifa Dinnaya\n";
            out << "------------------------------------\n\n";
            out << teksHasil;
            file.close();
            QMessageBox::information(this, "Sukses", "File berhasil disimpan.");
        }
    }
}

void CaesarGUI::on_btnBruteForce_clicked() {
    QString teks = ui->lineEditPesan->text();
    std::string strTeks = teks.toStdString();
    QString kumpulanHasil = "--- HASIL ANALISIS BRUTE FORCE ---\n\n";

    if (teks.isEmpty()) {
        QMessageBox::warning(this, "Peringatan", "Pesan tidak boleh kosong untuk di-Brute Force!");
        return;
    }

    // Melakukan perulangan untuk mencoba 25 kemungkinan kunci
    for (int k = 1; k < 26; k++) {
        std::string baris = "";
        for (char c : strTeks) {
            if (isupper(c)) baris += char((c - 65 - k + 26) % 26 + 65);
            else if (islower(c)) baris += char((c - 97 - k + 26) % 26 + 97);
            else baris += c;
        }
        kumpulanHasil += "Kunci " + QString::number(k) + ": " + QString::fromStdString(baris) + "\n";
    }

    // Menampilkan semua hasil ke layar
    ui->textEditHasil->setPlainText(kumpulanHasil);
}

// =====================================
// 4. MODUL VIGENERE CIPHER (Page 3)
// =====================================
void CaesarGUI::on_btnEnkripsiVig_clicked() {
    QString pesan = ui->textEditPesanVig->toPlainText().toUpper();
    QString kunci = ui->lineEditKunciVig->text().toUpper();
    QString hasil = "";

    if(kunci.isEmpty() || pesan.isEmpty()) {
        QMessageBox::critical(this, "Error", "Pesan dan Kunci tidak boleh kosong!");
        return;
    }

    int j = 0;
    for (int i = 0; i < pesan.length(); i++) {
        QChar c = pesan[i];
        if (c >= 'A' && c <= 'Z') {
            int p = c.unicode() - 'A';
            int k = kunci[j % kunci.length()].unicode() - 'A';
            int res = (p + k) % 26; // Rumus Enkripsi
            hasil.append(QChar(res + 'A'));
            j++;
        } else {
            hasil.append(c);
        }
    }
    ui->textEditHasilVig->setText("Hasil Enkripsi Vigenere:\n" + hasil);
}

void CaesarGUI::on_btnDekripsiVig_clicked() {
    QString pesan = ui->textEditPesanVig->toPlainText().toUpper();
    QString kunci = ui->lineEditKunciVig->text().toUpper();
    QString hasil = "";

    if(kunci.isEmpty() || pesan.isEmpty()) return;

    int j = 0;
    for (int i = 0; i < pesan.length(); i++) {
        QChar c = pesan[i];
        if (c >= 'A' && c <= 'Z') {
            int p = c.unicode() - 'A';
            int k = kunci[j % kunci.length()].unicode() - 'A';
            int res = (p - k + 26) % 26; // Rumus Dekripsi Vigenere
            hasil.append(QChar(res + 'A'));
            j++;
        } else {
            hasil.append(c);
        }
    }
    ui->textEditHasilVig->setText("Hasil Dekripsi Vigenere:\n" + hasil);
}

void CaesarGUI::on_btnSimpanVig_clicked() {
    // Ambil teks dari kotak hasil Vigenere
    QString teksHasil = ui->textEditHasilVig->toPlainText();

    if (teksHasil.isEmpty()) {
        QMessageBox::warning(this, "Peringatan", "Tidak ada hasil Vigenere yang bisa disimpan!");
        return;
    }

    // Munculkan jendela Save File
    QString fileName = QFileDialog::getSaveFileName(this, "Simpan Hasil Vigenere", "C:/", "Text Files (*.txt)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "=== LAPORAN HASIL ANALISIS SIBER (VIGENERE) ===\n";
            out << "Petugas: Said Irfan Halim & Keifa Dinnaya\n";
            out << "------------------------------------\n\n";
            out << teksHasil;
            file.close();
            QMessageBox::information(this, "Sukses", "File Vigenere berhasil disimpan.");
        }
    }
}
