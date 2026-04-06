// Traffic Light Kendaraan 
const int kendaraanMerah = 11;
const int kendaraanKuning = 10;
const int kendaraanHijau = 9;

// Pedestrian Sisi Kiri 
const int pedKiriMerah = 13;
const int pedKiriHijau = 12;

// Pedestrian Sisi Kanan
const int pedKananMerah = 8;
const int pedKananHijau = 7;

// Tombol Interrupt 
const int tombolPin = 2; 

volatile bool requestMenyeberang = false;

void setup() {
  // Definisikan semua pin sebagai OUTPUT
  pinMode(kendaraanMerah, OUTPUT);
  pinMode(kendaraanKuning, OUTPUT);
  pinMode(kendaraanHijau, OUTPUT);
  pinMode(pedKiriMerah, OUTPUT);
  pinMode(pedKiriHijau, OUTPUT);
  pinMode(pedKananMerah, OUTPUT);
  pinMode(pedKananHijau, OUTPUT);
  
  // Setup Interrupt 
  pinMode(tombolPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(tombolPin), pencetTombol, FALLING);
  
  // 3. KONDISI AWAL (STANDBY)
  digitalWrite(kendaraanHijau, HIGH);    // Lampu kendaraan hijau 
  digitalWrite(pedKiriMerah, HIGH);      // Lampu pedestrian merah (Pin 13) 
  digitalWrite(pedKananMerah, HIGH);     // Lampu pedestrian merah (Pin 8)
  
  // Pastikan lampu transisi/jalan lainnya mati
  digitalWrite(kendaraanMerah, LOW);
  digitalWrite(kendaraanKuning, LOW);
  digitalWrite(pedKiriHijau, LOW);
  digitalWrite(pedKananHijau, LOW);
}

void loop() {
  // Jika tombol ditekan 
  if (requestMenyeberang) {
    jalankanProsedur();
    requestMenyeberang = false;
  }
}

// Fungsi yang dipanggil saat tombol ditekan 
void pencetTombol() {
  requestMenyeberang = true; 
}

void jalankanProsedur() {
  // SAAT DITEKAN
  // Lampu kendaraan berubah menjadi merah 
  digitalWrite(kendaraanHijau, LOW);
  digitalWrite(kendaraanMerah, HIGH); 
  delay(500); // Jeda keamanan singkat
  
  // Lampu pedestrian berubah menjadi hijau
  digitalWrite(pedKiriMerah, LOW);
  digitalWrite(pedKananMerah, LOW);
  digitalWrite(pedKiriHijau, HIGH);
  digitalWrite(pedKananHijau, HIGH);
  
  // SETELAH WAKTU TERTENTU 
  delay(5000); // Durasi menyeberang 
  
  // Lampu pedestrian kembali merah 
  digitalWrite(pedKiriHijau, LOW);
  digitalWrite(pedKananHijau, LOW);
  digitalWrite(pedKiriMerah, HIGH);
  digitalWrite(pedKananMerah, HIGH);
  delay(1000);
  
  // Lampu kendaraan memasuki fase kuning (transisi) 
  digitalWrite(kendaraanMerah, LOW);
  digitalWrite(kendaraanKuning, HIGH);
  delay(2000); // Jeda transisi kuning
  
  // SISTEM KEMBALI KE KONDISI AWAL 
  digitalWrite(kendaraanKuning, LOW);
  digitalWrite(kendaraanHijau, HIGH);    // Lampu kendaraan hijau 
  // Lampu pedestrian tetap merah
}