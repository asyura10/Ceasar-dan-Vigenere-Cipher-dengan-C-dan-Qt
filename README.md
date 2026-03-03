# Sistem Kriptografi Siber (Caesar & Vigenere Cipher)

Aplikasi kriptografi klasik berbasis *Graphical User Interface* (GUI) yang dikembangkan menggunakan bahasa **C++** dan **Qt Framework**. Proyek ini disusun sebagai pemenuhan Tugas Akhir Semester mata kuliah Struktur Data dan Algoritma Pemrograman (SDAP) di Politeknik Siber dan Sandi Negara.

## 👥 Pengembang (Taruna Tingkat I)
* Said Irfan Halim
* Keifa Dinnaya Nadya S.

## 🛠️ Tech Stack
* **Bahasa Pemrograman:** C++ (Standard C++17)
* **Framework:** Qt (Qt Widgets, QStackedWidget)
* **IDE:** Qt Creator

## 🔒 Fitur Sistem
1. **Autentikasi Keamanan:** Sistem *login* sederhana untuk membatasi akses antarmuka.
2. **Caesar Cipher:** Modul enkripsi dan dekripsi menggunakan teknik substitusi monoalfabetik.
3. **Brute Force Attack:** Fitur kriptanalisis untuk membongkar sandi Caesar dengan menampilkan 25 iterasi kunci.
4. **Vigenere Cipher:** Modul enkripsi dan dekripsi menggunakan teknik substitusi polialfabetik dengan fitur normalisasi input (`.toUpper()`).
5. **File I/O Management:** Ekspor hasil *ciphertext* atau *plaintext* ke dalam format `.txt` lokal.

## 🚀 Cara Menjalankan (How to Run)
1. *Clone repository* ini: `git clone https://github.com/UsernameKamu/Kriptografi-Klasik-Qt.git`
2. Buka file `.pro` atau `CMakeLists.txt` menggunakan **Qt Creator**.
3. Lakukan proses *Build* (Ctrl+B) dan *Run* (Ctrl+R).
4. Gunakan kata sandi **poltekssn** pada halaman *login* untuk masuk ke *Dashboard*.
