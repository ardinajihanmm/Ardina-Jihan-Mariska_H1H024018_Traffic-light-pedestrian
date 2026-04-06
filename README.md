# 🚦 Sistem Lampu Penyeberangan Jalan (Berbasis Interrupt & Timer)

Halo! 👋 Saya **Ardina Jihan Mariska**. Proyek ini adalah simulasi sistem penyeberangan pejalan kaki cerdas menggunakan **Arduino Uno**, yang berfokus pada implementasi **External Interrupt** dan **Timer**.



## 👤 Profil Penulis
* **Nama:** Ardina Jihan Mariska
* **NIM:** H1H024018



## 📝 Ringkasan Proyek
Proyek ini memodifikasi lampu lalu lintas 4 simpang standar menjadi **Sistem Penyeberangan yang Dikendalikan Pejalan Kaki**. Proyek ini mendemonstrasikan bagaimana mikrokontroler menangani peristiwa eksternal secara *real-time* menggunakan **Interrupt** untuk memastikan keamanan pejalan kaki tanpa mengganggu aliran sistem utama.

### 🛠️ Komponen yang Digunakan
* 1x **Arduino Uno R3** 
* 1x **Push Button** (Pemicu Interrupt) 
* 3x **LED Kendaraan** (Merah, Kuning, Hijau) 
* 4x **LED Pedestrian** (2x Merah, 2x Hijau) 
* 7x **Resistor 330Ω** 
* 1x **Breadboard & Kabel Jumper** 



## ⚙️ Logika Kerja Sistem
Berdasarkan modul **Sistem Mikrokontroler**:

1.  **Mode Standby:** Lampu kendaraan berwarna **HIJAU** 🟢 dan semua lampu pedestrian berwarna **MERAH** 🔴
2.  **Trigger Interrupt:** Saat tombol ditekan, sistem segera menangkap sinyal permintaan penyeberangan
3.  **Kendaraan Berhenti:** Lampu kendaraan langsung berubah menjadi **MERAH** 🔴
4.  **Pejalan Kaki Menyeberang:** Lampu pedestrian berubah menjadi **HIJAU** 🟢 selama durasi tertentu
5.  **Fase Reset:** Lampu pedestrian kembali **MERAH** 🔴, diikuti transisi **KUNING** 🟡 untuk kendaraan
6.  **Kembali Normal:** Sistem kembali ke kondisi awal (Kendaraan Hijau)



## 💻 Link thinkercad
https://www.tinkercad.com/things/iCjzOsj1byu/editel?returnTo=%2Fdashboard&sharecode=6IWWOagBgbFJBT_nHLeWHCylBRNmXzo9HDGQRPQQGCA
