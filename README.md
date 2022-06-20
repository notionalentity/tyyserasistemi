# TYY Sera Sistemi

Eğlencesine başladığımız bu sistemi, sizlerle paylaşmaya karar verdik.
Arduino ile yazılmış geniş sera sistemi.
Gönlünüzce kullanıp değiştirebilirsiniz!

# KURULUM 

Bilgisayarınıza Arduino IDE'yi kurun.
Buradan indirebilirsiniz: https://www.arduino.cc/en/software

Kurulduktan sonra Tools>Board kısmından Arduino Uno'yu seçin.
Tools>Port kısmından da Arduino'nun bağlı olduğu COM'u seçin.
Aygıt Yöneticisi'nden öğrenebilirsiniz hangi COM'a bağlı olduğunu.

# DEVRE KURULUMU

Burası biraz karışık.

D3 D7

LCD Ekranımızı D3 D4 D5 D6 D7 yani 2-3-4-5-6-7 pinlerine bağlıyoruz.

Diğer pinleri gereken pinlere - buraları yazmaya üşendim, internetten LiquidCrystal LCD Ekran Kullanımı diye aratabilirsiniz.

Sigara gaz sensörlerinide gerekli yerlere - dirence ihtiyaç yok.

DHT22 sensörümüzü ise, delikli tarafı bize bakacak şekilde pinleri:

1: 5V
2: SIGNAL
3: NULL
4: GND

Bağlantı yaparken 1. ve 2. pinlerin arasına 10k direnç koyun.
Direnç hesaplaması yapmak için: https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-resistor-color-code
1. Pin'i 5 volt'a
2. Pin'i 8. pine
3. Pin boş
4. Pin'i GND kısmına

Not: Eğer 3 pin varsa DHT22'nizde, 3. pini GND olarak baz alın. Direnç kullanmanıza da gerek yok.

-TYY Team
