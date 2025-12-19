# Tugas Besar IF4806 - Kelompok 06

> **Soal:**
>
> Rancanglah multi-linked list yang memodelkan film, aktor/aktris, dan hubungan di antara mereka. Seorang aktor dapat bermain peran di banyak film, dan satu film dapat diperankan oleh banyak aktor/aktris. Program ditujukan untuk mengelola daftar artis yang berperan dalam suatu film serta memantau performanya.

## Deskripsi Proyek

Program ini mengelola data dengan hubungan **Many-to-Many** (Banyak ke Banyak), di mana:

- Seorang aktor dapat berperan dalam banyak film.
- Satu film dapat diperankan oleh banyak aktor.

Sistem ini memisahkan peran pengguna menjadi dua mode: **Producer (Admin)** untuk pengelolaan data, dan **Auditor (Analyst)** untuk pelaporan dan analisis data.

## Struktur File

- `main.cpp`: File utama yang berisi menu interaksi pengguna (Producer & Auditor).
- `mll.h`: Header file yang mendefinisikan tipe data abstrak (ADT), struktur data, dan deklarasi fungsi.
- `mllparent.cpp`: Implementasi fungsi primitif untuk pengelolaan data Film (Parent).
- `mllChild.cpp`: Implementasi fungsi primitif untuk pengelolaan data Aktor (Child) dan Relasi.

## Prasyarat

- Compiler C++ (Misalnya GCC/G++).
- **IDE Code::Blocks**

## Cara Kompilasi dan Menjalankan

### 1. Menggunakan Code::Blocks IDE (Utama)

1.  Buka Code::Blocks, pilih **File > New > Project**.
2.  Pilih **Console Application**, klik _Go_.
3.  Pilih bahasa **C++**.
4.  Beri nama proyek (misal: `Tubes_Kelompok06`) dan tentukan lokasi penyimpanan.
5.  Setelah proyek dibuat, klik kanan pada nama proyek di panel sebelah kiri (_Management_).
6.  Pilih **Add files...**
7.  Pilih semua file source: `main.cpp`, `mllparent.cpp`, `mllChild.cpp`, dan `mll.h`.
8.  Klik **Build and Run** (atau tekan tombol **F9**).

### 2. Menggunakan Terminal / Command Line

Jika ingin menjalankan manual tanpa IDE:

```bash
g++ main.cpp mllparent.cpp mllChild.cpp -o app_tubes
./app_tubes
# (Gunakan app_tubes.exe jika di Windows)
# (app_tubes bisa diganti sesuai penamaan yang diinginkan)
```
