#include <stdio.h>
#include <stdlib.h>

/**
 * Ýkili aðaç yapýsý
 * @author Yunus Emre AK
 */


/**
 * Ýkili aðaç yapýsýnda, daldaki deðerden 
 *		küçük ise soluna
 *		büyük ise saðýna yazýlýr.
 *
 *    		 11
 *   		/  \
 *  	   7    14
 *        / \   / \
 *       3   8  12  18
 *
 */
typedef struct _dal{
	int veri;
	
	_dal* solundaki;
	_dal* sagindaki;
}dal;

// Kullanýcý arayüzünüdeki yazýlarý oluþturan fonksiyon (Anlaþýlabilirlik için.)
void menu();
// Kullanýcý arayüzünü oluþturan fonksiyon (Anlaþýlabilirlik için.)
void loop(dal **);
// Aðacý oluþturmak için kullanýlan fonksiyon.
void create(dal **);
// Bellek ayýrmak için fonksiyon. (Tamamen kolaylýk amaçlýdýr.)
dal* get_leaf();
// Ýkili aðaç yapýsýna veri ekleme fonksiyonu. 
void insert(dal*);
// Aðactaki verileri sýralayýp ekrana yazan fonksiyon (Anlaþýlabilirlik için.)
void sort_disploy(dal*);
// Aðacta veri arama ve verinin bulundaðý dalý geri döndüren fonksiyon.
dal* search(dal*, int);
// Aðacýn dallarý silen fonksiyon.
void destroy_leaf(dal*);
// Aðacý komple silen fonksiyon
void destroy_tree(dal**);


int main(){
	dal *agacim = NULL;	
		
	loop(&agacim);
}

// Fonksiyonlar;
dal* get_leaf(){
	return (dal*)malloc(sizeof(dal));
}

void insert(dal* gelen_dal, int veri){
	// Eðer gelen dal boþ ise, yeni dal oluþturup veriyi atýyoruz.
	if(gelen_dal == NULL){
		printf("\n Agac yapisi mevcut degil. Lutfen once agaci olusturunuz.");
		
		return;
	}
	
	// Öncelikle gelen verinin baslangýç verimizden küçük olma durumunu inceliyoruz.
	if(veri < gelen_dal->veri){
		/**
		 *  Eðer gelen veri, baþ veriden "küçükse" dallarýndaki diðer verileriyle de kýyaslamamýz 
		 * lazým. Bu kýyaslama iþlemi, küçük olma durumunu incelediðimiz için aðacýn 
		 * baþlangýcýnýnýn sol tarafýnda dal olmayana kadar devam etmeli.
		 */
		if(gelen_dal->solundaki != NULL)
			/**
			 *  Eðer dalýn sonundaki null deðilse, tekrardan ekleme fonksiyonunu çaðýrcaðýz.
			 * Bu sayede her alt dal için baþlangýç dalýna uygulamýþ olduðumuz iþlemler
			 * uygulanacak.
			 */
			insert(gelen_dal->solundaki, veri);
		/**
		 *  Eðer dalýn solunda baþka dal yoksa, soluna yeni bir dal uluþturup veriyi atýyacaðýz.
	     *           11
		 *   		/  
	 	 *    (Yeni Dal) 
	 	 *    /       \
	 	 *   NULL      NULL
		 */
		else{
			// Yeni dalýmýz için gelen dalýn soluna dal oluþturuyoruz.
			gelen_dal->solundaki = get_leaf();
			// Gelen dalýn soluna eklenen dala, gelen veriyi atýyoruz.
			gelen_dal->solundaki->veri = veri;
			/**
			 *  Gelen dalýn solunda oluþturulan daldan sonra dal olmadýðý için her yönüne 
			 * de NULL atýyoruz.
			 */
			gelen_dal->solundaki->solundaki = NULL;
			gelen_dal->solundaki->sagindaki = NULL;
		}		
	}	
	
		/**
		 *  Eðer gelen veri, baþ veriden "küçük deðilse" dallarýndaki diðer verileriyle de kýyaslamamýz 
		 * lazým. Bu kýyaslama iþlemi, küçük olma durumunu incelediðimiz için aðacýn 
		 * baþlangýcýnýnýn sað tarafýnda dal olmayana kadar devam etmeli.
		 */
	else{
		if(gelen_dal->sagindaki != NULL)
			/**
			 *  Eðer dalýn sonundaki null deðilse, tekrardan ekleme fonksiyonunu çaðýrcaðýz.
			 * Bu sayede her alt dal için baþlangýç dalýna uygulamýþ olduðumuz iþlemler
			 * uygulanacak.
			 */
			insert(gelen_dal->sagindaki, veri);
			
		/**
		 *  Eðer dalýn saðýnda baþka dal yoksa, saðýnda yeni bir dal uluþturup veriyi atýyacaðýz.
	     *           11
		 *   			\  
	 	 *    		  (Yeni Dal) 
	 	 *    		   /       \
	 	 *   		 NULL      NULL
		 */
		else{
			// Yeni dalýmýz için gelen dalýn saðýna dal oluþturuyoruz.
			gelen_dal->sagindaki = get_leaf();
			// Gelen dalýn saðýna oluþturulan yeni dala veriyi atýyoruz.
			gelen_dal->sagindaki->veri = veri;
			/**
			 *  Gelen dalýn saðýnda oluþturulan daldan sonra dal olmadýðý için her yönüne 
			 * de NULL atýyoruz.
			 */
			gelen_dal->sagindaki->sagindaki = NULL;
			gelen_dal->sagindaki->solundaki = NULL;
		}
	}	 
}

dal *search(dal* gelen_dal, int istenen_veri){
	// Sadece gelen dalda veri olduðu sürece iþlem yapabiliriz.
	if(gelen_dal != NULL){
		// Ýlk olarak istenen veri gelen dalýn verisi olup olmadýðýný kontrol ediyoruz.
		if(gelen_dal->veri == istenen_veri)
			return gelen_dal;
		
		/**
		 *  Eðer istenen veri gelen daldan küçükse;
		 * Ekleme yaparken küçük verileri gelen dalýn soluna eklediðimiz için, bu fonksiyonu
		 * gelen dalýn solundaki dalý parametre vererek tekrar çaðýracaðýz.
		 */
		if(istenen_veri < gelen_dal->veri)
			search(gelen_dal->solundaki, istenen_veri);
			
		/**
		 *  Eðer istenen veri gelen daldan küçük deðilse yani gelen daldan büyük veya dala eþitse;
		 * Ekleme yaparken küçük olmayan verileri gelen dalýn saðýna eklediðimiz için, bu fonksiyonu
		 * gelen dalýn saðýndaki dalý parametre vererek tekrar çaðýracaðýz.
		 */
		else
			search(gelen_dal->sagindaki, istenen_veri);
		
		// Hiçbir koþul gerçekleþmiyorsa, istenen veri dalda mevcut deðil demektir.
	}
	else 
		return NULL;
}

void destroy_leaf(dal *gelen_dal){
/**
* (Agacýn kökü (en üst verisi) gönderilirse, tüm aðacý siler.)
*     		 11                   11
*   		/  \                /     \
*  	   7    14     ->      7        14
*        / \   / \           /  \    /    \
*       3   8  12  18      NULL NULL NULL NULL
* 
* Alttan üste doðru silme iþlemi yapmalýyýz.
*
*/

	// Öncelikle gelen dal boþ (NULL) deðilse iþlem yapýlýr.
	if(gelen_dal != NULL){
		/**
		*  Aðacýn verileri silmeden önce aðacýn dallarýný temizlememiz gerekiyor,
		* aksi halde diðer dallara eriþimimiz kesilecek ve dallar için ayrýlan bellekleri
		* serbest býrakamayacaðýz. Bu sebeple bu fonksiyonu aðacýn hem saðýndaki hem de 
		* solundaki dallarý için tekrar çaðýrmamýz, en sonda aðacýn verisini silmemiz 
		* gerekir.
		*/
		destroy_leaf(gelen_dal->sagindaki);
		destroy_leaf(gelen_dal->solundaki);
		
		
		// Saðýndaki ve solundaki tüm dallar silindikten sonra, aðacýn baþ verisi silinir.
		free(gelen_dal);
		
		
	}
}

void destroy_tree(dal **gelen_agac){
	// Öncelikle gelen dal boþ (NULL) deðilse iþlem yapýlýr.
	if(*gelen_agac != NULL){
		 // Agacin dallarýný sildiriyoruz.
		 destroy_leaf(*gelen_agac);
		 		 
		 // Gelen agacta dal kalmadýðý için agaca NULL atýyoruz.
		 *gelen_agac = NULL;
	}
}

void display_tree(dal *gelen_dal){
	if(gelen_dal != NULL){
		if(gelen_dal->solundaki != NULL)
			printf("| %d", gelen_dal->solundaki->veri);
		if(gelen_dal->sagindaki != NULL)
			printf("| %d", gelen_dal->sagindaki->veri);
	}
}

void sort_display(dal *gelen_dal){
	if(gelen_dal == NULL){
		printf("\nGosterilecek agac yok.");
		
		return;
	}
	
	if(gelen_dal->solundaki != NULL){
		sort_display(gelen_dal->solundaki);
	}
	
	printf("%d-",gelen_dal->veri);
	
	if(gelen_dal->sagindaki != NULL)
		sort_display(gelen_dal->sagindaki);
}

void menu(){
		printf("\n***************************\n");
	// Görsel hizalama için "%30s" 30 karakterlik alana saða dayalý yazdýrdýk.
	printf("->%30s\n"," Agaci olusturmak icin 1'e");
	printf("->%30s\n"," Agaca sayi eklemek icin 2'e");
	printf("->%30s\n"," Agaci gostermek icin 3'e");
	printf("->%30s\n"," Agaci silmek icin 4'e");
	printf("->%30s\n"," Cikmak icin 0'a");
}

void loop(dal **agacim){	
		int x = 5;
		
		while(x !=0){
		
		menu();
		
		/**
		 *  Dipnot : Boþluk %c (" %c") yazýlýrsa, öncesinde basýlan enter'ý veri olarak ("\n") görmez, hatalar engellenir.
	 	 * %d kullanýmý için bir satýr atlatma karakteri algýlama durumu olmaz.	
		 */
		scanf("%d", &x);
		
		switch(x){
			case 1:
				create(agacim);
				
				break;
				
			case 2:
				printf("\nLutfen eklemek istediginiz veriyi giriniz:\t");
				
				int eklenecek_veri;
				
				scanf(" %d",&eklenecek_veri);
				
				insert(*agacim, eklenecek_veri);
				
				break;
			
			case 3:
				printf("Agacin verilerinin siralanmis hali:\n");
				sort_display(*agacim);
				
				break;
			
			case 4:
				printf("\nAgac silindi.\n");
				
				destroy_tree(agacim);
				
				break;
				
			default:
				break;
		}
	}
}

void create(dal **agac){
	if(*agac == NULL)
		*agac =get_leaf();
	
	printf("\nAgacin ilk verisini giriniz:\t");
	
	int bas_veri;
	
	scanf(" %d", &bas_veri);
	
	(*agac)->veri = bas_veri;	
	(*agac)->sagindaki = NULL;
	(*agac)->solundaki = NULL;
	
	printf("\nAgac %d verisiyle olusturuldu.", bas_veri);
}

void print_leaf(dal *gelen_dal){
	if(gelen_dal != NULL){
		if(gelen_dal->solundaki != NULL)
			printf("%d ", gelen_dal->solundaki);
		if(gelen_dal->sagindaki != NULL)
			printf("%d ", gelen_dal->sagindaki);
	}
}

int degree_of_tree(dal **gelen_agac){
	int i = 0;
	
	if(gelen_agac == NULL)
		return i;
	
	if(has_leaf(*gelen_agac))
		i++;
	
	if(has_leaf())
		i++;
}

bool has_leaf(dal *gelen_dal){
	if(gelen_dal->solundaki != NULL || gelen_dal->sagindaki != NULL)
		return true;
	
	return false;
}

void print_tree(dal **gelen_agac){
	printf("%d", *gelen_agac->veri)
	print_leaf(*gelen_agac);
}

