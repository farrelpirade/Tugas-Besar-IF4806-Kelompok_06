# Tugas Besar IF4806 - Kelompok 06

> **📝 Soal:**
> Rancanglah multi-linked list yang memodelkan film, aktor/aktris, dan hubungan di antara mereka. Seorang aktor dapat bermain peran di banyak film, dan satu film dapat diperankan oleh banyak aktor/aktris. Program ditujukan untuk mengelola daftar artis yang berperan dalam suatu film serta memantau performanya.

## 📝 Deskripsi Proyek

Program ini mengelola data dengan hubungan **Many-to-Many** (Banyak ke Banyak), di mana:

- Seorang aktor dapat berperan dalam banyak film.
- Satu film dapat diperankan oleh banyak aktor.

Sistem ini memisahkan peran pengguna menjadi dua mode:

![Admin](<https://img.shields.io/badge/Role-Producer_(Admin)-d73a49?style=flat-square&logo=github>)
![Analyst](<https://img.shields.io/badge/Role-Auditor_(Analyst)-0366d6?style=flat-square&logo=github>)

## 📂 Struktur File

Berikut adalah penjelasan singkat mengenai file-file dalam repositori ini:

- `main.cpp`: File utama yang berisi fungsi `main`, menu interaksi pengguna (Producer & Auditor).
- `mll.h`: Header file yang mendefinisikan tipe data abstrak (ADT), struktur data, dan deklarasi fungsi/prosedur.
- `mllparent.cpp`: Implementasi fungsi primitif untuk pengelolaan data **Film (Parent)**.
- `mllChild.cpp`: Implementasi fungsi primitif untuk pengelolaan data **Aktor (Child)** dan Relasi.

## ⚙️ Prasyarat

Sebelum menjalankan program, pastikan Anda memiliki:

- Compiler C++ (seperti GCC/G++).
- IDE Code::Blocks (Direkomendasikan).

## 🚀 Cara Kompilasi dan Menjalankan

Karena proyek ini dibagi menjadi beberapa file, Anda harus mengompilasi semua file `.cpp` secara bersamaan.

### 1. Menggunakan Terminal / Command Line

```bash
g++ main.cpp mllparent.cpp mllChild.cpp -o app_tubes

# Jalankan program:
./app_tubes
# Atau jika di Windows:
app_tubes.exe
```

### 2. Menggunakan Code::Blocks IDE

Untuk menjalankan proyek ini di Code::Blocks, ikuti langkah berikut:

1.  Buka Code::Blocks dan pilih **File > New > Project**.
2.  Pilih **Console Application** dan klik _Go_.
3.  Pilih bahasa **C++**.
4.  Beri nama proyek (misalnya: `Tubes_Kelompok06`) dan tentukan lokasi penyimpanan.
5.  Setelah proyek dibuat, klik kanan pada nama proyek di panel sebelah kiri (Management).
6.  Pilih **Add files...**.
7.  Pilih semua file source: `main.cpp`, `mllparent.cpp`, `mllChild.cpp`, dan `mll.h`.
8.  Klik **Build and Run** (F9).

## 📋 Fitur Utama

Berdasarkan implementasi kode, berikut adalah fitur lengkap aplikasi:

### Modul Producer (Admin) ![Write Access](https://img.shields.io/badge/Access-Write-red?style=flat-square)

- **Registrasi Film**: Menambahkan film baru (_Insert Sorted_ berdasarkan Tahun Rilis).
- **Casting Aktor**: Menambahkan aktor baru ke dalam film (_Insert Unique_, mencegah duplikasi aktor/karakter dalam satu film).
- **Hapus Film**: Menghapus data film tertentu berdasarkan ID.
- **Pecat Aktor**: Menghapus aktor tertentu dari sebuah film berdasarkan ID Aktor.
- **Bersihkan Film Flop**: Fitur otomatis menghapus semua film dengan rating di bawah 5.0.
- **Efisiensi Cameo**: Fitur otomatis menghapus semua aktor dengan tipe peran "Cameo" dari film tertentu.
- **View Database**: Menampilkan seluruh data Film beserta Aktor yang bermain di dalamnya.

### Modul Auditor (Analyst) ![Read Access](https://img.shields.io/badge/Access-Read-blue?style=flat-square)

- **Pencarian Film**: Mencari detail data film berdasarkan Judul atau ID.
- **Validasi Aktor**: Mengecek apakah aktor tertentu bermain dalam film tertentu (_Relasi Check_).
- **Laporan Beban Gaji**: Menghitung total pengeluaran gaji aktor untuk satu judul film.
- **Cari Star Actor**: Mencari aktor dengan bayaran (gaji) tertinggi dalam sebuah film.

## 👥 Anggota Kelompok 06

| Nama Lengkap            | NIM          |
| :---------------------- | :----------- |
| **Ravi Adi Prakoso**    | 103012430058 |
| **Farrel Malik Pirade** | 103012400068 |
