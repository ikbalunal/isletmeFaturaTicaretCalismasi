

#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <ctime> 
#include <clocale>
#include <limits>
#include <sstream>
#include <fstream>
using namespace std;

int main() {


	setlocale(LC_ALL, "TURKISH");

	ofstream fatura; 
	fatura.open("faturaa.txt");
	
	string isim;
	
	      cout << "\tİKBAL BİLİŞİM SERVİSİNE HOŞGELDİNİZ !!!"<< endl;
		  cout << "----------------------------------------------" << endl;
		  cout << "Lütfen adınızı veya Şirketinizin adını giriniz :  " ;
		  getline(cin, isim);
		  cout << "Sayın " << isim << " Aşağıdaki menüden almak istediğiniz hizmeti seçebilirsiniz" << endl;

		  float fiyat = 0, toplam = 0;
		  int secim = 0, aylik = 0;
		  
		  

		  while(true) {       //Menü seçimi, tekrar listeye dönme sorusu döngü içine alındı
			  int soru;

			 

			  cout << "------------------------------------------" << endl;
			  cout << "\tMENU" << endl;
			  cout << "------------------------------------------" << endl;
			  cout << "|      1- Internet ağı bakım, iyileştirme, entegre servisi                (AYLIK)    :  299 TL |" << endl;
			  cout << "|      2- Ağ Güvenliği Hizmeti                                            (AYLIK)    : 1099 TL |" << endl;
			  cout << "|      3- Teknoloji Danışmanlığı                                          (AYLIK)    : 2299 TL |" << endl;
			  cout << "|      4- Web site, Sosyal Medya ve Reklam Yönetim hizmeti                (AYLIK)    : 3499 TL |" << endl;
			  cout << "------------------------------------------" << endl;



			  cout << "Seçiminiz : ";
			  cin >> secim;

			    if (secim ==1){
			 
				  cout << endl << "1. servisi seçtiniz " << endl;				  
				  fiyat = 299;

			    }

			    else if (secim == 2){

				  cout << endl << "2. servisi seçtiniz " << endl;
				  fiyat = 1099;

			    }
  
			    else if (secim == 3) {

				  cout <<  "3. servisi seçtiniz " << endl;
				  fiyat = 2299;
			  
			    }

			    else if (secim == 4) {

				  cout << "4. servisi seçtiniz " << endl;
				  fiyat = 3499;

			    }
		

			  cout << " Bu hizmeti Kaç ay almak istiyorsunuz?" << endl ; 			  
			  cin >> aylik;			  			  
			  toplam = toplam + (fiyat * aylik);
			  cout << "Şuanki borç = " << toplam << endl;
			  

			  cout << "Başka hizmet seçecek misiniz? ( EVET İÇİN  1   ,   hayır için 0 seçiniz ) : " << endl;
			 
			  cin >> soru;

			  if (soru==1) {
			
				 //tekrar
				  system("cls");
			  }
					 
			  else if (soru==0) {

				  cout <<"Alış-verişinizin toplam borcu : "<< toplam << endl;
				  break;

			  }
			 			 
		  }//while parantezi
	      

		     //KDV sorusu
		 
		   cout << "%18 KDV eklensin mi? (EVET İÇİN 1 , hayır için  0 tuşlayınız) " << endl;

		  int kdvsoru;
		  cin >> kdvsoru;
		  
		     if (kdvsoru == 1) {
			     float kdvhali;
			     kdvhali = (toplam * 18) / 100;
			     toplam = kdvhali + toplam; 
			        cout << "KDV li borcunuz = " << toplam<< " TL" << endl; 
		     } 
		     
			 else if (kdvsoru == 0) {

			  cout << "KDV siz ödemeyi seçtiniz" << endl;
		     }
		  
			
			 
			 
			 
			 //Taksit sorusu 
		 cout << "Borcunuzu Taksitlendirmek istiyor musunuz? (EVET için 1, HAYIR için 0) " << endl;

		  int taksitsoru;
		  float taksitmiktarı, taksitliborc;
		  cin >> taksitsoru;

		  if (taksitsoru == 1) {

			 
			      while (true) { // Maks taksit miktarını geçmemesi için döngü
				         cout << "Kaç ay taksitlendirmek istiyorsunuz? (MAX 12 AY)" << endl;
				         cin >> taksitmiktarı;
				 
				        if (taksitmiktarı > 12) {
					       cout << "Maksimum 12 ay taksitlendirme yapabiliyoruz!!!"<< endl;
				        }
				     
					    else {
					       taksitliborc = toplam / taksitmiktarı;
					       break;
				        }
			      }


			      cout << "Aylık ödeme tutarınız =" << taksitliborc << endl << endl;
			      cout << "\tÖDEME ÇİZELGENİZ" << endl << "------------------------------" << endl;

			      int indisay = 1;
			  
			            for (int i = 0; i < taksitmiktarı; i++) {

				            cout << indisay << ". ay =" << taksitliborc << endl;
				            indisay++;

			            }

						
						//Fatura.txt yazdırma
						
						fatura << "Müşteri adı\n" << isim << endl;
						fatura << "Toplam borç tutar = " << toplam<< "TL" << endl;
						fatura << "\n\tÖDEME ÇİZELGESİ" << endl << "-------------------------" << endl;
						for (int a = 0; a < taksitmiktarı; a++) {

							fatura << indisay << ". ay = " << taksitliborc << endl;
							indisay++;

						}
		  }//if taksit
		 
		 
		  else if (taksitsoru == 0) {

			  cout << "\tÖDEME ÇİZELGENİZ" << endl << "-------------------------" <<endl<< toplam << "TL" << endl << endl;

			  // Fatura.txt yazdırma 
			  fatura << "Müşteri adı\n" << isim << endl;
			  fatura << "Toplam borç tutar = " << toplam << "TL"<< endl;
			  fatura << "\n\tÖDEME ÇİZELGESİ" << endl << "-------------------------" << endl << toplam << "TL";
		  }

		  
		  
		  fatura.close();


}