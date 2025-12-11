<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tugas Besar IF4806 - Kelompok 06</title>
    <style>
        body {
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Helvetica, Arial, sans-serif;
            line-height: 1.6;
            color: #24292e;
            max-width: 900px;
            margin: 0 auto;
            padding: 2rem;
            background-color: #ffffff;
        }

        h1 {
            border-bottom: 1px solid #eaecef;
            padding-bottom: 0.3em;
            font-size: 2em;
            margin-bottom: 16px;
        }

        h2 {
            border-bottom: 1px solid #eaecef;
            padding-bottom: 0.3em;
            font-size: 1.5em;
            margin-top: 24px;
            margin-bottom: 16px;
        }

        h3 {
            font-size: 1.25em;
            margin-top: 24px;
            margin-bottom: 16px;
        }

        p {
            margin-top: 0;
            margin-bottom: 16px;
        }

        code {
            padding: 0.2em 0.4em;
            margin: 0;
            font-size: 85%;
            background-color: #f6f8fa;
            border-radius: 6px;
            font-family: SFMono-Regular, Consolas, "Liberation Mono", Menlo, monospace;
        }

        pre {
            padding: 16px;
            overflow: auto;
            font-size: 85%;
            line-height: 1.45;
            background-color: #f6f8fa;
            border-radius: 6px;
            margin-bottom: 16px;
        }

        pre code {
            background-color: transparent;
            padding: 0;
        }

        ul, ol {
            padding-left: 2em;
            margin-top: 0;
            margin-bottom: 16px;
        }

        li {
            margin-bottom: 0.25em;
        }

        table {
            border-collapse: collapse;
            width: 100%;
            margin-bottom: 16px;
        }

        table th, table td {
            padding: 6px 13px;
            border: 1px solid #dfe2e5;
        }

        table tr {
            background-color: #fff;
            border-top: 1px solid #c6cbd1;
        }

        table tr:nth-child(2n) {
            background-color: #f6f8fa;
        }

        blockquote {
            padding: 0 1em;
            color: #6a737d;
            border-left: 0.25em solid #dfe2e5;
            margin: 0 0 16px 0;
        }

        .footer {
            margin-top: 40px;
            border-top: 1px solid #eaecef;
            padding-top: 20px;
            font-style: italic;
            text-align: center;
            color: #586069;
        }

        .badge {
            display: inline-block;
            padding: 2px 6px;
            font-size: 12px;
            font-weight: 600;
            line-height: 1;
            color: #fff;
            text-align: center;
            white-space: nowrap;
            vertical-align: baseline;
            border-radius: 4px;
        }
        .badge-admin { background-color: #d73a49; } /* Red for Producer */
        .badge-analyst { background-color: #0366d6; } /* Blue for Auditor */

        .soal-box {
            background-color: #fffbdd; /* Light yellow for highlight */
            border-left: 5px solid #d4a72c;
            padding: 15px;
            margin-bottom: 20px;
            border-radius: 0 4px 4px 0;
        }
    </style>

</head>
<body>

    <h1>Tugas Besar IF4806 - Kelompok 06</h1>

    <div class="soal-box">
        <h3>Soal:</h3>
        <p>Rancanglah multi-linked list yang memodelkan film, aktor/aktris, dan hubungan di antara mereka. Seorang aktor dapat bermain peran di banyak film, dan satu film dapat diperankan oleh banyak aktor/aktris. Program ditujukan untuk mengelola daftar artis yang berperan dalam suatu film serta memantau performanya.</p>
    </div>

    <h2>📝 Deskripsi Proyek</h2>

    <p>Program ini mengelola data dengan hubungan <strong>Many-to-Many</strong> (Banyak ke Banyak), di mana:</p>
    <ul>
        <li>Seorang aktor dapat berperan dalam banyak film.</li>
        <li>Satu film dapat diperankan oleh banyak aktor.</li>
    </ul>

    <p>Sistem ini memisahkan peran pengguna menjadi dua mode: <strong>Producer (Admin)</strong> untuk pengelolaan data, dan <strong>Auditor (Analyst)</strong> untuk pelaporan dan analisis data.</p>

    <h2>📂 Struktur File</h2>
    <p>Berikut adalah penjelasan singkat mengenai file-file dalam repositori ini:</p>
    <ul>
        <li><strong><code>main.cpp</code></strong>: File utama yang berisi fungsi <code>main</code>, menu interaksi pengguna (Producer & Auditor).</li>
        <li><strong><code>mll.h</code></strong>: Header file yang mendefinisikan tipe data abstrak (ADT), struktur data, dan deklarasi fungsi/prosedur.</li>
        <li><strong><code>mllparent.cpp</code></strong>: Implementasi fungsi primitif untuk pengelolaan data Film (Parent).</li>
        <li><strong><code>mllChild.cpp</code></strong>: Implementasi fungsi primitif untuk pengelolaan data Aktor (Child) dan Relasi.</li>
    </ul>

    <h2>⚙️ Prasyarat</h2>
    <p>Sebelum menjalankan program, pastikan Anda memiliki:</p>
    <ul>
        <li>Compiler C++ (seperti GCC/G++).</li>
        <li>IDE Code::Blocks (Direkomendasikan).</li>
    </ul>

    <h2>🚀 Cara Kompilasi dan Menjalankan</h2>
    <p>Karena proyek ini dibagi menjadi beberapa file, Anda harus mengompilasi semua file <code>.cpp</code> secara bersamaan.</p>

    <h3>1. Menggunakan Terminal / Command Line</h3>
    <pre><code>g++ main.cpp mllparent.cpp mllChild.cpp -o app_tubes

./app_tubes (atau app_tubes.exe di Windows)</code></pre>

    <h3>2. Menggunakan Code::Blocks IDE</h3>
    <p>Untuk menjalankan proyek ini di Code::Blocks, ikuti langkah berikut:</p>
    <ol>
        <li>Buka Code::Blocks dan pilih <strong>File > New > Project</strong>.</li>
        <li>Pilih <strong>Console Application</strong> dan klik <em>Go</em>.</li>
        <li>Pilih bahasa <strong>C++</strong>.</li>
        <li>Beri nama proyek (misalnya: <code>Tubes_Kelompok06</code>) dan tentukan lokasi penyimpanan.</li>
        <li>Setelah proyek dibuat, klik kanan pada nama proyek di panel sebelah kiri (Management).</li>
        <li>Pilih <strong>Add files...</strong></li>
        <li>Pilih semua file source: <code>main.cpp</code>, <code>mllparent.cpp</code>, <code>mllChild.cpp</code>, dan <code>mll.h</code>.</li>
        <li>Klik <strong>Build and Run</strong> (F9).</li>
    </ol>

    <h2>📋 Fitur Utama</h2>
    <p>Berdasarkan implementasi kode, berikut adalah fitur lengkap aplikasi:</p>

    <h3>Modul Producer (Admin) <span class="badge badge-admin">Write Access</span></h3>
    <ul>
        <li><strong>Registrasi Film</strong>: Menambahkan film baru (Insert Sorted berdasarkan Tahun Rilis).</li>
        <li><strong>Casting Aktor</strong>: Menambahkan aktor baru ke dalam film (Insert Unique, mencegah duplikasi aktor/karakter dalam satu film).</li>
        <li><strong>Hapus Film</strong>: Menghapus data film tertentu berdasarkan ID.</li>
        <li><strong>Pecat Aktor</strong>: Menghapus aktor tertentu dari sebuah film berdasarkan ID Aktor.</li>
        <li><strong>Bersihkan Film Flop</strong>: Fitur otomatis menghapus semua film dengan rating di bawah 5.0.</li>
        <li><strong>Efisiensi Cameo</strong>: Fitur otomatis menghapus semua aktor dengan tipe peran "Cameo" dari film tertentu.</li>
        <li><strong>View Database</strong>: Menampilkan seluruh data Film beserta Aktor yang bermain di dalamnya.</li>
    </ul>

    <h3>Modul Auditor (Analyst) <span class="badge badge-analyst">Read Access</span></h3>
    <ul>
        <li><strong>Pencarian Film</strong>: Mencari detail data film berdasarkan Judul atau ID.</li>
        <li><strong>Validasi Aktor</strong>: Mengecek apakah aktor tertentu bermain dalam film tertentu (Relasi Check).</li>
        <li><strong>Laporan Beban Gaji</strong>: Menghitung total pengeluaran gaji aktor untuk satu judul film.</li>
        <li><strong>Cari Star Actor</strong>: Mencari aktor dengan bayaran (gaji) tertinggi dalam sebuah film.</li>
    </ul>

    <h2>👥 Anggota Kelompok 06</h2>
    <table>
        <thead>
            <tr>
                <th>Nama Lengkap</th>
                <th>NIM</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td><strong>Ravi Adi Prakoso</strong></td>
                <td>103012430058</td>
            </tr>
            <tr>
                <td><strong>Farrel Malik Pirade</strong></td>
                <td>103012400068</td>
            </tr>
        </tbody>
    </table>

</body>
</html>
