
/*
*******************************************************************************************
**                                                                                       **
**                                    Arduino 4. Proje                                   **
**                                 Mesafe Sensörü ve Ekran                               **
**                                                                                       **
**                                                                                       **
**                                          Cihat                                        **
**                                                                                       **
*******************************************************************************************
*/
#include <LiquidCrystal.h> //Ekranın class'ını tanıtıyoruz.

const int trig = 8; //Sensörün TRİG girişini 8 nolu girişe bağladık.
const int echo = 9; //Sensörün ECHO girişini 9 nolu girişe bağladık.

int sure=0; // sure isminde değişken tanımladık.
int mesafe=0; //mesafe isminde değişken tanımladık.

LiquidCrystal lcd(12,11, 5, 4, 3, 2); // Ekranın pinleri sırasıyla Arduino üzerindeki 12,11,5,4,3,2 numaralı pinlere takılı.

void setup() {
lcd.begin(16, 2); // Ekranın kullanılacağı alan 16 harf 2 satır.
pinMode(trig, OUTPUT); //trig'i çıkış olarak tanımlıyoruz.
pinMode(echo, INPUT); //Ses dalgasının dönüş yaptığı echo'yu giriş olarak tanımlıyoruz.
}

void loop() {
digitalWrite(trig,HIGH); //Ses dalgasını aktif ediyoruz.
delayMicroseconds(1000); //Zamanı ayarlıyoruz.
digitalWrite(trig,LOW); ////trig'i durduruyoruz.

sure = pulseIn(echo, HIGH); //echo verileri alıyor.
mesafe = (sure/2) / 29.1; //mesafeyi hesaplıyoruz.

lcd.print("Mesafe: "); //Ekrana'a önce "Mesafe:" yazdıyoruz.
lcd.print(mesafe); //Mesafe değerini yazdırıyoruz.
lcd.print(" cm"); //değerin sonuna cm yazmasını sağlıyoruz ki anlaşılır olsun.
delay(1000); //Zamanı ayarlıyoruz. Bunu siz değiştirebilirsiniz. Örn:500
}
