# v.1.0.1

* Degistirilmis hali eklendi.

## Degisenler
* Degisken isimleri, fonksiyon yapisi.

## Not
* **Çıktı ve içerik değişmemiştir.**

# Oku Beni (Konusu) adlı dosyaya bakınız.

**Soru1: (40 Puan)**

Karmaşık sayılar için dört işlemi yapan C++ programını nesneye yönelik programlamaya uygun olarak yazınız.

 Programınız da bir işlem menüsü olmalıdır. 1-Toplama, 2-Çıkarma, 3-Çarpma ve 4- Bölme işlemlerini kullanıcı seçebilmelidir.

 Kullanıcının işlem seçeneğinden sonra kullanıcıdan karmaşık sayının reel ve sanal kısımları alınmalıdır.

 Programın yürütücü kısmından işlem menüsü, ve buna göre karmaşık sayı girilmesi işlemleri sadece \_Yurutucu.cpp içerisinde yapılabilmelidir.

 Programınızı nesneye yönelik programlamaya uygun olarak yazınız, bu şekilde yazılmayan ödevler değerlendirmeye alınmaz.

 Programınızda, \_Karmasik.h, \_Karmasik.cpp ve \_Yurutucu.cpp dosyları bulunmalıdır.

 Programınızda, karmaşık sayı nesneleri Karmasik k1, Karmasik k2 şeklinde oluşturulmalı ve gerekiyorsa dört işlem sonrasını da atanacak karmaşık sayı Karmasik k3 şeklinde tanımlanabilmelidir.

 \_Karmasik.cpp dosyası içerisinde bütün **Get** , **Set** ve **Goster** şeklinde karmaşık sayıyı gösteren methodların gövdeleri olmalıdır.

 Programınızın \_Karmasik.h dosyası içerisinde methodlarınızın imzası ve dışardan erişebilecek **public** , **private** methodları belirtiniz.

 Programdaki yapıcı fonksiyonların tanımlarını şu şekilde ifade ediniz. Karmasik() ve Karmasik(int a, int b), bu iki yapıcıyı da programınızda kullanınız.

 Programınızda **operator overloading** işlemini yapınız. +, -, \* ve / bölme işlemlerini karmaşık sayılar üzerinde işlem yapacak şekilde revize ediniz. Başka bir ifade ile programınız kullanıcıdan oluşturduğunuz karmaşık sayılar üzerinde başka bir methoda gerek duymadan işlem yapabilmelidir. Operator overloading yaparken **friend function** (arkadaş fonksiyon) kullanabilirsiniz.

(Doğru Örnek: k3=k1+k2; k3=k1\*k2) , (Yanlış Örnek: k3=ToplamaIslemi(k1,k2))

 Yukarıda yazılanlara uygun sınıf ve nesne mantığına uygun yazılmayan ödevler değerlendirmeye alınmayacaktır. Tek main ve sınıf ile yapılan ve nesne oluşturulmadan yazılan ödevler değerlendirmeye alınmaz.

Örnek Toplama:

**z1= 3+2i** , **z2=4+3i** ise, z3=z1+z2 işleminin sonucu: **7+5i**

Örnek Çarpma: Çarpma işlemi aşağıdaki gibi bir matematiksel işlem ile gerçekleştirebilir. Benzer şekilde bölme işlemini de siz araştırınız.

(a+b **i** )(c+d **i** ) = (ac−bd) + (ad+bc) **i**

Örnek: **z1=1+4i** , **z2=5+i** ise, z3=z1\*z2 işleminin sonucu: **1+21i**


**Soru2: (60 Puan)**

Bu ödevde C++ programlama ile dosyadan verilerin okunması, STL kullanarak Vector, List vb. içerisine ya da pointer yardımıyla kendinizin oluşturacağınız bir dinamik liste yapısına bir dosya elamanlarının eklenmesi ve üzerinde işlem yapılması istenmektedir.

 Ödevde STL (Vector, List) kullanımı ya da pointer ile dinamik bir liste oluşturulması istenmektedir. Sabit boyutlu dizi ile yapılan ödevler **kabul edilmeyecektir**.

 Ödev de **Struct** ile kendi veri türümüzü tanımlayıp, dinamik yapılar içerisinde bu veri tipini saklayacağız.

 Bu ödev için, kurduğunuz dinamik yapı içerisinde öğrenci verileri; ÖğrenciId, Ad, Soyad, Sınav1, Sınav2, Sınav3, Toplam Skor ve Harf Notu tutulabilmedir.

 Verilen girdi dosyasına göre verileri okuyunuz.

 Okunan verilere göre Toplam skorunu ve Harf Notunu hesaplayınız.

 Toplam skora göre verilen aşağıdaki aralığa göre Harf Notu oluşturunuz.

270 ya da daha fazlası A

240&#39;dan 269&#39;e kadar B

210&#39;dan 239&#39;a kadar C

180&#39;den 209&#39;a kadar D

179 ya da daha aşağısı ise F

 Toplam skora göre verileri sıralayınız (hazır sıralama algoritması kullanmayınız).

 En düşük not, En yüksek not, Ortalama ve Standart sapmayı bulunuz.

**Girdi Dosya:**

1234 Ferhat Bozkurt 82 86 80

9138 Faruk Günay 90 98 94

3124 Ceylin Özer 87 84 82

4532 Ali Adanalı 56 89 78

5678 Ayşe Paluli 90 87 65

6134 Sinan Öztürk 29 65 33

7874 Mikail Gürer 91 92 92

8026 Melisa Donat 74 75 89

9893 Galip Yuka 69 66 68


