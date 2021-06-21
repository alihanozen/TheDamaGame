/*
Prepared by "Alihan Özen-1306170091"

Açıklama: Hazırlamış olduğum oyunda dama olan taşların gösterimi W/B, dama olmayan taşların gösterimi w/b şeklindedir.
Görüntüsü ile ilgili sorun yaşadığımdan ötürü, algoritmayı başta bu şekilde kurdum. 
Daha sonra ilerlediğim içinde değiştiremedim. istediğiniz formata uymayan tek durum budur.
Geri kalan kuralları ve oyun içeriğine dair durumları aşağıdaki fonksiyonlardan inceleyebilirsiniz.

Fonksiyon parametreleri ile ilgili olarak: "(string hamle1, string hamle3, int int1, int int2)"
-> anamenu() fonksiyonunda kullanıcıdan yapmak istediği hamle alınır ve hamle adlı string değişkenine atanır.
-> Daha sonra hamle, string parçalama fonksiyonu ile 4 ayrı string değişkenine atanır.
-> Sayı içeren string değişkenleri int değişkenine çevrilir.

Örnek Senaryo:
a3c3 = oyuncudan alınan hamle
a = hamle1
c = hamle3
3 = int1
3 = int2
Kısaca: hamle1-int1 : taşın olduğu yer
        hamle3-int2 : taşın götürüleceği yer

Genel Açıklamalar:
->fseekg() fonksiyonu dosyaya erişmek için kullanılmıştır. Parametresi için dosya düzenime uygun oluşturduğum formülleri kullandım.
->Çoğu fonksiyonda temel olarak taşın w/b/W/B olmasına göre 4 if komutu yer almaktadır. İf komutları içinde her durum değerlendirildiği için
satır sayısı fazladır ama temel mantık hepsinde aynıdır.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

using namespace std;

// ANAMENU_MESAJ = "Lütfen bir seçim yapınız"

//İç içe kullandığım 3 fonksiyonun bildirimi
void tasoyna(string hamle1, string hamle3, int int1, int int2);
void siradegis();
bool tasyemek(string hamle1, string hamle3, int int1, int int2);
bool status;

void hamleler(string hamle){ 
    // Fonksiyon Açıklaması: Oyuncular tarafından girilen hamleler book.dat adlı dosyaya eklenir.
    fstream f7; 
    f7.open("index.dat", ios::out | ios::in);
    string sira;
    f7.seekg(0);
    f7>>sira; //oyunun bulunduğu index.dat dosyasından sıra bilgisi alınır
    f7.close();

    fstream f8; 
    f8.open("book.dat", ios::app);
    f8<<sira << ":" << hamle << endl; //book.dat dosyasına sıra bilgisi ve kullanıcıdan alınan hamle istenilen formatta eklenir.
    f8.close();
}

bool kural(string hamle1, string hamle3, int int1, int int2){
    //Fonksiyon Açıklaması: Taş oynatma kuralları için oluşturuldu, true dönerse hamle gerçekleşir.
    fstream f6; 
    f6.open("index.dat", ios::out | ios::in);
    int z;
    if(hamle1=="a"){ z=0; } if(hamle1=="b"){ z=1; }
    if(hamle1=="c"){ z=2; } if(hamle1=="d"){ z=3; }
    if(hamle1=="e"){ z=4; } if(hamle1=="f"){ z=5; }
    if(hamle1=="g"){ z=6; } if(hamle1=="h"){ z=7; }
    char kntrl;
    f6.seekg((244+(4*z))-((int1-1)*34));
    f6 >> kntrl; //oynatılacak taş bilgisi kntrl adlı string değişkenine atılır

    int x,y;
    if(hamle1=="a"){ x=1; } if(hamle1=="b"){ x=2; }
    if(hamle1=="c"){ x=3; } if(hamle1=="d"){ x=4; }
    if(hamle1=="e"){ x=5; } if(hamle1=="f"){ x=6; }
    if(hamle1=="g"){ x=7; } if(hamle1=="h"){ x=8; }

    if(hamle3=="a"){ y=1; } if(hamle3=="b"){ y=2; }
    if(hamle3=="c"){ y=3; } if(hamle3=="d"){ y=4; }
    if(hamle3=="e"){ y=5; } if(hamle3=="f"){ y=6; }
    if(hamle3=="g"){ y=7; } if(hamle3=="h"){ y=8; }
    /*kntrl adı string değişkeninin w,b,W,B olmasında göre 4 adet if sorgusu oluşturulmuştur.
    Her durum için yana, ileri, taş dama iste geri gidebilmesine dair kısıtlamalar iç içe if ifadeleri içinde yazılmıştır.
    Kurallara uygun bir hamle is true döndürülür.
    */
    fstream f4; 
    f4.open("index.dat", ios::out | ios::in);
    if(kntrl=='w'){
        if(hamle1==hamle3){
            if((int2==int1+1) || (int2==int1+2)){
                return true;
            }
            else{
                return false;
            }
        } 
        if((int2==int1) && ((y-x==2) || (x-y==2) || (y-x==1) || (x-y==1))){
            return true;
        }
        else{
            return false;
        }
    }

    if(kntrl=='b'){
        if(hamle1==hamle3){
            if((int1==int2+1) || (int1==int2+2)){
                return true;
            }
            else{
                return false;
            }
        } 
        if((int2==int1) && ((y-x==2) || (x-y==2) || (y-x==1) || (x-y==1))){
            return true;
        } 
        else{
            return false;
        }
    }

    if(kntrl=='W'){
        if((hamle1==hamle3) || (int1==int2)){
            return true;
        }
        else{
            return false;
        }
    }

    if(kntrl=='B'){
        if((hamle1==hamle3) || (int1==int2)){
            return true;
        }  
        else{
            return false;
        }
    }
    f4.close();
    return 0;
}

void pespese(string hamle1, string hamle3, int int1, int int2){  
    fstream f6; 
    f6.open("index.dat", ios::out | ios::in);
    char knt; char knt2; char knt3; char knt4; char knt5; char knt6; char knt7;
    int x; int y;
    int i; char a1; char a2; char a3; char a4; char a5; char a6;
    if(status==true){   
    /* 
    "status" tasyemek adlı fonksiyonu tarafından döndürülen değerdir. Eğer oyuncunun yaptığı hamle sonucu taş yenildiyse status değeri true olur 
    ve pespese fonksiyonu aktif olur. 
    -> Fonksiyonda oyuncunun oynattığı taş "knt" adlı string değişkenine atanır.
    -> taşın w/b/W/B olma durmuna göre sağında, solunda, önünde ve eğer taş dama ise geride zıt taş olup olmadığı ve zıt taştan sonrada boş yer olup
    olmadığı kontrol edilir (normal taş ise 1 ileri/sağ/sol, dama taşı ise ileri,geri,sağ,sol) ve şartlar sağlanırsa peşpeşe aktif olur ve uyarı çıkar, 
    sıra değişmez, kullanıcıdan tekrar hamle istenir.
    */    
        if(hamle3=="a"){ x=0;}; if(hamle3=="b"){ x=1;}; 
        if(hamle3=="c"){ x=2;}; if(hamle3=="d"){ x=3;};
        if(hamle3=="e"){ x=4;}; if(hamle3=="f"){ x=5;};
        if(hamle3=="g"){ x=6;}; if(hamle3=="h"){ x=7;};

        if(hamle1=="a"){ y=0;}; if(hamle1=="b"){ y=1;}; 
        if(hamle1=="c"){ y=2;}; if(hamle1=="d"){ y=3;};
        if(hamle1=="e"){ y=4;}; if(hamle1=="f"){ y=5;};
        if(hamle1=="g"){ y=6;}; if(hamle1=="h"){ y=7;};

        f6.seekg((244+(4*x))-((int2-1)*34));
        f6>>knt;
        if(knt=='w'){ //taş yeme olduktan sonra sağ sol ön kontrol edilir ve tekrar taş yeme varsa sıra değişmez
            f6.seekg((244+(4*x))-((int2)*34));
            f6>>knt2;
            f6.seekg(((244+(4*x))-((int2-1)*34))+4);
            f6>>knt4;
            f6.seekg(((244+(4*x))-((int2-1)*34))-4);
            f6>>knt5;
            if(knt2=='b' || knt2=='B' || knt4=='b' || knt4=='B' || knt5=='b' || knt5=='B'){
                f6.seekg((244+(4*x))-((int2+1)*34));
                f6>>knt3;
                f6.seekg(((244+(4*x))-((int2-1)*34))+8);
                f6>>knt6;
                f6.seekg(((244+(4*x))-((int2-1)*34))-8);
                f6>>knt7;
                if( knt3=='_' || knt6=='_' || knt7=='_'){
                    cout<<"Peşpeşe taş yemek için devam et! " << endl;
                        string beyaz = "W";
                        f6.seekg(0); 
                        f6<<beyaz;                     
                }
            }
        }      
        
        if(knt=='b'){ //taş yeme olduktan sonra sağ sol ön kontrol edilir ve tekrar taş yeme varsa sıra değişmez
            f6.seekg((244+(4*x))-((int2-2)*34));
            f6>>knt2;
            if(knt2=='w' || knt2=='W'){
                f6.seekg((244+(4*x))-((int2-3)*34));
                f6>>knt3;
                if(knt3!='_'){
                    cout<<"Peşpeşe taş yemek için devam et! " << endl; 
                        string siyah = "B";
                        f6.seekg(0); 
                        f6<<siyah;
                }
            }
            f6.seekg(((244+(4*x))-((int2-1)*34))+4);
            f6>>knt4;
            if(knt4=='w' || knt4=='W'){
                f6.seekg(((244+(4*x))-((int2-1)*34))+8);
                f6>>knt6;
                if(knt6!='_'){
                    cout<<"Peşpeşe taş yemek için devam et! " << endl;
                        string siyah = "B";
                        f6.seekg(0); 
                        f6<<siyah;  
                }
            }
            f6.seekg(((244+(4*x))-((int2-1)*34))-4);
            f6>>knt5;
            if(knt5=='w' || knt5=='W'){
                f6.seekg(((244+(4*x))-((int2-1)*34))-8);
                f6>>knt7;
                if(knt7!='_'){
                    cout<<"Peşpeşe taş yemek için devam et! " << endl;
                        string siyah = "B";
                        f6.seekg(0); 
                        f6<<siyah;                    
                }
            }       
        }

        if(knt=='W'){ 
            //taş yeme olduktan sonra sağ sol ön geri kontrol edilir ve tekrar taş yeme varsa sıra değişmez
            //tüm durumlar ele alındığı için W ve B uzun olmuştur.
            if(int1>int2){
                for(i=int2; i>1; i--){
                    f6.seekg((244+(4*x))-((i-2)*34));
                    f6>>a1;
                    f6.seekg((244+(4*x))-((i-3)*34));
                    f6>>a2;
                    if((a1=='b' || a1=='B') && a2=='_'){
                        cout<<"Peşpeşe taş yemek için devam et! " << endl;
                            string beyaz = "W";
                            f6.seekg(0); 
                            f6<<beyaz;                    
                    }
                }

                for(i=x+1; i<7; i++){
                    f6.seekg((244+(4*i))-((int2-1)*34));
                    f6>>a3;
                    f6.seekg((244+(4*(i+1)))-((int2-1)*34));
                    f6>>a4;
                    if((a3=='b' || a3=='B') && a4=='_'){
                        cout<<"Peşpeşe taş yemek için devam et! " << endl;
                            string beyaz = "W";
                            f6.seekg(0); 
                            f6<<beyaz;           
                    }
                }

                for(i=x-1; i>1; i--){
                    f6.seekg((244+(4*i))-((int2-1)*34));
                    f6>>a5;
                    f6.seekg((244+(4*(i-1)))-((int2-1)*34));
                    f6>>a6;
                    if((a5=='b' || a5=='B') && a6=='_'){
                        cout<<"Peşpeşe taş yemek için devam et! " << endl;
                            string beyaz = "W";
                            f6.seekg(0); 
                            f6<<beyaz;          
                    }
                }
            }
            if(int2>int1){
                for(i=int2; i<7; i++){
                    f6.seekg((244+(4*x))-(i*34));
                    f6>>a1;
                    f6.seekg((244+(4*x))-((i+1)*34));
                    f6>>a2;
                    if((a1=='b' || a1=='B') && a2=='_'){
                        cout<<"Peşpeşe taş yemek için devam et! " << endl;
                            string beyaz = "W";
                            f6.seekg(0); 
                            f6<<beyaz;                       
                    }
                }
                for(i=x+1; i<7; i++){
                    f6.seekg((244+(4*i))-((int2-1)*34));
                    f6>>a3;
                    f6.seekg((244+(4*(i+1)))-((int2-1)*34));
                    f6>>a4;
                    if((a3=='b' || a3=='B') && a4=='_'){
                        cout<<"Peşpeşe taş yemek için devam et! " << endl;
                            string beyaz = "W";
                            f6.seekg(0); 
                            f6<<beyaz;     
                    }
                }

                for(i=x-1; i>1; i--){
                    f6.seekg((244+(4*i))-((int2-1)*34));
                    f6>>a1;
                    f6.seekg((244+(4*(i-1)))-((int2-1)*34));
                    f6>>a2;
                    if((a5=='b' || a5=='B') && a6=='_'){
                        cout<<"Peşpeşe taş yemek için devam et! " << endl;
                            string beyaz = "W";
                            f6.seekg(0); 
                            f6<<beyaz;                      
                    }
                }
            }
            if(int1==int2){
                if(x>y){
                    for(i=int2; i>1; i--){
                        f6.seekg((244+(4*x))-((i-2)*34));
                        f6>>a1;
                        f6.seekg((244+(4*x))-((i-3)*34));
                        f6>>a2;
                        if((a1=='b' || a1=='B') && a2=='_'){
                            cout<<"Peşpeşe taş yemek için devam et! " << endl;
                                string beyaz = "W";
                                f6.seekg(0); 
                                f6<<beyaz;                             
                        }
                    }

                    for(i=int2; i<7; i++){
                        f6.seekg((244+(4*x))-(i*34));
                        f6>>a3;
                        f6.seekg((244+(4*x))-((i+1)*34));
                        f6>>a4;
                        if((a3=='b' || a3=='B') && a4=='_'){
                            cout<<"Peşpeşe taş yemek için devam et! " << endl;
                                string beyaz = "W";
                                f6.seekg(0); 
                                f6<<beyaz;                             
                        }
                    }

                    for(i=x+1; i<7; i++){
                        f6.seekg((244+(4*i))-((int2-1)*34));
                        f6>>a5;
                        f6.seekg((244+(4*(i+1)))-((int2-1)*34));
                        f6>>a6;
                        if((a5=='b' || a5=='B') && a6=='_'){
                            cout<<"Peşpeşe taş yemek için devam et! " << endl;
                                string beyaz = "W";
                                f6.seekg(0); 
                                f6<<beyaz;                          
                        }
                    }
                }
                if(y>x){
                    for(i=int2; i>1; i--){
                        f6.seekg((244+(4*x))-((i-2)*34));
                        f6>>a1;
                        f6.seekg((244+(4*x))-((i-3)*34));
                        f6>>a2;
                        if((a1=='b' || a1=='B') && a2=='_'){
                            cout<<"Peşpeşe taş yemek için devam et! " << endl;
                                string beyaz = "W";
                                f6.seekg(0); 
                                f6<<beyaz;                           
                        }
                    }
                    for(i=int2; i<7; i++){
                        f6.seekg((244+(4*x))-(i*34));
                        f6>>a3;
                        f6.seekg((244+(4*x))-((i+1)*34));
                        f6>>a4;
                        if((a3=='b' || a3=='B') && a4=='_'){
                            cout<<"Peşpeşe taş yemek için devam et! " << endl;
                                string beyaz = "W";
                                f6.seekg(0); 
                                f6<<beyaz;                       
                        }
                    }
                    for(i=x-1; i>1; i--){
                        f6.seekg((244+(4*i))-((int2-1)*34));
                        f6>>a5;
                        f6.seekg((244+(4*(i-1)))-((int2-1)*34));
                        f6>>a6;
                        if((a5=='b' || a5=='B') && a6=='_'){
                            cout<<"Peşpeşe taş yemek için devam et! " << endl;         
                                string beyaz = "W";
                                f6.seekg(0); 
                                f6<<beyaz;                             
                        }
                    }
                }
            }
        }

        if(knt=='B'){
            //taş yeme olduktan sonra sağ sol ön geri kontrol edilir ve tekrar taş yeme varsa sıra değişmez
            //tüm durumlar ele alındığı için W ve B uzun olmuştur.
            if(int1>int2){
                for(i=int2; i>1; i--){
                    f6.seekg((244+(4*x))-((i-2)*34));
                    f6>>a1;
                    f6.seekg((244+(4*x))-((i-3)*34));
                    f6>>a2;
                    if((a1=='w' || a1=='W') && a2=='_'){
                        cout<<"Peşpeşe taş yemek için devam et! " << endl;
                            string beyaz = "B";
                            f6.seekg(0); 
                            f6<<beyaz;                       
                    }
                }

                for(i=x+1; i<7; i++){
                    f6.seekg((244+(4*i))-((int2-1)*34));
                    f6>>a3;
                    f6.seekg((244+(4*(i+1)))-((int2-1)*34));
                    f6>>a4;
                    if((a3=='w' || a3=='W') && a4=='_'){
                        cout<<"Peşpeşe taş yemek için devam et! " << endl;
                            string beyaz = "B";
                            f6.seekg(0); 
                            f6<<beyaz;                         
                    }
                }

                for(i=x-1; i>1; i--){
                    f6.seekg((244+(4*i))-((int2-1)*34));
                    f6>>a5;
                    f6.seekg((244+(4*(i-1)))-((int2-1)*34));
                    f6>>a6;
                    if((a5=='w' || a5=='W') && a6=='_'){
                        cout<<"Peşpeşe taş yemek için devam et! " << endl;            
                            string beyaz = "B";
                            f6.seekg(0); 
                            f6<<beyaz;                        
                    }
                }
            }
            if(int2>int1){
                for(i=int2; i<7; i++){
                    f6.seekg((244+(4*x))-(i*34));
                    f6>>a1;
                    f6.seekg((244+(4*x))-((i+1)*34));
                    f6>>a2;
                    if((a1=='w' || a1=='W') && a2=='_'){
                        cout<<"Peşpeşe taş yemek için devam et! " << endl; 
                            string beyaz = "B";
                            f6.seekg(0); 
                            f6<<beyaz;                    
                    }
                }
                for(i=x+1; i<7; i++){
                    f6.seekg((244+(4*i))-((int2-1)*34));
                    f6>>a3;
                    f6.seekg((244+(4*(i+1)))-((int2-1)*34));
                    f6>>a4;
                    if((a3=='w' || a3=='W') && a4=='_'){
                        cout<<"Peşpeşe taş yemek için devam et! " << endl;    
                            string beyaz = "B";
                            f6.seekg(0); 
                            f6<<beyaz;                         
                    }
                }

                for(i=x-1; i>1; i--){
                    f6.seekg((244+(4*i))-((int2-1)*34));
                    f6>>a1;
                    f6.seekg((244+(4*(i-1)))-((int2-1)*34));
                    f6>>a2;
                    if((a5=='w' || a5=='W') && a6=='_'){
                        cout<<"Peşpeşe taş yemek için devam et! " << endl;         
                            string beyaz = "B";
                            f6.seekg(0); 
                            f6<<beyaz;                        
                    }
                }
            }
            if(int1==int2){
                if(x>y){
                    for(i=int2; i>1; i--){
                        f6.seekg((244+(4*x))-((i-2)*34));
                        f6>>a1;
                        f6.seekg((244+(4*x))-((i-3)*34));
                        f6>>a2;
                        if((a1=='w' || a1=='W') && a2=='_'){
                            cout<<"Peşpeşe taş yemek için devam et! " << endl;          
                                string beyaz = "B";
                                f6.seekg(0); 
                                f6<<beyaz;                            
                        }
                    }

                    for(i=int2; i<7; i++){
                        f6.seekg((244+(4*x))-(i*34));
                        f6>>a3;
                        f6.seekg((244+(4*x))-((i+1)*34));
                        f6>>a4;
                        if((a3=='w' || a3=='W') && a4=='_'){
                            cout<<"Peşpeşe taş yemek için devam et! " << endl;             
                                string beyaz = "B";
                                f6.seekg(0); 
                                f6<<beyaz;                         
                        }
                    }

                    for(i=x+1; i<7; i++){
                        f6.seekg((244+(4*i))-((int2-1)*34));
                        f6>>a5;
                        f6.seekg((244+(4*(i+1)))-((int2-1)*34));
                        f6>>a6;
                        if((a5=='w' || a5=='W') && a6=='_'){
                            cout<<"Peşpeşe taş yemek için devam et! " << endl;                 
                                string beyaz = "B";
                                f6.seekg(0); 
                                f6<<beyaz;                        
                        }
                    }
                }
                if(y>x){
                    for(i=int2; i>1; i--){
                        f6.seekg((244+(4*x))-((i-2)*34));
                        f6>>a1;
                        f6.seekg((244+(4*x))-((i-3)*34));
                        f6>>a2;
                        if((a1=='w' || a1=='W') && a2=='_'){
                            cout<<"Peşpeşe taş yemek için devam et! " << endl;                 
                                string beyaz = "B";
                                f6.seekg(0); 
                                f6<<beyaz;                          
                        }
                    }
                    for(i=int2; i<7; i++){
                        f6.seekg((244+(4*x))-(i*34));
                        f6>>a3;
                        f6.seekg((244+(4*x))-((i+1)*34));
                        f6>>a4;
                        if((a3=='w' || a3=='W') && a4=='_'){
                            cout<<"Peşpeşe taş yemek için devam et! " << endl;                 
                                string beyaz = "B";
                                f6.seekg(0); 
                                f6<<beyaz;                             
                        }
                    }
                    for(i=x-1; i>1; i--){
                        f6.seekg((244+(4*i))-((int2-1)*34));
                        f6>>a5;
                        f6.seekg((244+(4*(i-1)))-((int2-1)*34));
                        f6>>a6;
                        if((a5=='w' || a5=='W') && a6=='_'){
                            cout<<"Peşpeşe taş yemek için devam et! " << endl;                   
                                string beyaz = "B";
                                f6.seekg(0); 
                                f6<<beyaz;                            
                        }
                    }
                }
            }
        }
    }

    f6.close();
}

bool tasyemek(string hamle1, string hamle3, int int1, int int2){
    /* 
    Oyuncu eğer normal taşı 2 birim ileri,sağa ya da sola oynattıysa ve 1 birim gerisinde zıt taş var ise fonksiyon aktif olur.
    Dama olan taş için ise oynatılan güzergahta sadece 1 adet zıt taş var ise fonksiyon aktif olur.
    Fonksiyon türünün bool olmasının sebebi "pespese" adlı fonksiyonun kontrollü gerçekleşmesi içindir.
    */ 
    fstream f5; 
    f5.open("index.dat", ios::out | ios::in);
    int x;
    status = false;
    if(hamle1=="a"){ x=0; } if(hamle1=="b"){ x=1; }
    if(hamle1=="c"){ x=2; } if(hamle1=="d"){ x=3; }
    if(hamle1=="e"){ x=4; } if(hamle1=="f"){ x=5; }
    if(hamle1=="g"){ x=6; } if(hamle1=="h"){ x=7; }
    int y;
    if(hamle3=="a"){ y=0; } if(hamle3=="b"){ y=1; }
    if(hamle3=="c"){ y=2; } if(hamle3=="d"){ y=3; }
    if(hamle3=="e"){ y=4; } if(hamle3=="f"){ y=5; }
    if(hamle3=="g"){ y=6; } if(hamle3=="h"){ y=7; }
    char kntrl; 
    f5.seekg((244+(4*x))-((int1-1)*34));
    f5 >> kntrl;
    char kntrl2;
    if(kntrl == 'w'){
        if(hamle1==hamle3 && int2 == int1+2){ //ileri yönde taş yeme kontrolü
            f5.seekg((244+(4*x))-((int1)*34));
            f5>>kntrl2;
            if(kntrl2=='b' || kntrl2=='B'){
                f5.seekg((244+(4*x))-((int1)*34));
                f5 << '_';
                status = true;  
                return status;
            } 
        }
        if(int1==int2){ //sağ ve sol taş yeme kontrolü
            if((hamle1=="a" || hamle1=="A") && (hamle3=="c" || hamle3=="C")){
                f5.seekg(248-((int1-1)*34));
                f5>>kntrl2;
                if(kntrl2=='b' || kntrl2=='B'){
                    f5.seekg(248-((int1-1)*34));
                    f5 << "_";
                    status = true;
                    return status;
                }
            }        
            if((hamle1=="b" || hamle1=="B") && (hamle3=="d" || hamle3=="D")){
                f5.seekg(252-((int1-1)*34));
                f5>>kntrl2;
                if(kntrl2=='b' || kntrl2=='B'){
                    f5.seekg(252-((int1-1)*34));
                    f5 << "_";
                    status = true;
                    return status;
                }                 
            }
            if(hamle1=="c" || hamle1=="C"){
                if(hamle3=="e" || hamle3=="E"){
                    f5.seekg(256-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='b' || kntrl2=='B'){
                        f5.seekg(256-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    }
                } 
                if(hamle3=="a" || hamle3=="A"){
                    f5.seekg(248-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='b' || kntrl2=='B'){
                        f5.seekg(248-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    }
                }     
            }
            if(hamle1=="d" || hamle1=="D"){
                if(hamle3=="f" || hamle3=="F"){
                    f5.seekg(260-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='b' || kntrl2=='B'){
                        f5.seekg(260-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    } 
                } 
                if(hamle3=="b" || hamle3=="B"){
                    f5.seekg(252-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='b' || kntrl2=='B'){
                        f5.seekg(252-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    } 
                } 
            }
            if(hamle1=="e" || hamle1=="E"){
                if(hamle3=="g" || hamle3=="G"){
                    f5.seekg(264-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='b' || kntrl2=='B'){
                        f5.seekg(264-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    } 
                } 
                if(hamle3=="c" || hamle3=="C"){
                    f5.seekg(256-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='b' || kntrl2=='B'){
                        f5.seekg(256-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    } 
                }    
            }
            if(hamle1=="f" || hamle1=="F"){
                if(hamle3=="h" || hamle3=="H"){
                    f5.seekg(268-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='b' || kntrl2=='B'){
                        f5.seekg(268-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    } 
                } 
                if(hamle3=="d" || hamle3=="D"){
                    f5.seekg(260-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='b' || kntrl2=='B'){
                        f5.seekg(260-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    } 
                }     
            }
            if((hamle1=="g" || hamle1=="G") && (hamle3=="e" || hamle3=="E")){
                f5.seekg(264-((int1-1)*34));
                f5>>kntrl2;
                if(kntrl2=='b' || kntrl2=='B'){
                    f5.seekg(264-((int1-1)*34));
                    f5 << "_";
                    status = true;
                    return status;
                }      
            }
            if((hamle1=="h" || hamle1=="H") && (hamle3=="f" || hamle3=="F")){
                f5.seekg(268-((int1-1)*34));
                f5>>kntrl2;
                if(kntrl2=='b' || kntrl2=='B'){
                    f5.seekg(268-((int1-1)*34));
                    f5 << "_";
                    status = true;
                    return status;
                }      
            }
        }
    }
    if(kntrl == 'b'){
        if(hamle1==hamle3 && int1 == int2+2){ // ileri yönde taş yeme kontrolü
            f5.seekg((244+(4*x))-((int2)*34));
            f5>>kntrl2;
                if(kntrl2=='w' || kntrl2=='W'){
                    f5.seekg((244+(4*x))-((int2)*34));
                    f5 << "_";
                    status = true; 
                    return status;
                }         
        }
        if(int1==int2){ // sağ ve sol taş yeme kontrolü
            if((hamle1=="a" || hamle1=="A") && (hamle3=="c" || hamle3=="C")){
                f5.seekg(248-((int1-1)*34));
                f5>>kntrl2;
                if(kntrl2=='w' || kntrl2=='W'){
                    f5.seekg(248-((int1-1)*34));
                    f5 << "_";
                    status = true;
                    return status;
                }
            }        
            if((hamle1=="b" || hamle1=="B") && (hamle3=="d" || hamle3=="D")){
                f5.seekg(252-((int1-1)*34));
                f5>>kntrl2;
                if(kntrl2=='w' || kntrl2=='W'){
                    f5.seekg(252-((int1-1)*34));
                    f5 << "_";
                    status = true;
                    return status;
                }                
            }
            if(hamle1=="c" || hamle1=="C"){
                if(hamle3=="e" || hamle3=="E"){
                    f5.seekg(256-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='w' || kntrl2=='W'){
                        f5.seekg(256-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    }
                } 
                if(hamle3=="a" || hamle3=="A"){
                    f5.seekg(248-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='w' || kntrl2=='W'){
                        f5.seekg(248-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    }
                }     
            }
            if(hamle1=="d" || hamle1=="D"){
                if(hamle3=="f" || hamle3=="F"){
                    f5.seekg(260-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='w' || kntrl2=='W'){
                        f5.seekg(260-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    }
                } 
                if(hamle3=="b" || hamle3=="B"){
                    f5.seekg(252-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='w' || kntrl2=='W'){
                        f5.seekg(252-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    } 
                } 
            }
            if(hamle1=="e" || hamle1=="E"){
                if(hamle3=="g" || hamle3=="G"){
                    f5.seekg(264-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='w' || kntrl2=='W'){
                        f5.seekg(264-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    } 
                } 
                if(hamle3=="c" || hamle3=="C"){
                    f5.seekg(256-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='w' || kntrl2=='W'){
                        f5.seekg(256-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    } 
                }    
            }
            if(hamle1=="f" || hamle1=="F"){
                if(hamle3=="h" || hamle3=="H"){
                    f5.seekg(268-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='w' || kntrl2=='W'){
                        f5.seekg(268-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    } 
                } 
                if(hamle3=="d" || hamle3=="D"){
                    f5.seekg(260-((int1-1)*34));
                    f5>>kntrl2;
                    if(kntrl2=='w' || kntrl2=='W'){
                        f5.seekg(260-((int1-1)*34));
                        f5 << "_";
                        status = true;
                        return status;
                    } 
                }     
            }
            if((hamle1=="g" || hamle1=="G") && (hamle3=="e" || hamle3=="E")){
                f5.seekg(264-((int1-1)*34));
                f5>>kntrl2;
                if(kntrl2=='w' || kntrl2=='W'){
                    f5.seekg(264-((int1-1)*34));
                    f5 << "_";
                    status = true;
                    return status;
                }  
            }
            if((hamle1=="h" || hamle1=="H") && (hamle3=="f" || hamle3=="F")){
                f5.seekg(268-((int1-1)*34));
                f5>>kntrl2;
                if(kntrl2=='w' || kntrl2=='W'){
                    f5.seekg(268-((int1-1)*34));
                    f5 << "_";
                    status = true;
                    return status;
                }    
            }
        }
    }
    if(kntrl == 'W'){
        int i;
        int sayac=0;
        char harf;
        if(int1 > int2){ //ileri yönde taş yeme kontrolü
            for(i=int2; i<int1-1; i++){
                f5.seekg((244+(4*x))-(i*34));
                f5>>harf;
                if(harf=='b' || harf=='B'){
                    sayac++;
                }
            }
            if(sayac==1){
                for(i=int2; i<int1-1; i++){
                    f5.seekg((244+(4*x))-(i*34));
                    f5<<"_";
                }
                status = true;
                return status;
            }
        }
        
        if(int2 > int1){ //geri yönde taş yeme kontrolü
            for(i=int1; i<int2-1; i++){
                f5.seekg((244+(4*x))-(i*34));
                f5>>harf;
                if(harf=='b' || harf=='B'){
                    sayac++;
                }
            }
            if(sayac==1){
                for(i=int1; i<int2-1; i++){
                    f5.seekg((244+(4*x))-(i*34));
                    f5<<"_";
                }
                status = true;
                return status;
            }
        }

        if(int1 == int2){ //sağ/sol yönde taş yeme kontrolü
            if(y>x){
                for(i=x+1; i<y; i++){
                    f5.seekg((244+(4*i))-((int2-1)*34));
                    f5>>harf;
                    if(harf=='b' || harf=='B'){
                        sayac++;
                    }
                }
                if(sayac==1){
                    for(i=x+1; i<y; i++){
                        f5.seekg((244+(4*i))-((int2-1)*34));
                        f5<<"_";
                    }
                    status = true;
                    return status;
                }
            }
            if(x>y){
                for(i=x-1; i>y; i--){
                    f5.seekg((244+(4*i))-((int2-1)*34));
                    f5>>harf;
                    if(harf=='b' || harf=='B'){
                        sayac++;
                    }
                }
                if(sayac==1){
                    for(i=x-1; i>y; i--){
                        f5.seekg((244+(4*i))-((int2-1)*34));
                        f5<<"_";
                    }
                    status = true;
                    return status;
                }
            }
            
        }
    }
    if(kntrl == 'B'){
        int i;
        int sayac=0;
        char harf;
        if(int1 > int2){ //geri yönde taş yeme kontrolü
            for(i=int2; i<int1-1; i++){
                f5.seekg((244+(4*x))-(i*34));
                f5>>harf;
                if(harf=='w' || harf=='W'){
                    sayac++;
                }
            }
            if(sayac==1){
                for(i=int2; i<int1-1; i++){
                    f5.seekg((244+(4*x))-(i*34));
                    f5<<"_";
                }
                status = true;
                return status;
            }
        }
        
        if(int2 > int1){ //ileri yönde taş yeme kontrolü
            for(i=int1; i<int2-1; i++){
                f5.seekg((244+(4*x))-(i*34));
                f5>>harf;
                if(harf=='w' || harf=='W'){
                    sayac++;
                }
            }
            if(sayac==1){
                for(i=int1; i<int2-1; i++){
                    f5.seekg((244+(4*x))-(i*34));
                    f5<<"_";
                }
                status = true;
                return status;
            }
        }

        if(int1 == int2){ //sağ/sol yönde taş yeme kontrolü
            if(y>x){
                for(i=x+1; i<y; i++){
                    f5.seekg((244+(4*i))-((int2-1)*34));
                    f5>>harf;
                    if(harf=='w' || harf=='W'){
                        sayac++;
                    }
                }
                if(sayac==1){
                    for(i=x+1; i<y; i++){
                        f5.seekg((244+(4*i))-((int2-1)*34));
                        f5<<"_";
                    }
                    status = true;
                    return status;
                }
            }
            if(x>y){
                for(i=x-1; i>y; i--){
                    f5.seekg((244+(4*i))-((int2-1)*34));
                    f5>>harf;
                    if(harf=='w' || harf=='W'){
                        sayac++;
                    }
                }
                if(sayac==1){
                    for(i=x-1; i>y; i--){
                        f5.seekg((244+(4*i))-((int2-1)*34));
                        f5<<"_";
                    }
                    status = true;
                    return status;
                }
            }
            
        }
    }
return 0;
}

void tasoyna(string hamle1, string hamle3, int int1, int int2){
    //Fonksiyon Açıklaması: Taş, kural adlı fonksiyondan true dönerse oynatılır ve istenilen yere taşınır.
    fstream f; 
    f.open("index.dat", ios::out | ios::in);
    int x;
    if(hamle1=="a"){ x=0; } if(hamle1=="b"){ x=1; }
    if(hamle1=="c"){ x=2; } if(hamle1=="d"){ x=3; }
    if(hamle1=="e"){ x=4; } if(hamle1=="f"){ x=5; }
    if(hamle1=="g"){ x=6; } if(hamle1=="h"){ x=7; }
    //Girilen hamleye göre oynatılmak istenilen taşa gidilir ve onu "tas" adlı string değişkenine atar.
    char tas;
    f.seekg((244+(4*x))-((int1-1)*34));
    f >> tas;

    if(kural(hamle1, hamle3, int1, int2)){ //taşın olduğu yere _ yazılır yani taş oradan alınır.
        tasyemek(hamle1, hamle3, int1, int2); //taş yeme durumu varsa çalışır.
        if(hamle1=="a" || hamle1=="A"){
            f.seekg(244-((int1-1)*34));
            f << "_";  
        }
        if(hamle1=="b" || hamle1=="B"){
            f.seekg(248-((int1-1)*34));
            f << "_";           
        }
        if(hamle1=="c" || hamle1=="C"){
            f.seekg(252-((int1-1)*34));
            f << "_"; 
        }
        if(hamle1=="d" || hamle1=="D"){ 
            f.seekg(256-((int1-1)*34));
            f << "_"; 
        }
        if(hamle1=="e" || hamle1=="E"){ 
            f.seekg(260-((int1-1)*34));
            f << "_";
        }
        if(hamle1=="f" || hamle1=="F"){
            f.seekg(264-((int1-1)*34));
            f << "_"; 
        }
        if(hamle1=="g" || hamle1=="G"){
            f.seekg(268-((int1-1)*34));
            f << "_";   
        }
        if(hamle1=="h" || hamle1=="H"){ 
            f.seekg(272-((int1-1)*34));
            f << "_";    
        }

        
        //hamleye göre alınan taş istenilen yere eklenir.
        if(hamle3=="a" || hamle3=="A"){
            f.seekg(244-((int2-1)*34));
            if(int2 == 1 || int2==8){
                if(tas=='w'){f << 'W';}
                if(tas=='b'){f << 'B';}
                if(tas=='W'){f << 'W';}
                if(tas=='B'){f << 'B';}
            }
            else{
                f << tas;
            }
        }
        if(hamle3=="b" || hamle3=="B"){
            f.seekg(248-((int2-1)*34));
            if(int2 == 1 || int2==8){
                if(tas=='w'){f << 'W';}
                if(tas=='b'){f << 'B';}
                if(tas=='W'){f << 'W';}
                if(tas=='B'){f << 'B';}
            }
            else{
                f << tas;
            }          
        }
        if(hamle3=="c" || hamle3=="C"){
            f.seekg(252-((int2-1)*34));
            if(int2 == 1 || int2==8){
                if(tas=='w'){f << 'W';}
                if(tas=='b'){f << 'B';}
                if(tas=='W'){f << 'W';}
                if(tas=='B'){f << 'B';}
            }
            else{
                f << tas;
            }  
        }
        if(hamle3=="d" || hamle3=="D"){
            f.seekg(256-((int2-1)*34));
            if(int2 == 1 || int2==8){
                if(tas=='w'){f << 'W';}
                if(tas=='b'){f << 'B';}
                if(tas=='W'){f << 'W';}
                if(tas=='B'){f << 'B';}
            }
            else{
                f << tas;
            }
        }
        if(hamle3=="e" || hamle3=="E"){
            f.seekg(260-((int2-1)*34));
            if(int2 == 1 || int2==8){
                if(tas=='w'){f << 'W';}
                if(tas=='b'){f << 'B';}
                if(tas=='W'){f << 'W';}
                if(tas=='B'){f << 'B';}
            }
            else{
                f << tas;
            }
    
        }
        if(hamle3=="f" || hamle3=="F"){
            f.seekg(264-((int2-1)*34));
            if(int2 == 1 || int2==8){
                if(tas=='w'){f << 'W';}
                if(tas=='b'){f << 'B';}
                if(tas=='W'){f << 'W';}
                if(tas=='B'){f << 'B';}
            }
            else{
                f << tas;
            } 
        }
        if(hamle3=="g" || hamle3=="G"){
            f.seekg(268-((int2-1)*34));
            if(int2 == 1 || int2==8){
                if(tas=='w'){f << 'W';}
                if(tas=='b'){f << 'B';}
                if(tas=='W'){f << 'W';}
                if(tas=='B'){f << 'B';}             
            }
            else{
                f << tas;
            }   
        }
        if(hamle3=="h" || hamle3=="H"){
            f.seekg(272-((int2-1)*34));
            if(int2 == 1 || int2==8){
                if(tas=='w'){f << 'W';}
                if(tas=='b'){f << 'B';}
                if(tas=='W'){f << 'W';}
                if(tas=='B'){f << 'B';}
            }
            else{
                f << tas;
            }
        }     
    }
    else{
        cout << "Geçersiz Hamle" << endl;
        string sirakimde;
        f.seekg(0);
        f>>sirakimde;
        if(sirakimde=="B"){
            string beyaz = "W";
            f.seekg(0); 
            f<<beyaz;
        }
        if(sirakimde=="W"){
            string beyaz = "B";
            f.seekg(0); 
            f<<beyaz;
        }
    }
    f.close();
}

void dosyaOku(){
    //Fonksiyon Açıklaması: Her hamleden sonra dosyanın güncel halini ekrana basar.
    fstream f2; 
    f2.open("index.dat", ios::in);
    string dosya;
    while (!f2.eof())
    {
        getline(f2, dosya);
        cout << dosya << "\n";
    }
    f2.close();
}

void skor(){
    //Fonksiyon Açıklaması: Oyunun sonundaki taş sayısına göre kazanma, kaybetme ya da beraberlik durumunu belirten fonksiyon.
    fstream f2; 
    f2.open("index.dat", ios::in);
    string skor, ilk;
    int i;
    int sayac1=0, sayac2=0, sayac3=0, sayac4=0;
    for(i= 0; i<272; i++){
        f2.seekg(i);
        f2>>skor;
        if(skor=="b"){ sayac1++; }
    }
    for(i= 0; i<272; i++){
        f2.seekg(i);
        f2>>skor;
        if(skor=="w"){ sayac2++; }
    }
    for(i= 0; i<272; i++){
        f2.seekg(i);
        f2>>skor;
        if(skor=="B"){ sayac3++; }
    }
    for(i= 0; i<272; i++){
        f2.seekg(i);
        f2>>skor;
        if(skor=="W"){ sayac4++; }
    }
    //Dama olan taş ve sıra W/B ile gösterildiği için oyun sırası kimdeyse (Örneğin: B) ,taş sayısından 1 çıkartılır.
    //Böylelikle taş sayıları doğru hesaplanmış olur.
    f2.seekg(0);
    f2>>ilk;
    if(ilk=="B"){ sayac3=sayac3-1;}
    if(ilk=="W"){ sayac4=sayac4-1;}    
    f2.close();
    int beyazlar=sayac2+sayac4;
    int siyahlar=sayac1+sayac3;
    if(beyazlar==1 && siyahlar==1){
        cout << "Oyun Berabere !!! Lütfen Anamenüye Dönün."<<endl;
    }
    if(siyahlar==0){
        cout << "Kazanan : W !!! Lütfen Anamenüye Dönün."<<endl;
    }
    if(beyazlar==0){
        cout << "Kazanan : B !!! Lütfen Anamenüye Dönün."<<endl;
    }
}

void dosyabastan(){
    //Fonksiyon Açıklaması: Oyuncu "New Game" seçeneği ile oyun başlatıysa dosyayı ilk haline getiren fonksiyon.
    fstream f1; 
    f1.open("index.dat", ios::out | ios::in);
    string st1 = "W";
    string st2 = "8   __|___|___|___|___|___|___|__";
    string st3 = "7   b_|_b_|_b_|_b_|_b_|_b_|_b_|_b";
    string st4 = "6   b_|_b_|_b_|_b_|_b_|_b_|_b_|_b";
    string st5 = "5   __|___|___|___|___|___|___|__";
    string st6 = "4   __|___|___|___|___|___|___|__";
    string st7 = "3   w_|_w_|_w_|_w_|_w_|_w_|_w_|_w";
    string st8 = "2   w_|_w_|_w_|_w_|_w_|_w_|_w_|_w";
    string st9 = "1   __|___|___|___|___|___|___|__";
    string st0 = "    A   B   C   D   E   F   G   H";
        
    f1<<st1<<endl; f1<<st2<<endl; 
    f1<<st3<<endl; f1<<st4<<endl; 
    f1<<st5<<endl; f1<<st6<<endl; 
    f1<<st7<<endl; f1<<st8<<endl; 
    f1<<st9<<endl; f1<<st0<<endl;
    f1.close();
}

void siradegis(){
    //Fonksiyon Açıklaması: Her hamleden sonra sıranın değişmesini sağlar.
    fstream f3; 
    f3.open("index.dat", ios::out | ios::in);
    string sira;
    f3.seekg(0);
    f3>>sira;
    string beyaz = "W";
    string siyah = "B";
    if(sira=="W") { f3.seekg(0); f3<<siyah;}
    if(sira=="B") { f3.seekg(0); f3<<beyaz;}
    f3.close();
}

void anamenu(){
    fstream f6; 
    f6.open("index.dat", ios::out | ios::in);
    fstream f8; 
    f8.open("book.dat", ios::app);
    
    string hamle;
    string hamle1;
    string hamle2;
    string hamle3;
    string hamle4;
    int int1;
    int int2;
    string sirakimde;

    cout<<"DAMA OYNA (PLAY CHECKER) !!!"<<endl;
    cout<<"1-NEW GAME"<<endl;
    cout<<"2-CONTİNUE GAME"<<endl;
    cout<<"3-END GAME"<<endl;
    int secim;
    cout<<"Choose: ";
    cin>>secim;
    if(secim==1){
        dosyabastan();
    }
    if(secim==1){ //book.dat dosyasına yeni oyun yazılır ve oyuncuların hamleleri sonra yazılır.
        f8 << "Yeni Oyun" << endl;
    }
    while(1){
        switch(secim)
        {
            case 1:
                dosyaOku();
                cout<<"Hamlenizi girmek için önce 1'e basın, ana menüye dönmek için ise 2'ye."<<endl;
                cout<<"1-Hamle Yap // 2-Ana Menüye Dön"<<endl;
                int secim2;
                cout<<"Choose: ";
                cin>>secim2;
                switch(secim2)
                {
                    case 1:   
                        skor();
                        //Hamle parçalanır.(En yukarıdaki açıklamada ayrıntılı anlatım yapılmıştır.)          
                        cout << "Hamle (Örnek: a2a3) : ";
                        cin>>hamle;
                        hamle1 = hamle.substr (0,1); 
                        hamle2 = hamle.substr (1,1);
                        int1 = stoi(hamle2);
                        hamle3 = hamle.substr (2,1);
                        hamle4 = hamle.substr (3,1);
                        int2 = stoi(hamle4);
                        //Oyun için gerekli fonksiyonlar sırası ile çağırılır.
                        hamleler(hamle);
                        tasoyna(hamle1, hamle3, int1, int2);
                        siradegis();
                        pespese(hamle1, hamle3, int1, int2);
                       
                    break;
        
                    case 2:
                        anamenu(); 
                    break;  

                    default:
                        anamenu(); 
                    break;
                }
                break;
                
        
            case 2:
                dosyaOku();
                cout<<"Hamlenizi girmek için önce 1'e basın, ana menüye dönmek için ise 2'ye."<<endl;
                cout<<"1-Hamle Yap // 2-Ana Menüye Dön"<<endl;               
                int secim3;
                cout<<"Choose: ";
                cin>>secim3;
                switch(secim3)
                {
                    case 1:
                        skor();
                        //Hamle parçalanır.(En yukarıdaki açıklamada ayrıntılı anlatım yapılmıştır.)
                        cout << "Hamle (Örnek: a2a3) : ";
                        cin>>hamle;
                        hamle1 = hamle.substr (0,1); 
                        hamle2 = hamle.substr (1,1);
                        int1 = stoi(hamle2);
                        hamle3 = hamle.substr (2,1);
                        hamle4 = hamle.substr (3,1);
                        int2 = stoi(hamle4);
                        //Oyun için gerekli fonksiyonlar sırası ile çağırılır.
                        hamleler(hamle);
                        tasoyna(hamle1, hamle3, int1, int2);
                        siradegis();
                        pespese(hamle1, hamle3, int1, int2);                 
                    break;
        
                    case 2:
                        anamenu();
                    break;  

                    default:
                        anamenu(); 
                    break;
                }
                break;

            case 3:
                exit(0);
                break;  
        }
    }
    f8.close();
    f6.close();
}

int main(){
    setlocale(LC_ALL, "Turkish");
    anamenu();
    return 0;
}
