///////////////////////////////////////////////////
//            TYY SERA SİSTEMLERİ                //
///////////////////////////////////////////////////
//Selamlar!
//Eğlence için geliştirdiğimiz sera sistemini, herkese açık paylaşmaya karar verdik.
//Gönlünüzce kullanıp değiştirebilirsiniz!
//Versiyon: Alpha

// TYY Ekibi


//kütüphaneler eklendi
#include <DHT.h> //Sera içerisindeki nemi ve sıcaklığı ölçmek için gerekli.
// Sera sistemi için, ortamın nemin ve sıcaklığın ölçülmesi gereklidir.
// Bu ölçümlerle beraber gün içerisindeki sıcaklıkları ölçerek günlük rapor oluşturabilir, sonraki ekeceğiniz sebzeyi/meyveyi seçebilirsiniz kolaylıkla.
//KURULUM İÇİN:
//soldan sağa doğru pinler: - yani delikli noktalar size bakacak
//1. pin 5 volt
//2. pin signal
//3. pin boş - null
//4. pin gnd
//NOT:  1. ve 2. pin arasına 10k direnç koyunuz.
#include <LiquidCrystal.h>
//ui kısmını daha güzel bir hale gelebilmesi için 16x2 lcd ekran kullanmaya karar verdim.
#define DHTPIN 9
#define DHTTYPE DHT22

//burada dht için gerekli ayarlamaları yaptık.
DHT dht(DHTPIN, DHTTYPE);

int dhtPin = 9;

int esikDegeri = 400;
int gazDeger;

//burada lcd için konfigürasyon yaptık.
LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  //Konfigürasyonlar
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
  lcd.print("TYY Sera Sistemleri");
  delay(3000);
  lcd.clear();
  lcd.print("Ver: Alpha")
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  //ana kısım
  delay(2000);
  gazDeger = analogRead(A0);

  //gaz sensörü kontrol
  if(gazDeger > esikDegeri){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("GAZ KACAGI");
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("GAZ KACAGI");
  }
  else{
      Serial.print("Gaz kaçağı bulunmamakta. Tebrikler! Seranızı iyi koruyorsunuz.")
  }
  

  float nem = dht.readHumidity();
  float sicaklik = dht.readTemperature();
  float f = dht.readTemperature(true);  

  if (isnan(sicaklik) || isnan(nem) || isnan(f)) {
    Serial.println(F("DHT CRITICAL 01"));
    lcd.setCursor(0,0);
    lcd.print("DHT CRITICAL 01");
    return;
  }
  
  if(isnan(gazDeger)) {
    lcd.print("MQ CRITICAL 01")
    Serial.println("MQ CRITICAL 01")
  }
  // logging islemi
  Serial.print("Nem:");
  Serial.print(nem);
  Serial.print("Sicaklik:");
  Serial.print(sicaklik);
  Serial.print("________");

  // lcd ekrana dht22den gelen degerler yaziliyor
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Nem Orani:");
  lcd.setCursor(0,10);
  lcd.print((float)nem);

  lcd.setCursor(0,1);
  lcd.print("Sicaklik:");
  lcd.setCursor(9,1);
  lcd.print((float)sicaklik);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Nem Orani:");
  lcd.setCursor(10,0);
  lcd.print(nem);

  lcd.setCursor(0,1);
  lcd.print("Sicaklik:");
  lcd.setCursor(9,1);
  lcd.print(sicaklik);
}