# TheDamaGame
Turkish Dama Game (C++)
Hazırlanan oyunda dama olan taşların gösterimi W/B, dama olmayan taşların gösterimi w/b şeklindedir.


        
## Genel Açıklamalar:
- Oyun tahtası dosya içindedir (index.dat) ve kullanıcının yaptığı hamlelere göre dosya güncellenmektedir.
- Oyun hamle geçmişi ise book.dat dosyası içindedir. Her yeni oyun için yeni başlık altında tüm hamleler listelenmektedir.
- fseekg() fonksiyonu dosyaya erişmek için kullanılmıştır. Parametresi için dosya düzenine uygun oluşturulan formüller kullanılmıştır.
  Çoğu fonksiyonda temel olarak taşın w/b/W/B olmasına göre 4 if komutu yer almaktadır. İf komutları içinde her durum değerlendirildiği için
  satır sayısı fazladır ama temel mantık hepsinde aynıdır.
  
## Örnek Senaryo:
- a3c3 = oyuncudan alınan hamle
  - a = hamle1
  - c = hamle3
  - 3 = int1
  - 3 = int2

- Kısaca: 
  - hamle1-int1 : taşın olduğu yer
  - hamle3-int2 : taşın götürüleceği yer

## Oyunun Çalıştırılması
`g++ dama.cpp` ile cpp dosyası derlenir.
`./a.out` komutu ile çalıştırılır.

![alt text](https://github.com/alihanozen/TheDamaGame/blob/main/dama.png?raw=true) 
