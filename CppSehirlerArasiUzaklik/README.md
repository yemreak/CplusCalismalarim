
ÖDEV-3

Arş.Gör. Şeyma Yücel Altay (Teslim Tarihi: 31.05.2018)

Bu ödevde, C++ ile Türkiye’deki şehirlerarası mesafenin km bazında listelenmesi, arama yapılabilmesine yönelik uygulama istenmektedir.
•	Ödev,  dosyada bulunan boyutu belli olmayan şehir dosyasına göre, şehirlerin birbiri ile olan uzaklık mesafelerini göstermek için kullanılacaktır.
•	Ekler kısmında verilen dosya formatına göre “Sehirler.dat” dosyasını girdi kullanarak ilgili şehirlerin sistem yüklenmesi gerçekleştirilecektir. (Aşağıdaki girdi dosyası haricinde dosya kullanmayınız değerlendirme aşağıdaki dosyaya göre yapılacaktır)
•	Bu ödev Nesneye Yön. Programlamaya uygun olarak sınıf (class), nesne (object) kullanılarak yapılacaktır. Tek dosya ile main.cpp içerisinde işlemler gerçekleştirilmeyecektir. Dolayısıyla ödeviniz parçalı dosyalar; “Sehir.h”, “Sehir.cpp” ve “Main.cpp” ler içerecek şekilde yazılmalıdır. 
•	Program ana çalışma dosyası Main içerisinde argüman satırından çalışma anında girdi ve çıktı dosyalarının isimlerini alarak çalışmalıdır. 
•	Bu ödev için STL (Standart Şablon Kütüphanesi) Vektor, map yapıları kullanılacaktır.
•	Şehirler string karakter katarı içeren bir vektörden oluşmalıdır.
•	Mesafeler integer tipinde iki boyutlu vektör olarak ele alınacaktır.
•	Vektör kullanıldığı için sabit boyutlu bir tanımlama yapılmamalıdır.
•	Yazacağınız tüm public ve private fonksiyonlar (methodlar) sadece “Sehir.cpp” içinde olmalıdır. Header imza dosyasında gerekli private ve public methodlar belirtilmelidir. Sehir.cpp, header dosyasını include etmelidir. Main içerisinden sadece dışardan erişilecek public fonksiyonlar çağrılmalıdır.   
•	Ödevde oluşturulacak .exe ye parametre olarak girdi dosyası “Sehirler.dat” ve “Sonuclar” yazdığımızda girdi dosyasına göre çıktı dosyası oluşmalıdır.
•	Program aşağıdaki Örnek Dosyaya göre çalışacaktır.  Bu  “Sehirler.dat”  dosyasının ilk satırında örneğin “Eskisehir” iline en yakın 500 km sınır içerisinde kalan şehirler getirilecektir. İkinci satırda  “Erzurum-Izmir” arası mesafe ve üçüncü satırdan itibaren ise sisteme doldurulacak şehirler ve mesafeler bilgileri bulunmaktadır (Elle şehir-mesafe bilgileri kullanıcıdan alınarak doldurulmayacaktır, dosyadan okunup vektörler doldurulacaktır.) 
•	Bütün şehir adları ve mesafeleri ilgili vektörlere doldurulduktan sonra, “Sonuclar.dat” dosyasına şu bilgiler yazdırılacaktır.
o	“Eskisehir” iline en yakın 500 km sınır içerisinde kalan şehirlerin listesi
o	“Erzurum-Izmir” arası mesafenin ne kadar olduğu
o	  Birbirine 1400 km’den daha uzak olan illerin listesi (Örneğin Erzurum-İzmir listeye sadece 1 kez eklenmelidir. Yani Erzurum-İzmir eklendikten sonra İzmir-Erzurum listede olmamalıdır.)
•	Bununla ilgili çıktı aşağıda verilmiştir.
•	Ödev değerlendirilirken Dev-C++ ile değerlendirilecektir. Okunacak olan “Sehirler.dat” dosyası aşağıdaki içeriğe uygun olarak projenizin olduğu klasörün içerisinde yer almalıdır. Proje derlendiğinde “Sonuclar.dat” dosyası yine aynı klasörde oluşturulmalıdır. Değerlendirme “Sonuclar.dat” dosyasının içeriğine göre yapılacaktır.
•	 Zamanında iletilmeyen ödevler için itiraz hakkınız bulunmamaktadır. Klasör içerinde .exe uzantılı dosya olmamalıdır, aksi takdirde mail iletilmeyebilir. Bu durumdan öğrencinin kendisi mesul tutulacaktır.

Sehirler.dat (Dosya Formatı)
İlk satır: Yazılan ile en yakın iller 
İkinci Satır: Yazılan iki şehir arası mesafe:
Üçüncü Satırdan itibaren şehirler ve mesafeleri
SehirAdi#km1 km2 km3 km4 km5 km6 km7 km8 km9 km10

Örnek dosya: Bu örnek dosyada alltaki verileri txt dosya içine koyarak kaydedip, dosya adını Sehirler, dosya uzatısını .dat olarak değiştiriniz)

Sehirler.dat
Eskisehir
Erzurum-Izmir
Adana#0 618 844 658 946 896 1048 347 888 443
Antalya#618 0 1238 415 694 454 1440 302 1497 676
Erzurum#844 1238 0 1116 1234 1467 204 932 379 661
Eskisehir#658 415 1116 0 322 412 1318 339 1436 456
Istanbul#946 694 1234 322 0 471 1436 711 1661 661
Izmir#896 454 1467 412 471 0 1671 557 1775 809
Kars#1048 1440 204 1318 1436 1671 0 1134 360 862
Konya#347 302 932 339 711 557 1134 0 1224 367
Van#888 1497 379 1436 1661 1775 360 1224 0 1014
Yozgat#443 676 661 456 661 809 862 367 1014 0	Sonuclar.dat (Çıktı)

Eskisehir iline 500 km sınır içinde en yakın iller:
Antalya
Istanbul
Izmir
Konya
Yozgat

Erzurum-İzmir arası mesafe:
1467km

Birbirine 1400 km den daha uzak olan iller:

Antalya-Kars
Antalya-Van
Erzurum-İzmir
Eskisehir-Van
İstanbul-Kars
İstanbul-Van
İzmir-Kars
İzmir-Van


Şehirlerarası mesafeler Tablosu
 	Adana	Antalya	Erzurum	Eskisehir	Istanbul	Izmir	Kars	Konya	Van	Yozgat
Adana	0	618	844	658	946	896	1048	347	888	443
Antalya	618	0	1238	415	694	454	1440	302	1497	676
Erzurum	844	1238	0	1116	1234	1467	204	932	379	661
Eskisehir	658	415	1116	0	322	412	1318	339	1436	456
Istanbul	946	694	1234	322	0	471	1436	711	1661	661
Izmir	896	454	1467	412	471	0	1671	557	1775	809
Kars	1048	1440	204	1318	1436	1671	0	1134	360	862
Konya	347	302	932	339	711	557	1134	0	1224	367
Van	888	1497	379	1436	1661	1775	360	1224	0	1014
Yozgat	443	676	661	456	661	809	862	367	1014	0
Örneğin: bu tabloya göre Erzurum- İzmir arası: 1467 km’dir.



